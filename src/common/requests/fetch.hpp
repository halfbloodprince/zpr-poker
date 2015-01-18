#ifndef POKER_FETCH_REQUEST_H
#define POKER_FETCH_REQUEST_H

#include "common/requests/request.hpp"

#include <string>

namespace requests {

	/// @brief Request for specific informations
	/// @brief Client may request for information like open games or 
	/// other players.
	class Fetch : public Request
	{
	public:
		Fetch(std::string what);
		~Fetch();

		std::string &what();

		/// Default acception enabling request handling by different handlers
		virtual void acceptHandler(RequestHandler &handler);

	private:
		std::string what_;
	};

}

#endif
