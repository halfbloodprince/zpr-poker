#ifndef POKER_LOBBY_H
#define POKER_LOBBY_H

#include "common/requests/request_handler.hpp"
#include "common/requests/msg.hpp"
#include "common/requests/create_table.hpp"
#include "server/session.hpp"
#include "server/table/table.hpp"

#include <vector>
#include <map>

namespace lobby {

	/// @brief Store multiple sessions and manages them
	class Lobby : public requests::RequestHandler
	{
	public:
		/// @brief Default behavior for requests (not supported)
		virtual void handle(requests::Request &req);

		///@brief Handle msg request
		virtual void handle(requests::Msg &req);

		/// @brief Handle creating table request
		/// @details create new table and send its details
		/// to client. Client is binded to this table until 
		/// quit or disconnected.
		virtual void handle(requests::CreateTable &req);

		void addSession(Session *ses); 

		void createTable();

	private:
		std::vector<Session *> sessions_;
		std::map<int, table::Table *> tables_;

		/// @brief Find free table id
		int freeTableId();
	};

}

#endif
