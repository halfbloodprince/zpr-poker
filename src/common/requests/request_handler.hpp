#ifndef POKER_REQUEST_HANDLER_H
#define POKER_REQUEST_HANDLER_H

#include "common/requests/request.hpp"
#include "common/requests/msg.hpp"

namespace requests {

	/// @brief Base class for all handlers
	class RequestHandler
	{
	public:
		virtual void handle(Request &req) = 0;
	};

}
#endif
