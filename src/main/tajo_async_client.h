#pragma once

#include <boost/asio.hpp>
#include <boost/noncopyable.hpp>

#include <functional>
#include <string>
#include <list>

#include "tajo_result.h"
#include "tajo_client_impl.h"

using namespace std::placeholders;
class TajoAsyncClient :  boost::noncopyable
{
public:

     TajoAsyncClient(boost::asio::io_service &ioService);
     ~TajoAsyncClient();

    // Connect to tajo server
     void connect(
            const boost::asio::ip::address &address,
            unsigned short port,
            const std::function<void(bool, const std::string &)> &handler);

    // Connect to tajo server
     void connect(
            const boost::asio::ip::tcp::endpoint &endpoint,
            const std::function<void(bool, const std::string &)> &handler);

    // backward compatibility
    inline void asyncConnect(
            const boost::asio::ip::address &address,
            unsigned short port,
            const std::function<void(bool, const std::string &)> &handler)
    {
        connect(address, port, handler);
    }

    // backward compatibility
    inline void asyncConnect(
            const boost::asio::ip::tcp::endpoint &endpoint,
            const std::function<void(bool, const std::string &)> &handler)
    {
        connect(endpoint, handler);
    }

    // Set custom error handler. 
     void installErrorHandler(const std::function<void(const std::string &)> &handler);

     static void dummyHandler(const TajoValue &) {}

	 bool is_connected() const;
	 std::string &master_server_addr() const;
	 int master_server_port() const;
	 std::string &username() const;

	 // seconds
	 long connect_timeout() const;

	 // seconds
	 long socket_timeout() const;

	 // return a property value corresponding to a given key
	 std::string& property(const std::string &key) const;

	 // session id will be given once the connection is established
	 std::string& session_id() const;

	 TajoStatus SelectDatabase(const std::string &dbname);

	 TajoStatus CurrentDatabase(std::string *dbname);

	 // for just update query without result
	 TajoStatus ExecuteUpdate(const std::string &sql);

	 TajoStatus ExecuteQuery(const std::string &sql, ResultBatch *batch);

	 TajoStatus ExecuteQueryAsync(const std::string &sql,
		 std::function<void(const TajoQueryState &state,
		 ResultBatch *batch)> callback);

	 // List only those tables whose names pass a substring match on 'filter'.
	 //
	 // 'tables' is appended to only on success.
	 TajoStatus ListTables(std::vector<std::string>& tables,
		 const std::string &filter = "");

	 // List only those session variables whose names pass a substring match on 'filter'.
	 //
	 // 'vars' is appended to only on success.
	 TajoStatus ListSessionVars(
		 std::vector<std::pair<std::string, std::string>>& vars,
		 const std::string &filter = "");

protected:
	bool stateValid() const;

private:
    std::shared_ptr<TajoClientImpl> pImpl_;
};
