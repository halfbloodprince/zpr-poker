#include "server/session.hpp"

#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

#include "common/requests/request_factory.hpp"

Session::Session(boost::asio::io_service& io_service, requests::RequestHandler *handler)
	: socket_(io_service)
	, handler_(handler)
{
}

void Session::start()
{
	socket_.async_read_some(boost::asio::buffer(data_, buffer_length),
		boost::bind(&Session::handle_read, this,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));
}

void Session::send(requests::Request &req)
{
	const requests::RawData *buf = requests::RequestFactory::instance()->convert(req);
	boost::asio::async_write(socket_,
		boost::asio::buffer(buf, buf->size()),
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
	
	// TODO Creating request object from raw data
	requests::Request* req = NULL;
	handler_->handle(*req);

	// We read some data, let's read more
	start();
}

void Session::handle_write(const boost::system::error_code& error)
{
	// TODO
	if (error)
		return;
}
