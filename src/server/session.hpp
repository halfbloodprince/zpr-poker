#ifndef POKER_SERVER_SESSION_H
#define POKER_SERVER_SESSION_H

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <string>

#include "server/request_handler.hpp"

using boost::asio::ip::tcp;

/// @brief Represent one connection with client
class Session
{
public:
	/// @brief Create new session
	Session(boost::asio::io_service& io_service, RequestHandler *handler);

	/// @brief Start receiving client's requests
	void start();
	
	/// @brief Send given data to client
	void send(const Request &req);

	/// @brief Set reuqest handler 
	/// @param[in] 
	void setHandler(RequestHandler *handler);

protected:
	/// @brief Proceed with received data
	/// @details Data buffer is converted into request object and sent to
	/// handler.
	virtual void handle_read(const boost::system::error_code& error,
		size_t bytes_transferred);

	/// @brief Proceed after data was sent to client
	virtual void handle_write(const boost::system::error_code& error);

	static const short buffer_length = 1024;
	tcp::socket socket_;
	char data_[buffer_length];
	RequestHandler *handler_;
};

#endif
