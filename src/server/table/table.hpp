#ifndef POKER_TABLE_H
#define POKER_TABLE_H

#include "common/requests/request_handler.hpp"
#include "common/requests/msg.hpp"
#include "server/player.hpp"

#include <vector>

namespace table {

	/// @brief Stores single game
	class Table : public requests::RequestHandler
	{
	public:
		/// @brief Default behavior for requests (not supported)
		virtual void handle(requests::Request &req);
	
		/// @brief Add player to table
		void addPlayer(Player *player);

		/// @brief Starts game
		void startGame();

	private:
		std::vector<Player *> players_;
		// GameState *state;
	};

}

#endif
