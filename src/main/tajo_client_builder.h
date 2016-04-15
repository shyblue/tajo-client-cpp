#pragma once

#include <string>
#include "tajo_client.h"

class TajoClientBuilder {
	using client_t = TajoClient;
	using self_t = TajoClientBuilder;
 public:
    // required
    self_t& master_server_addr(const std::string &addrs);

    // optional and default port is 26002
    self_t& master_server_port(const int port);

    // optional and default value is the username of operating system
    self_t& username(const std::string &username);

    // optional and default value is 15 secs
    self_t& connect_timeout(const long sec);

    // optional and default value is 180 secs
    self_t& socket_timeout(const long sec);

    // Adding multiple key-value properties is allowed
    self_t& add_property(const std::string &key, const std::string &val);

    // Return TajoClient instance
    client_t& build();

private:
	std::map<std::string, std::string> property_;
};
