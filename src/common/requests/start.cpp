#include "common/requests/start.hpp"
#include "common/requests/request_handler.hpp"

using namespace requests;

Start::Start() 
{}

Start::~Start()
{}

void Start::acceptHandler(RequestHandler &handler)
{
	handler.handle(*this);
}
