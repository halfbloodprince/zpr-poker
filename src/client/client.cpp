#include "client/client.hpp"

#include <boost/bind.hpp>
#include <iostream>

Client::Client(boost::asio::io_service &io_service, std::string &ip, int port)
	: io_service_(io_service),
	  socket_(io_service),
	  endpoint_(boost::asio::ip::address::from_string(ip), port)
{
	std::cout << "connecting!\n";
	boost::asio::ip::tcp::resolver resolver(io_service);
	boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(endpoint_);

	boost::asio::async_connect(socket_, it,
		boost::bind(&Client::handle_connect, this,
		boost::asio::placeholders::error));
}

void Client::write(std::string &req) {
	std::cout << "writting!\n";
	boost::asio::async_write(socket_, boost::asio::buffer(req),
		boost::bind(&Client::handle_write, this,
		boost::asio::placeholders::error));
}

void Client::handle_connect(const boost::system::error_code &e)
{
}
void Client::handle_read(const boost::system::error_code &e)
{
}

void Client::handle_write(const boost::system::error_code &e)
{
}
