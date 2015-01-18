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
	for (std::map<int, Session *>::iterator it = sessions_.data_.begin();
		it != sessions_.data_.end(); ++it) {
		std::string str = requests::RequestFactory::instance()->convert(req);
		it->second->send(str);
	}
}

void Lobby::handle(requests::CreateTable &req)
{
	table::Table *tab = new table::Table();
	int id = tables_.add(tab);	
}

void Lobby::addSession(Session *ses)
{
	int id = sessions_.add(ses);
	ses->setId(id);
}
