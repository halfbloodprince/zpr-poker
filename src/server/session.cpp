#include "server/session.hpp"

#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

Session::Session(boost::asio::io_service& io_service, RequestHandler *handler)
	: socket_(io_service)
	: handler_(handler)
{
}

void Session::start()
{
	socket_.async_read_some(boost::asio::buffer(data_, buffer_length),
		boost::bind(&Session::handle_read, this,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));
}

void Session::send(Request *req)
{
	// TODO
}

void Session::handle_read(const boost::system::error_code& error,
	size_t bytes_transferred)
{
	if (error)
		return;
	
	// TODO Creating request objectfrom raw data
	Request* req = NULL;
	handler_->handle(req);
}

void Session::handle_write(const boost::system::error_code& error)
{
	// TODO
	if (error)
		return;

	// We read some data, let's read more
	start();
}
