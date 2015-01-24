#ifndef POKER_REQUEST_HANDLER_H
#define POKER_REQUEST_HANDLER_H

#include "common/requests/request.hpp"

namespace requests {

	class Request;
	class Msg;
	class Act;
	class CreateTable;
	class Fetch;
	class Start;
	class Quit;
	class Cards;

	/// @brief Base class for all handlers
	class RequestHandler
	{
	public:
		virtual void handle(Request &req) = 0;
		virtual void handle(Msg &req) {
			handle(reinterpret_cast<Request&>(req));
		}
		virtual void handle(CreateTable &req) {
			handle(reinterpret_cast<Request&>(req));
		}
		virtual void handle(Fetch &req) {
			handle(reinterpret_cast<Request&>(req));
		}
		virtual void handle(Start &req) {
			handle(reinterpret_cast<Request&>(req));
		}
		virtual void handle(Act &req) {
			handle(reinterpret_cast<Request&>(req));
		}
		virtual void handle(Quit &req) {
			handle(reinterpret_cast<Request&>(req));
		}
		virtual void handle(Cards &req) {
			handle(reinterpret_cast<Request&>(req));
		}
	};

}
#endif
