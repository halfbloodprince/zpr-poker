#ifndef POKER_TABLE_H
#define POKER_TABLE_H

#include "common/requests/request_handler.hpp"
#include "common/requests/msg.hpp"
#include "common/requests/quit.hpp"
#include "server/player.hpp"
#include "common/id_container.hpp"

#include <vector>
#include <string>
#include <Python.h>

namespace table {

	/// @brief Stores single game
	class Table : public requests::RequestHandler
	{
	public:
		Table(requests::RequestHandler *parent);
		~Table();

		/// @brief Default behavior for requests (not supported)
		virtual void handle(requests::Request &req);
	
		/// @brief Starts the game
		virtual void handle(requests::Start &req);

		/// @brief Handle action received from player
		virtual void handle(requests::Act &req);
		
		/// @brief Handle quitting request
		virtual void handle(requests::Quit &req);

		/// @brief Add player to table
		void addPlayer(std::shared_ptr<Session> player);

		/// @brief Starts game
		void startGame();

		/// @brief Returns short description of this table
		std::string desc();

		/// @brief Sends information to all players about changes on the table
		void informPlayers();

		// @brief Inform given player about changes
		void informPlayer(std::shared_ptr<Session> player);

	private:
		IdContainer<std::shared_ptr<Session> > players_;
		std::string desc_;
		requests::RequestHandler *parent_;
		PyObject *game_;
	};

}

#endideonef
