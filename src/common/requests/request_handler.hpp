#ifndef POKER_REQUEST_HANDLER_H
#define POKER_REQUEST_HANDLER_H

#include "common/requests/request.hpp"

namespace requests {

	class Request;
	class Msg;
	class CreateTable;
	class Fetch;

	/// @brief Base class for all handlers
	class RequestHandler
	{
	public:
		virtual void handle(Request &req) = 0;
		virtual void handle(Msg &req) = 0;
		virtual void handle(CreateTable &req) = 0;
		virtual void handle(Fetch &req) = 0;
	};

}
#endif
