#ifndef POKER_START_REQUEST_H
#define POKER_START_REQUEST_H

#include "common/requests/request.hpp"

#include <string>

namespace requests {

	/// @brief Simplest request class for sending data
	class Start : public Request
	{
	public:
		Start();
		~Start();

		/// @brief call handler handle method
		virtual void acceptHandler(RequestHandler &handler);
	};

}

#endif
