#ifndef POKER_ACT_REQUEST_H
#define POKER_ACT_REQUEST_H

#include "common/requests/request.hpp"

#include <string>

namespace requests {

	/// @brief Request for do some action on the table
	class Act : public Request
	{
	public:
		Act(const std::string &name, int bet = 0);
		~Act();

		/// @brief Give name of thin action
		std::string& name();

		/// @brief How much
		int bet();

		/// Default acception enabling request handling by different handlers
		virtual void acceptHandler(RequestHandler &handler);

	private:
		std::string name_;
		int bet_;
	};

}

#endif
