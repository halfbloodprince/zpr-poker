#include "common/requests/act.hpp"
#include "common/requests/request_handler.hpp"

using namespace requests;

Act::Act(const std::string &name, int bet)
	: name_(name), bet_(bet)
{
}

Act::~Act()
{}

std::string& Act::name()
{
	return name_;
}

int Act::bet()
{
	return bet_;
}

void Act::acceptHandler(RequestHandler &handler)
{
	handler.handle(*this);
}
