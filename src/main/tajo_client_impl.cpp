#include <boost/asio/write.hpp>
#include <boost/lexical_cast.hpp>

#include <functional>
#include <algorithm>
#include <iostream>

#include "tajo_client_impl.h"

const size_t HEADER_SIZE = 4;
TajoClientImpl::TajoClientImpl(boost::asio::io_service &ioService)
	: state_(TajoClientState::NOTCONNECTED), strand_(ioService), socket_(ioService), subscribeSeq_(0)
{
}

TajoClientImpl::~TajoClientImpl()
{
    close();
}

void TajoClientImpl::close()
{
    if( state_ != TajoClientState::CLOSED)
    {
        boost::system::error_code ignored_ec;

        errorHandler_ = std::bind(&TajoClientImpl::ignoreErrorHandler, _1);
        socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
        state_ = TajoClientState::CLOSED;
    }
}


void TajoClientImpl::processMessage()
{
    using boost::system::error_code;

    socket_.async_read_some(boost::asio::buffer(buf_),
                           std::bind(&TajoClientImpl::asyncRead,
                                       shared_from_this(), _1, _2));
}

void TajoClientImpl::doProcessMessage(const TajoValue &v)
{
    if( state_ == TajoClientState::SUBSCRIBED)
    {
        std::vector<TajoValue> result = v.toArray();

        if( result.size() == 3 )
        {
            const TajoValue &command = result[0];
            const TajoValue &queueName = result[1];
            const TajoValue &value = result[2];

            const std::string &cmd = command.toString();

            if( cmd == "message" )
            {
                SingleShotHandlersMap::iterator it = singleShotMsgHandlers.find(queueName.toString());
                if( it != singleShotMsgHandlers.end() )
                {
                    strand_.post(std::bind(it->second, value.toByteArray()));
                    singleShotMsgHandlers.erase(it);
                }

                std::pair<MsgHandlersMap::iterator, MsgHandlersMap::iterator> pair =
                        msgHandlers.equal_range(queueName.toString());
                for(MsgHandlersMap::iterator handlerIt = pair.first;
                    handlerIt != pair.second; ++handlerIt)
                {
                    strand_.post(std::bind(handlerIt->second.second, value.toByteArray()));
                }
            }
            else if( cmd == "subscribe" && handlers.empty() == false )
            {
                handlers.front()(v);
                handlers.pop();
            }
            else if(cmd == "unsubscribe" && handlers.empty() == false )
            {
                handlers.front()(v);
                handlers.pop();
            }
            else
            {
                std::stringstream ss;

                ss << "[tajoClient] invalid command: "
                   << command.toString();

                errorHandler_(ss.str());
                return;
            }
        }
        else
        {
            errorHandler_("[tajoClient] Protocol error");
            return;
        }
    }
    else
    {
        if( handlers.empty() == false )
        {
            handlers.front()(v);
            handlers.pop();
        }
        else
        {
            std::stringstream ss;

            ss << "[TajoClient] unexpected message: "
               <<  v.inspect();

            errorHandler_(ss.str());
            return;
        }
    }
}

void TajoClientImpl::asyncWrite(const boost::system::error_code &ec, const size_t)
{
    if( ec )
    {
        errorHandler_(ec.message());
        return;
    }

    assert(queue_.empty() == false);
    queue_.pop();

    if( queue_.empty() == false )
    {
        const QueueItem &item = queue_.front();
        
        boost::asio::async_write(socket_,
                                 boost::asio::buffer(item.buff->data(), item.buff->size()),
                                 std::bind(&TajoClientImpl::asyncWrite, shared_from_this(), _1, _2));
    }
}

void TajoClientImpl::handleAsyncConnect(const boost::system::error_code &ec,
                                         const std::function<void(bool, const std::string &)> &handler)
{
    if( !ec )
    {
        socket_.set_option(boost::asio::ip::tcp::no_delay(true));
        state_ = TajoClientState::CONNECTED;
        handler(true, std::string());
        processMessage();
    }
    else
    {
        handler(false, ec.message());
    }
}

std::vector<RpcRequest> TajoClientImpl::makeCommand(const std::vector<TajoBuffer> &items)
{
	std::vector<RpcRequest> result;

	int id = 0;
	for (const auto& item : items)
	{
		RpcRequest req;

		req.set_id(++id);
		req.set_request_message(item.data());


		result.push_back(req);
	}
    return result;
}

void TajoClientImpl::EncodeHeader(std::ostream& stream, int size) {
	uint8_t buf[HEADER_SIZE];
	buf[0] = static_cast<uint8_t>((size >> 24) & 0xFF);
	buf[1] = static_cast<uint8_t>((size >> 16) & 0xFF);
	buf[2] = static_cast<uint8_t>((size >> 8) & 0xFF);
	buf[3] = static_cast<uint8_t>(size & 0xFF);
	stream.write(reinterpret_cast<const char*>(buf), HEADER_SIZE);
}

int TajoClientImpl::DecodeHeader(const char* buf) {
	int size = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];

	return size;
}

std::pair<int,TajoValue> TajoClientImpl::doSyncCommand(const std::string& method_name, const TajoBuffer& cmd)
{
    boost::system::error_code ec;

	RpcRequest req;
	req.set_id(GetSequence());
	req.set_method_name(method_name);
	req.set_request_message(cmd.data(),cmd.size());

	req.ByteSize();

	boost::asio::streambuf buffer;
	buffer.prepare(HEADER_SIZE + req.ByteSize());
	std::ostream req_stream(&buffer);

	EncodeHeader(req_stream, req.ByteSize());
	req.SerializeToOstream(&req_stream);

	boost::asio::write(socket_, boost::asio::buffer(boost::asio::buffer_cast<const char*>(buffer.data()), buffer.size()), boost::asio::transfer_all(), ec);

    if( ec )
    {
        errorHandler_(ec.message());
        return std::make_pair(-1,TajoValue());
    }
    else
    {
		boost::array<char, 4096> inbuff{};

		size_t read_size = 0;
		size_t body_size = 0;
        for(;;)
        {
            read_size += socket_.read_some(boost::asio::buffer(inbuff));
			if (read_size < HEADER_SIZE) continue;
			
			if (body_size == 0) body_size = DecodeHeader(inbuff.data());
			if( read_size < body_size + HEADER_SIZE) continue;
			else break;
			            
        }

		RpcResponse res;
		res.ParseFromArray(inbuff.data() + HEADER_SIZE, body_size);

		TajoValue v(res.response_message());

		return std::make_pair(res.id(), v);

    }
}

void TajoClientImpl::doAsyncCommand(const std::string method_name,
	const std::vector<char> &buff,
	const std::function<void(const TajoValue &)> &handler)
{
    QueueItem item;

    item.buff.reset( new std::vector<char>(buff) );
    item.handler = handler;
    queue_.push(item);

    handlers.push( item.handler );

    if( queue_.size() == 1 )
    {
        boost::asio::async_write(socket_, 
                                 boost::asio::buffer(item.buff->data(), item.buff->size()),
                                 std::bind(&TajoClientImpl::asyncWrite, shared_from_this(), _1, _2));
    }
}

void TajoClientImpl::asyncRead(const boost::system::error_code &ec, const size_t size)
{
    if( ec || size == 0 )
    {
        errorHandler_(ec.message());
        return;
    }

    for(size_t pos = 0; pos < size;)
    {
        auto result = tajoParser_.parse(buf_.data() + pos, size - pos);

        if( result.second == TajoParser::Completed )
        {
            doProcessMessage(tajoParser_.result());
        }
        else if( result.second == TajoParser::Incompleted )
        {
            processMessage();
            return;
        }
        else
        {
            errorHandler_("[tajoClient] Parser error");
            return;
        }

        pos += result.first;
    }

    processMessage();

}

void TajoClientImpl::onClientError(const TajoValue &v)
{
    std::string message = v.toString();
    errorHandler_(message);
}


void TajoClientImpl::defaulErrorHandler(const std::string &s)
{
    throw std::runtime_error(s);
}

void TajoClientImpl::ignoreErrorHandler(const std::string &)
{
    // empty
}

void TajoClientImpl::append(std::vector<char> &vec, const TajoBuffer &buf)
{
    vec.insert(vec.end(), buf.data(), buf.data() + buf.size());
}

void TajoClientImpl::append(std::vector<char> &vec, const std::string &s)
{
    vec.insert(vec.end(), s.begin(), s.end());
}

void TajoClientImpl::append(std::vector<char> &vec, const char *s)
{
    vec.insert(vec.end(), s, s + strlen(s));
}

void TajoClientImpl::append(std::vector<char> &vec, char c)
{
    vec.resize(vec.size() + 1);
    vec[vec.size() - 1] = c;
}