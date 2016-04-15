#include "tajo_async_client.h"


TajoAsyncClient::TajoAsyncClient(boost::asio::io_service &ioService)
    : pImpl_(std::make_shared<TajoClientImpl>(std::ref(ioService)))
{
    pImpl_->errorHandler_ = std::bind(&TajoClientImpl::defaulErrorHandler,pImpl_, _1);
}

TajoAsyncClient::~TajoAsyncClient()
{
    pImpl_->close();
}

void TajoAsyncClient::connect(const boost::asio::ip::address &address,
                               unsigned short port,
                               const std::function<void(bool, const std::string &)> &handler)
{
    boost::asio::ip::tcp::endpoint endpoint(address, port);
    connect(endpoint, handler);
}

void TajoAsyncClient::connect(const boost::asio::ip::tcp::endpoint &endpoint,
                               const std::function<void(bool, const std::string &)> &handler)
{
    pImpl_->socket_.async_connect(endpoint, std::bind(&TajoClientImpl::handleAsyncConnect,
                                                      pImpl_, _1, handler));
}


void TajoAsyncClient::installErrorHandler(
        const std::function<void(const std::string &)> &handler)
{
    pImpl_->errorHandler_ = handler;
}