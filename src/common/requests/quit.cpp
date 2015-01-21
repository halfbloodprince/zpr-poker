#include "common/requests/quit.hpp"
#include "common/requests/request_handler.hpp"

using namespace requests;

Quit::Quit(bool full) : full_(full)
{}

Quit::~Quit()
{}

bool Quit::full()
{
	return full_;
}

void Quit::acceptHandler(RequestHandler &handler)
{
	handler.handle(*this);
}
