#include "server/lobby/lobby.hpp"
#include "common/requests/msg.hpp"

using namespace lobby;

void Lobby::handle(requests::Request &req)
{
	/// TODO

	// temporary workaround - broadcast request to everyone
	for (std::vector<Session *>::iterator it = sessions_.begin(); it != sessions_.end(); ++it) {
		(*it)->send(req);
	}
}

void Lobby::addSession(Session *ses)
{
	sessions_.push_back(ses);
}