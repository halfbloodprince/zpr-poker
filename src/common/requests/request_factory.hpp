#ifndef POKER_REQUEST_FACTORY_H
#define POKER_REQUEST_FACTORY_H

#include "common/requests/request.hpp"
#include "common/requests/msg.hpp"
#include "common/requests/create_table.hpp"
#include "common/requests/joined.hpp"
#include "common/requests/act.hpp"
#include "common/requests/error.hpp"
#include "common/requests/table_list.hpp"
#include "common/requests/welcome.hpp"
#include "common/requests/fetch.hpp"
#include "common/requests/start.hpp"
#include "common/requests/join.hpp"
#include "common/requests/quit.hpp"
#include "common/requests/cards.hpp"
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
		/// @param buf bufer containing data
		/// @param len length of received data
		Request *convert(const char *buf, int len);

		/// @brief Convert given request to raw data to be send
		std::string convert(Msg &req);

		/// @brief Convert given request to raw data to be send
		std::string convert(CreateTable &req);

		/// @brief Convert given request to raw data to be send
		std::string convert(Joined &req);

		/// @brief Convert given request to raw data to be send
		std::string convert(Act &req);

		/// @brief Convert given request to raw data to be send
		std::string convert(Error &req);

		/// @brief Convert given request to raw data to be send
		std::string convert(TableList &req);

		/// @brief Convert given request to raw data to be send
		std::string convert(Welcome &req);

		/// @brief Convert given request to raw data to be send
		std::string convert(Fetch &req);

		/// @brief Convert given request to raw data to be send
		std::string convert(Start &req);

		/// @brief Convert given request to raw data to be send
		std::string convert(Join &req);

		/// @brief Convert given request to raw data to be send
		std::string convert(Quit &req);

		/// @brief Convert given request to raw data to be send
		std::string convert(Cards &req);

	private:
		RequestFactory();
		static RequestFactory *instance_;
	};

}

#endif
