#include "server/lobby/lobby.hpp"
#include "common/requests/request_factory.hpp"
#include "server/table/table.hpp"
#include <iostream>

using namespace lobby;

void Lobby::handle(requests::Request &req)
{
	std::cout << "Request is not supported\n";
	/// TODO
}

void Lobby::handle(requests::Msg &req)
{
	for (auto it = sessions_.data_.begin(); it != sessions_.data_.end(); ++it) {
		std::string str = requests::RequestFactory::instance()->convert(req);
		it->second->send(str);
	}
}

void Lobby::handle(requests::Fetch &req)
{
	if (req.what() == "table_list") {
		requests::TableList ans;
		ans.setId(req.id());

		for (auto it = tables_.data_.begin(); it != tables_.data_.end(); ++it) {
			ans.addTable(it->first, it->second->desc());
		}

		std::string data = requests::RequestFactory::instance()->convert(ans);
		if (sessions_.exist(req.id())) {
			sessions_.data_[req.id()]->send(data);
		}
	}
	// TODO other requests
}

void Lobby::handle(requests::Join &req)
{
	int id = req.table();
	if (!sessions_.exist(req.id())) {
		// TODO handle this situation
	} else if (!tables_.exist(id)) {
		requests::Error err("Table does not exist");
		err.setId(req.id());

		std::string data = requests::RequestFactory::instance()->convert(err);
		sessions_.data_[req.id()]->send(data);
	} else {
		table::Table *tab = tables_.get(id);
		requests::Joined ans(id);
		std::string data = requests::RequestFactory::instance()->convert(ans);
		Session *ses = sessions_.get(req.id());
		ses->setHandler(tab);
		ses->send(data);
	}
}

void Lobby::handle(requests::CreateTable &req)
{
	table::Table *tab = new table::Table();
	int id = tables_.add(tab);

	if (sessions_.exist(req.id())) {
		requests::Joined ans(id);
		std::string data = requests::RequestFactory::instance()->convert(ans);
		Session *ses = sessions_.data_[req.id()];
		ses->setHandler(tab);
		ses->send(data);
	}
}

void Lobby::addSession(Session *ses)
{
	int id = sessions_.add(ses);
	ses->setId(id);
}
