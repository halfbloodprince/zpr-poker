#include "server/lobby/lobby.hpp"
#include "common/requests/request_factory.hpp"

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
		std::string str = requests::RequestFactory::instance()->convert(req);
		(*it)->send(str);
	}
}



void Lobby::addSession(Session *ses)
{
	sessions_.push_back(ses);
}
