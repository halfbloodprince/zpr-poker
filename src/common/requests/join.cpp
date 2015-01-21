#include "common/requests/join.hpp"
#include "common/requests/request_handler.hpp"

using namespace requests;

Join::Join(int table) : table_(table)
{}

Join::~Join()
{}

int Join::table()
{
	return table_;
}

void Join::acceptHandler(RequestHandler &handler)
{
	handler.handle(*this);
}
