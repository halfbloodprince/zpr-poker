#include "common/requests/msg.hpp"

using namespace requests;

Msg::Msg(RawData *data) : data_(data)
{}

Msg::~Msg()
{}

RawData *Msg::data()
{
	return data_;
}