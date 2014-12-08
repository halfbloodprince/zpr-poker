#ifndef POKER_SERVER_SESSION_H
#define POKER_SERVER_SESSION_H

#include <boost/bind.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Session
{
public:
	Session(boost::asio::io_service& io_service);
	void start();
	tcp::socket& socket();

private:
	void handle_read(const boost::system::error_code& error,
		size_t bytes_transferred);
	void handle_write(const boost::system::error_code& error);

	static const short buffer_length = 1024;
	tcp::socket socket_;
	char data_[buffer_length];
};

#endif