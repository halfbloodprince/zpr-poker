#ifndef POKER_MSG_REQUEST_H
#define POKER_MSG_REQUEST_H

#include "common/requests/request.hpp"
#include "common/requests/request_factory.hpp"

namespace requests {

	/// @brief Simplest request class for sending data
	class Msg : public Request
	{
	public:
		Msg(RawData *data);
		~Msg();

		RawData *data();

	private:
		RawData *data_;
	};

}

#endif
