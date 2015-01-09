#ifndef POKER_LOBBY_H
#define POKER_LOBBY_H

#include "common/requests/request_handler.hpp"
#include "common/requests/msg.hpp"
#include "server/session.hpp"
#include "server/table/table.hpp"

#include <vector>

namespace lobby {

	/// @brief Store multiple sessions and manages them
	class Lobby : public requests::RequestHandler
	{
	public:
		/// @brief Default behavior for requests (not supported)
		virtual void handle(requests::Request &req);

		///@brief Handle msg request
		virtual void handle(requests::Msg &req);

		void addSession(Session *ses); 

		void createTable();

	private:
		std::vector<Session *> sessions_;
		std::vector<table::Table *> tables_;
	};

}

#endif
