#ifndef POKER_MSG_REQUEST_H
#define POKER_MSG_REQUEST_H

#include "common/requests/request.hpp"

#include <string>

namespace requests {

	/// @brief Simplest request class for sending data
	class Msg : public Request
	{
	public:
		Msg(const std::string &data);
		~Msg();

		std::string& data();

		virtual void acceptHandler(RequestHandler &handler);

	private:
		std::string data_;
	};

}

#endif
