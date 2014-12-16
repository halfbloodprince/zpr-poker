#ifndef POKER_REQUEST_FACTORY_H
#define POKER_REQUEST_FACTORY_H

#include "common/requests/request.hpp"
#include <vector>

namespace requests {

	typedef std::vector<char> RawData;

	/// @brief Factory used for object serialization
	class RequestFactory
	{
	public:
		/// @brief Get access to factory instance
		static RequestFactory *instance();

		/// @brief Convert given raw data to request object
		Request *convert(RawData &data);

		/// @brief Convert given request to raw data to be send
		RawData *convert(Request &req);

	private:
		RequestFactory();
		static RequestFactory *instance_;
	};

}

#endif