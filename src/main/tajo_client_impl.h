#pragma once

#include <boost/array.hpp>
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>

#include <memory>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <array>
#include <atomic>
#include <ostream>

#include "tajo_status.h"
#include "tajo_parser.h"
#include "tajo_buffer.h"

#include "RpcProtos.pb.h"
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>

using namespace std::placeholders;

class TajoClientImpl : public std::enable_shared_from_this<TajoClientImpl> {
public:
     TajoClientImpl(boost::asio::io_service &ioService);
     ~TajoClientImpl();

     void handleAsyncConnect(
            const boost::system::error_code &ec,
            const std::function<void(bool, const std::string &)> &handler);

     void close();

     std::vector<RpcRequest> makeCommand(const std::vector<TajoBuffer> &items);

	 std::pair<int, TajoValue> doSyncCommand(const std::string& method_name,const TajoBuffer& cmd);

	 void TajoClientImpl::EncodeHeader(std::ostream& stream, int size);
	 int TajoClientImpl::DecodeHeader(const char* buf);

     void doAsyncCommand(
			const std::string method_name,
            const std::vector<char> &buff,
            const std::function<void(const TajoValue &)> &handler);

     void sendNextCommand();
     void processMessage();
     void doProcessMessage(const TajoValue &v);
     void asyncWrite(const boost::system::error_code &ec, const size_t);
     void asyncRead(const boost::system::error_code &ec, const size_t);

     void onClientError(const TajoValue &);
     void defaulErrorHandler(const std::string &s);
     static void ignoreErrorHandler(const std::string &s);

     static void append(std::vector<char> &vec, const TajoBuffer &buf);
     static void append(std::vector<char> &vec, const std::string &s);
     static void append(std::vector<char> &vec, const char *s);
     static void append(std::vector<char> &vec, char c);
    template<size_t size>
    static inline void append(std::vector<char> &vec, const char (&s)[size]);

    template<typename Handler>
    inline void post(const Handler &handler);

	TajoClientState state_;
    boost::asio::strand strand_;
    boost::asio::ip::tcp::socket socket_;
    TajoParser tajoParser_;
    std::array<char, 4096> buf_;
    size_t subscribeSeq_;
	static std::atomic<int32_t> sequence_;

	inline int32_t GetSequence() { sequence_.fetch_add(1); return sequence_.load(); }

    typedef std::pair<size_t, std::function<void(const std::vector<char> &buf_)> > MsgHandlerType;
    typedef std::function<void(const std::vector<char> &buf_)> SingleShotHandlerType;

    typedef std::multimap<std::string, MsgHandlerType> MsgHandlersMap;
    typedef std::multimap<std::string, SingleShotHandlerType> SingleShotHandlersMap;

    std::queue<std::function<void(const TajoValue &v)> > handlers;
    MsgHandlersMap msgHandlers;
    SingleShotHandlersMap singleShotMsgHandlers;

    struct QueueItem {
        std::function<void(const TajoValue &)> handler;
        std::shared_ptr<std::vector<char> > buff;
    };

    std::queue<QueueItem> queue_;

    std::function<void(const std::string &)> errorHandler_;
};

template<size_t size>
void TajoClientImpl::append(std::vector<char> &vec, const char (&s)[size])
{
    vec.insert(vec.end(), s, s + size);
}

template<typename Handler>
inline void TajoClientImpl::post(const Handler &handler)
{
    strand_.post(handler);
}