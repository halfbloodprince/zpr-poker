#ifndef POKER_REQUEST_H
#define POKER_REQUEST_H

namespace requests {

	class RequestHandler;

	/// @brief Base class for all requests coming from client
	/// @details Request is created from data received by client and passed to
	/// a request handler. Response sent to client is also a request.
	class Request
	{
	public:
		/// Accept object which will handle this request
		virtual void acceptHandler(RequestHandler &handler)=0;
	};

}

#endif
