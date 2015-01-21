#ifndef POKER_LOBBY_H
#define POKER_LOBBY_H

#include "common/requests/request_handler.hpp"
#include "common/requests/msg.hpp"
#include "common/requests/create_table.hpp"
#include "common/requests/fetch.hpp"
#include "common/requests/join.hpp"
#include "common/requests/quit.hpp"
#include "server/session.hpp"
#include "server/table/table.hpp"
#include "common/id_container.hpp"

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
		
		///@brief Handle request for data
		virtual void handle(requests::Fetch &req);

		/// @brief Handle creating table request
		/// @details create new table and send its details
		/// to client. Client is binded to this table until 
		/// quit or disconnected.
		virtual void handle(requests::CreateTable &req);

		/// @brief Handle joining a table
		/// @details Requested table must exist and
		/// game policy should allow to enter
		virtual void handle(requests::Join &req);

		/// @brief Handle quiting
		/// @details Also done when connection is lost
		virtual void handle(requests::Quit &req);

		/// @brief Add a session to this lobby
		void addSession(std::shared_ptr<Session> ses); 

	private:
		IdContainer<std::shared_ptr<Session> > sessions_;
		IdContainer<table::Table *> tables_;
	};

}

#endif
