#ifndef POKER_ACT_REQUEST_H
#define POKER_ACT_REQUEST_H

#include "common/requests/request.hpp"

#include <string>

namespace requests {

	/// @brief Request for do some action on the table
	class Act : public Request
	{
	public:
		Act(const std::string &data);
		~Act();

		std::string& name();

		/// Default acception enabling request handling by different handlers
		virtual void acceptHandler(RequestHandler &handler);

	private:
		std::string name_;
	};

}

#endif
