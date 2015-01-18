#ifndef POKER_WELCOME_REQUEST_H
#define POKER_WELCOME_REQUEST_H

#include "common/requests/request.hpp"

#include <string>

namespace requests {

	/// @brief Request sent after successfull connection
	/// @detail Tell client about his id
	class Act : public Request
	{
	public:
		Welcome();
		~Welcome();

		/// Default acception enabling request handling by different handlers
		virtual void acceptHandler(RequestHandler &handler);

	private:
	};

}

#endif
