#include "common/requests/welcome.hpp"
#include "common/requests/request_handler.hpp"

using namespace requests;

Welcome::Welcome() 
{
}

Welcome::~Welcome()
{}

void Welcome::acceptHandler(RequestHandler &handler)
{
	handler.handle(*this);
}
