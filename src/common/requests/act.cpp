#include "common/requests/act.hpp"
#include "common/requests/request_handler.hpp"

using namespace requests;

Act::Act(const std::string &name) 
	: name_(name)
{
}

Act::~Act()
{}

std::string& Act::name()
{
	return name_;
}

void Act::acceptHandler(RequestHandler &handler)
{
	handler.handle(*this);
}
