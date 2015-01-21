#include "server/session.hpp"

#include <iostream>
#include <string>

#include "common/requests/request_factory.hpp"

Session::Session(boost::asio::io_service& io_service, requests::RequestHandler *handler)
	: socket_(io_service)
	, handler_(handler)
{
}

void Session::start()
{
	requests::Welcome welcome;
	welcome.setId(id_);
	std::string welcome_str = requests::RequestFactory::instance()->convert(welcome);
	send(welcome_str);

	read();
}

void Session::read()
{
	socket_.async_read_some(boost::asio::buffer(data_, buffer_length),
		boost::bind(&Session::handle_read, this,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));
}

void Session::send(std::string &req)
{
	boost::asio::async_write(socket_,
		boost::asio::buffer(req),
		boost::bind(&Session::handle_write, this,
		boost::asio::placeholders::error));
}

tcp::socket &Session::socket() {
	return socket_;
}

void Session::handle_read(const boost::system::error_code& error,
	size_t bytes_transferred)
{
	if (error)
		return;

	requests::Request* req = 
		requests::RequestFactory::instance()->convert(data_, bytes_transferred);

	if (req == NULL) {
		std::cout << "Request not supported: " << data_ << std::endl;
	}
	else {
		req->acceptHandler(*handler_);
	}

	// We read some data, let's read more
	read();
}

void Session::handle_write(const boost::system::error_code& error)
{
	// TODO
	if (error)
		return;
}

void Session::setId(int id) {
	id_ = id;
}

void Session::setHandler(requests::RequestHandler *handler) {
	handler_ = handler;
}

int Session::id() {
	return id_;
}
