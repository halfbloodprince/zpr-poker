#ifndef POKER_REQUEST_H
#define POKER_REQUEST_H

namespace requests {

	/// @brief Base class for all requests coming from client
	/// @details Request is created from data received by client and passed to
	/// a request handler. Response sent to client is also a request.
	class Request
	{
	public:
		virtual ~Request();
	};

}

#endif
