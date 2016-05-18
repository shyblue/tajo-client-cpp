#include "tajo_client_builder.h"


TajoClientBuilder::TajoClientBuilder() : property_(), io_service_(), client_(io_service_)
{

}

TajoClientBuilder::client_t& TajoClientBuilder::build()
{
	if (property_.empty()) return client_;

	auto& addr = property_["MASTER_SERVER_ADDR"];
	std::string& port = property_["MASTER_SERVER_PORT"];
	std::string& user = property_["USER_NAME"];

	if (user.empty()) user = "tajo";
	if (addr.empty()) addr = "localhost";
	if (port.empty()) port = "26002";

	boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::from_string(addr), static_cast<USHORT>(stol(port)));

	std::string err;
	client_.connect(ep, err);

	return client_;
}

