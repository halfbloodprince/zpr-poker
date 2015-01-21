#ifndef POKER_QUIT_REQUEST_H
#define POKER_QUIT_REQUEST_H

#include "common/requests/request.hpp"

#include <string>

namespace requests {

	/// @brief Request for do some action on the table
	class Quit : public Request
	{
	public:
		/// @brief Construct quit request
		/// @param full When true, user is closing his session for good.
		/// Quit only from game if false and in game already
		Quit(bool full = false);
		~Quit();

		/// @brief Give full parameter of quit
		bool full();

		/// Default acception enabling request handling by different handlers
		virtual void acceptHandler(RequestHandler &handler);

	private:
		bool full_;
	};

}

#endif
