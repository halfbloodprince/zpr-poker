#ifndef POKER_SERVER_H
#define POKER_SERVER_H

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "server/session.hpp"
#include "server/lobby/lobby.hpp"

using boost::asio::ip::tcp;

class Server
{
public:
	Server(boost::asio::io_service& io_service, short port);

private:
	/// @brief Start accepting connections
	void start_accept();

	/// @brief Handle new connection
	void handle_accept(Session* new_session,
		const boost::system::error_code& error);

	boost::asio::io_service& io_service_;
	tcp::acceptor acceptor_;

	lobby::Lobby lobby_;
};

#endif
