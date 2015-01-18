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
	if (root["type"] == "joined")
		return new Joined(root["id"].asInt());
	if (root["type"] == "act")
		return new Act(root["name"].asString());
	if (root["type"] == "error")
		return new Act(root["data"].asString());
	if (root["type"] == "table_list") {
		TableList *tables = new TableList();
		for (Json::ValueIterator it = root["tables"].begin();
			it != root["tables"].end(); ++it) {
			tables->tables_.push_back(std::make_pair((*it)["id"].asInt(),
				(*it)["desc"].asString()));
		}
		return new Act(root["tables"].asString());
	}
	
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

std::string RequestFactory::convert(Joined &req)
{
	Json::Value root;
	root["type"] = "joined";
	root["id"] = req.id();
	Json::FastWriter writer;
	return writer.write(root);
}

std::string RequestFactory::convert(Act &req)
{
	Json::Value root;
	root["type"] = "act";
	root["name"] = req.name();
	Json::FastWriter writer;
	return writer.write(root);
}

std::string RequestFactory::convert(Error &req)
{
	Json::Value root;
	root["type"] = "error";
	root["data"] = req.data();
	Json::FastWriter writer;
	return writer.write(root);
}

std::string RequestFactory::convert(TableList &req)
{
	Json::Value root;
	Json::Value node;

	root["type"] = "table_list";
	root["tables"] = Json::Value(Json::arrayValue);
	for (auto it = req.tables_.begin(); it != req.tables_.end(); ++it) {
		node["id"] = it->first;
		node["desc"] = it->second;
		root["tables"].append(node);
	}

	Json::FastWriter writer;
	return writer.write(root);
}
