#ifndef POKER_REQUEST_H
#define POKER_REQUEST_H

#include "common/requests/request_handler.hpp"
#include "server/session.hpp"

#include <vector>

namespace lobby {

	/// @brief Store multiple sessions and manages them
	class Lobby : public Requests::RequestHandler
	{
	public:
		virtual void handle(Request *req) = 0;

	private:
		std::vector<Session *> sessions_;
	};

}

#endif
