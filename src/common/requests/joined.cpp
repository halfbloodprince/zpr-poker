#include "common/requests/joined.hpp"
#include "common/requests/request_handler.hpp"

using namespace requests;

Joined::Joined(int table) 
	: table_(table)
{
}

Joined::~Joined()
{}

int Joined::table()
{
	return table_;
}

void Joined::acceptHandler(RequestHandler &handler)
{
	handler.handle(*this);
}
