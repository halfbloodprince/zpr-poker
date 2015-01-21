#include "server.hpp"

#include <iostream>

Server::Server(boost::asio::io_service& io_service, short port)
	: io_service_(io_service),
	acceptor_(io_service, tcp::endpoint(tcp::v4(), port))
{
	start_accept();
}

void Server::start_accept()
{
	std::shared_ptr<Session> new_session = std::make_shared<Session>(io_service_,
		static_cast<requests::RequestHandler *>(&lobby_));

	acceptor_.async_accept(new_session->socket(),
		boost::bind(&Server::handle_accept, this, new_session,
		boost::asio::placeholders::error));
}

void Server::handle_accept(std::shared_ptr<Session> new_session,
	const boost::system::error_code& error)
{
	if (!error)
	{
		lobby_.addSession(new_session);
		new_session->start();
	}

	start_accept();
}
