#ifndef POKER_SERVER_SESSION_H
#define POKER_SERVER_SESSION_H

#include <boost/bind.hpp>
#include <boost/asio.hpp>

#include "common/requests/request_handler.hpp"

using boost::asio::ip::tcp;

/// @brief Represent one connection with client
class Session
{
public:
	/// @brief Create new session
	Session(boost::asio::io_service& io_service, requests::RequestHandler *handler);

	/// @brief Start receiving client's requests
	void start();
	
	/// @brief Send given data to client
	void send(std::string &req);

	/// @brief Set reuqest handler 
	/// @param[in] 
	void setHandler(requests::RequestHandler *handler);

	/// @brief Sets id
	void setId(int id);

	/// @brief Gets id
	int id();

	/// @brief Get access to session's socket
	tcp::socket &socket();

protected:
	/// @brief Proceed with received data
	/// @details Data buffer is converted into request object and sent to
	/// handler.
	virtual void handle_read(const boost::system::error_code& error,
		size_t bytes_transferred);

	/// @brief Proceed after data was sent to client
	virtual void handle_write(const boost::system::error_code& error);

	tcp::socket socket_;
	requests::RequestHandler *handler_;
	static const short buffer_length = 1024;
	char data_[buffer_length];

	/// id of this session
	int id_;
};

#endif
