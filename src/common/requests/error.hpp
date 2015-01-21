#ifndef POKER_ERROR_REQUEST_H
#define POKER_ERROR_REQUEST_H

#include "common/requests/request.hpp"

#include <string>

namespace requests {

	/// @brief Informs that something went wrong
	/// @details When client request was invalid, he gets this as answer.
	class Error : public Request
	{
	public:
		Error(const std::string &data);
		~Error();

		/// @brief Returns error message
		std::string& data();

		/// Default acception enabling request handling by different handlers
		virtual void acceptHandler(RequestHandler &handler);

	private:
		std::string data_;
	};

}

#endif
