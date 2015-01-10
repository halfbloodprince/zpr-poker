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
	for (std::vector<Session *>::iterator it = sessions_.begin();
		it != sessions_.end(); ++it) {
		std::string str = requests::RequestFactory::instance()->convert(req);
		(*it)->send(str);
	}
}

void Lobby::handle(requests::CreateTable &req)
{
	int id = freeTableId();
	table::Table *tab = new table::Table();
	tables_[id] = tab;
	
}

void Lobby::addSession(Session *ses)
{
	sessions_.push_back(ses);
}

int Lobby::freeTableId()
{
	int ret = 0;
	while (tables_.find(ret) != tables_.end()) ++ret;
	return ret;
}
