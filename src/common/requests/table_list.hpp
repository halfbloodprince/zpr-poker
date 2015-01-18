#ifndef POKER_TABLE_LIST_REQUEST_H
#define POKER_TABLE_LIST_REQUEST_H

#include "common/requests/request.hpp"
#include "common/id_container.hpp"

#include <string>
#include <vector>

namespace requests {

	/// @brief Informs abaout tables opened for joining
	class TableList : public Request
	{
	public:
		friend class RequestFactory;

		TableList();
		~TableList();

		/// @brief Add table to list
		void addTable(int k, std::string label);
		
		/// Default acception enabling request handling by different handlers
		virtual void acceptHandler(RequestHandler &handler);

	private:
		std::vector<std::pair<int, std::string> > tables_;
	};

}

#endif
