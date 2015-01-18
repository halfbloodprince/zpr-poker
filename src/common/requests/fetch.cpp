#include "common/requests/fetch.hpp"
#include "common/requests/request_handler.hpp"

using namespace requests;

Fetch::Fetch(std::string what) : what_(what)
{
}

Fetch::~Fetch()
{}

std::string &Fetch::what() {
	return what_;
}

void Fetch::acceptHandler(RequestHandler &handler)
{
	handler.handle(*this);
}
