#include <functional>

#include "tajo_sync_client.h"

TajoSyncClient::TajoSyncClient(boost::asio::io_service &ioService)
    : pImpl_(std::make_shared<TajoClientImpl>(std::ref(ioService)))
{
    pImpl_->errorHandler_ = std::bind(&TajoClientImpl::defaulErrorHandler,
                                      pImpl_, _1);
}

TajoSyncClient::~TajoSyncClient()
{
    pImpl_->close();
}

bool TajoSyncClient::connect(const tcp::endpoint &endpoint,
        std::string &errmsg)
{
    boost::system::error_code ec;

    pImpl_->socket_.open(endpoint.protocol(), ec);

    if( !ec )
    {
        pImpl_->socket_.set_option(tcp::no_delay(true), ec);

        if( !ec )
        {
            pImpl_->socket_.connect(endpoint, ec);
        }
    }

    if( !ec )
    {
		pImpl_->state_ = TajoClientState::CONNECTED;
        return true;
    }
    else
    {
        errmsg = ec.message();
        return false;
    }
}

bool TajoSyncClient::connect(const boost::asio::ip::address &address,
        unsigned short port,
        std::string &errmsg)
{
    tcp::endpoint endpoint(address, port);

    return connect(endpoint, errmsg);
}

void TajoSyncClient::installErrorHandler(const std::function<void(const std::string &)> &handler)
{
    pImpl_->errorHandler_ = handler;
}

bool TajoSyncClient::stateValid() const
{
	if (pImpl_->state_ != TajoClientState::CONNECTED)
	{
		std::stringstream ss;

		ss << "tajoClient::command called with invalid state "
			<< static_cast<int>(pImpl_->state_);

		pImpl_->errorHandler_(ss.str());
		return false;
	}

	return true;
}
