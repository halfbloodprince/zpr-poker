#ifndef POKER_JOINED_REQUEST_H
#define POKER_JOINED_REQUEST_H

#include "common/requests/request.hpp"

#include <string>

namespace requests {

	/// @brief Request for player informing about joining table
	class Joined : public Request
	{
	public:
		Joined(int table);
		~Joined();
		
		/// @brief returns id of table to which player joined
		int table();

		virtual void acceptHandler(RequestHandler &handler);

	private:
		int table_;
	};

}

#endif
