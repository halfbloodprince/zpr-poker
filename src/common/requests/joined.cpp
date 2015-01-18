#include "common/requests/joined.hpp"
#include "common/requests/request_handler.hpp"

using namespace requests;

Joined::Joined(int id) 
	: id_(id)
{
}

Joined::~Joined()
{}

int Joined::id()
{
	return id_;
}

void Joined::acceptHandler(RequestHandler &handler)
{
	handler.handle(*this);
}
