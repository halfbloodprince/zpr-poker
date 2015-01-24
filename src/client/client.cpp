#include "client/client.hpp"

#include <boost/bind.hpp>
#include <iostream>

Client::Client(boost::asio::io_service &io_service, std::string &ip, int port)
	: io_service_(io_service),
	  socket_(io_service),
	  endpoint_(boost::asio::ip::address::from_string(ip), port)
{
	boost::asio::ip::tcp::resolver resolver(io_service);
	boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(endpoint_);

	boost::asio::async_connect(socket_, it,
		boost::bind(&Client::handle_connect, this,
		boost::asio::placeholders::error));
}

void Client::write(std::string &req) {
	boost::asio::async_write(socket_, boost::asio::buffer(req),
		boost::bind(&Client::handle_write, this,
		boost::asio::placeholders::error));
}

void Client::read_more()
{
	socket_.async_read_some(boost::asio::buffer(buffer_, buffer_size_),
		boost::bind(&Client::handle_read, this,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));
}

void Client::handle_connect(const boost::system::error_code &e)
{
	read_more();
}

void Client::handle_read(const boost::system::error_code &e, std::size_t len)
{
	std::cout << buffer_ << std::endl;
	read_more();
}

void Client::handle_write(const boost::system::error_code &e)
{
}
