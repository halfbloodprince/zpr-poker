#include "common/requests/table_list.hpp"
#include "common/requests/request_handler.hpp"

using namespace requests;

TableList::TableList() 
{
}

TableList::~TableList()
{
}

void TableList::addTable(int k, std::string label) {
	tables_.push_back(std::make_pair(k, label));
}

void TableList::acceptHandler(RequestHandler &handler)
{
	handler.handle(*this);
}
