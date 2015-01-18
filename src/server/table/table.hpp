#ifndef POKER_TABLE_H
#define POKER_TABLE_H

#include "common/requests/request_handler.hpp"
#include "common/requests/msg.hpp"
#include "server/player.hpp"

#include <vector>
#include <string>

namespace table {

	/// @brief Stores single game
	class Table : public requests::RequestHandler
	{
	public:
		Table();

		/// @brief Default behavior for requests (not supported)
		virtual void handle(requests::Request &req);
	
		/// @brief Add player to table
		void addPlayer(Player *player);

		/// @brief Starts game
		void startGame();

		virtual void handle(requests::Msg &req) {}
		virtual void handle(requests::CreateTable &req) {}
		virtual void handle(requests::Fetch &req) {}

		std::string desc();

	private:
		std::vector<Player *> players_;
		std::string desc_;
		// GameState *state;
	};

}

#endif
