#ifndef POKER_CARDS_REQUEST_H
#define POKER_CARDS_REQUEST_H

#include "common/requests/request.hpp"
#include "common/card.hpp"

#include <string>
#include <vector>

namespace requests {

	/// @brief Returns list of known cards to client
	class Cards : public Request
	{
	public:
		Cards();
		~Cards();

		/// @brief Add card to player's hand
		void addHand(card::Card card);

		/// @brief Add card to the table
		void addTable(card::Card card);

		/// Default acception enabling request handling by different handlers
		virtual void acceptHandler(RequestHandler &handler);

		std::vector<card::Card> table_;
		std::vector<card::Card> hand_;
	};

}

#endif
