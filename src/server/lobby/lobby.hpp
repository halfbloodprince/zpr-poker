#ifndef POKER_LOBBY_H
#define POKER_LOBBY_H

#include "common/requests/request_handler.hpp"
#include "server/session.hpp"

#include <vector>

namespace lobby {

	/// @brief Store multiple sessions and manages them
	class Lobby : public requests::RequestHandler
	{
	public:
		void handle(requests::Request &req);
		void addSession(Session *ses);

	private:
		std::vector<Session *> sessions_;
	};

}

#endif
