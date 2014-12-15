#ifndef POKER_REQUEST_HANDLER_H
#define POKER_REQUEST_HANDLER_H

#include "common/requests/request.hpp"

namespace requests {

	/// @brief Base class for all handlers
	class RequestHandler
	{
	public:
		/// @brief Handle given request
		/// @param[in] req Request object to be handled
		virtual void handle(Request *req) = 0;
	};

}
#endif
