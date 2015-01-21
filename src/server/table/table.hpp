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
	
		/// @brief Starts the game
		virtual void handle(requests::Start &req);

		/// @brief Handle action received from player
		virtual void handle(requests::Act &req);
		
		/// @brief Add player to table
		void addPlayer(Player *player);

		/// @brief Starts game
		void startGame();

		/// @brief Returns short description of this table
		std::string desc();

	private:
		std::vector<Player *> players_;
		std::string desc_;
		// GameState *state;
	};

}

#endif
