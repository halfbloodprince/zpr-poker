#ifndef POKER_REQUEST_FACTORY_H
#define POKER_REQUEST_FACTORY_H

#include "common/requests/request.hpp"
#include "common/requests/msg.hpp"
#include "common/requests/create_table.hpp"
#include <string>

namespace requests {

	typedef std::string RawData;

	/// @brief Factory used for object serialization
	class RequestFactory
	{
	public:
		/// @brief Get access to factory instance
		static RequestFactory *instance();

		/// @brief Convert given raw data to request object
		Request *convert(const char *buf, int len);

		/// @brief Convert given request to raw data to be send
		std::string convert(Msg &req);
		std::string convert(CreateTable &req);

	private:
		RequestFactory();
		static RequestFactory *instance_;
	};

}

#endif
