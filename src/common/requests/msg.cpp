#include "common/requests/msg.hpp"
#include "common/requests/request_handler.hpp"
#include <iostream>

using namespace requests;

Msg::Msg(const std::string &data) 
	: data_(data)
{
}

Msg::~Msg()
{}

std::string& Msg::data()
{
	return data_;
}

void Msg::acceptHandler(RequestHandler &handler)
{
	handler.handle(*this);
}
