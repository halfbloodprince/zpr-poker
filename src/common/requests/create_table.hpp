#ifndef POKER_CREATE_TABLE_REQUEST_H
#define POKER_CREATE_TABLE_REQUEST_H

#include "common/requests/request.hpp"

namespace requests {

	/// @brief Request for creating new table
	class CreateTable : public Request
	{
	public:
		CreateTable();
		~CreateTable();
		
		virtual void acceptHandler(RequestHandler &handler);

	private:
		/// TODO different game types
	};
}

#endif
