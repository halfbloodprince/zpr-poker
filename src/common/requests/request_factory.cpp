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

	Request* ret = NULL;

	if (root["type"] == "create_table")
		ret = new CreateTable();
	else if (root["type"] == "msg")
		ret = new Msg(root["msg"].asString());
	else if (root["type"] == "joined")
		ret = new Joined(root["id"].asInt());
	else if (root["type"] == "act")
		ret = new Act(root["name"].asString());
	else if (root["type"] == "error")
		ret = new Act(root["data"].asString());
	else if (root["type"] == "table_list") {
		TableList *tables = new TableList();
		for (Json::ValueIterator it = root["tables"].begin();
			it != root["tables"].end(); ++it) {
			tables->tables_.push_back(std::make_pair((*it)["id"].asInt(),
				(*it)["desc"].asString()));
		}
		ret = new Act(root["tables"].asString());
	}
	// TODO error handling

	if (ret) {
		ret->id_ = root["player_id"].asInt();
	}

	return ret;
}

std::string RequestFactory::convert(Msg &req)
{
	Json::Value root;
	root["type"] = "msg";
	root["msg"] = req.data();
	root["player_id"] = req.id();
	Json::FastWriter writer;
	return writer.write(root);
}

std::string RequestFactory::convert(CreateTable &req)
{
	Json::Value root;
	root["type"] = "create_table";
	root["player_id"] = req.id();
	Json::FastWriter writer;
	return writer.write(root);
}

std::string RequestFactory::convert(Joined &req)
{
	Json::Value root;
	root["type"] = "joined";
	root["id"] = req.id();
	root["player_id"] = req.id();
	Json::FastWriter writer;
	return writer.write(root);
}

std::string RequestFactory::convert(Act &req)
{
	Json::Value root;
	root["type"] = "act";
	root["name"] = req.name();
	root["player_id"] = req.id();
	Json::FastWriter writer;
	return writer.write(root);
}

std::string RequestFactory::convert(Error &req)
{
	Json::Value root;
	root["type"] = "error";
	root["data"] = req.data();
	root["player_id"] = req.id();
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
	
	root["player_id"] = req.id();

	Json::FastWriter writer;
	return writer.write(root);
}
