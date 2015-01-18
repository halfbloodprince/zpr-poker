#include "common/requests/error.hpp"
#include "common/requests/request_handler.hpp"

using namespace requests;

Error::Error(const std::string &data) 
	: data_(data)
{
}

Error::~Error()
{}

std::string& Error::data()
{
	return data_;
}

void Error::acceptHandler(RequestHandler &handler)
{
	handler.handle(*this);
}
