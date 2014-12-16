#include "server/lobby/lobby.hpp"

#include <iostream>

using namespace lobby;

void Lobby::handle(requests::Request &req)
{
	std::cout << "Request is not supported\n";
	/// TODO
}

void Lobby::handle(requests::Msg &req)
{
	for (std::vector<Session *>::iterator it = sessions_.begin();
		it != sessions_.end(); ++it) {
		(*it)->send(req);
	}
}

void Lobby::addSession(Session *ses)
{
	sessions_.push_back(ses);
}
