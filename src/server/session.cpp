#include "session.hpp"

#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

Session::Session(boost::asio::io_service& io_service)
	: socket_(io_service)
{
}

void Session::start()
{
	socket_.async_read_some(boost::asio::buffer(data_, buffer_length),
		boost::bind(&Session::handle_read, this,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));
}

tcp::socket& Session::socket()
{
	return socket_;
}

void Session::handle_read(const boost::system::error_code& error,
	size_t bytes_transferred)
{
	if (!error)
	{
		std::string response = "Bytes received: ";
		response.append(boost::lexical_cast<std::string>(bytes_transferred));
		response.append("\n");

		std::cout << response;

		boost::asio::async_write(socket_,
			boost::asio::buffer(response),
			boost::bind(&Session::handle_write, this,
			boost::asio::placeholders::error));
	}
	else
	{
		delete this;
	}
}

void Session::handle_write(const boost::system::error_code& error)
{
	if (!error)
	{
		socket_.async_read_some(boost::asio::buffer(data_, buffer_length),
			boost::bind(&Session::handle_read, this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
	}
	else
	{
		delete this;
	}
}