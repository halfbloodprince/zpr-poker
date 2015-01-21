#ifndef POKER_JOIN_REQUEST_H
#define POKER_JOIN_REQUEST_H

#include "common/requests/request.hpp"

#include <string>

namespace requests {

	/// @brief Request for player informing about joining table
	class Join : public Request
	{
	public:
		Join(int table);
		~Join();
		
		/// @brief returns id of table to join
		int table();

		virtual void acceptHandler(RequestHandler &handler);

	private:
		int table_;
	};

}

#endif
