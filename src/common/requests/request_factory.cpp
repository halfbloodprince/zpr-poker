#include "common/requests/request_factory.hpp"
#include "json/json.h"

#include <string>

using namespace requests;

RequestFactory *RequestFactory::instance_ = 0;

RequestFactory::RequestFactory() {
}

/// @brief Get access to factory instance
RequestFactory *RequestFactory::instance() {
	if (instance_ == 0)
		instance_ = new RequestFactory;
	return instance_;
}

/// @brief Convert given raw data to request object
Request *RequestFactory::convert(const char *buf, int len) {
	Json::Value root;
	Json::Reader reader;
	bool correct = reader.parse(buf, root, false);
	// TODO error handling

	if (root["type"] == "create_table")
		return new CreateTable();
	if (root["type"] == "msg")
		return new Msg(root["msg"].asString());
	
	// request was not recognized
	return NULL;
}

std::string RequestFactory::convert(Msg &req)
{
	Json::Value root;
	root["type"] = "msg";
	root["msg"] = req.data();
	Json::FastWriter writer;
	return writer.write(root);
}

std::string RequestFactory::convert(CreateTable &req)
{
	Json::Value root;
	root["type"] = "create_table";
	Json::FastWriter writer;
	return writer.write(root);
}
