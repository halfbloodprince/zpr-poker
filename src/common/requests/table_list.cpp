#include "common/requests/table_list.hpp"
#include "common/requests/request_handler.hpp"

using namespace requests;

TableList::TableList() 
{
}

TableList::~TableList()
{
}

void TableList::acceptHandler(RequestHandler &handler)
{
	handler.handle(*this);
}
