#include "server/table/table.hpp"
#include "common/requests/cards.hpp"
#include "common/requests/request_factory.hpp"

#include <boost/bind.hpp>

using namespace table;

Table::Table(requests::RequestHandler *parent) : parent_(parent) {
	desc_ = "Default table";
}

void Table::handle(requests::Request &req)
{
	// TODO not supported
}

void Table::handle(requests::Start &req)
{
	// TODO starting a game
}

void Table::handle(requests::Act &req)
{
	// TODO making action
}

void Table::handle(requests::Quit &req)
{
	players_.get(req.id())->setHandler(parent_);
	players_.remove(req.id());
}

void Table::addPlayer(std::shared_ptr<Session> player)
{
	players_.add(player);
}

std::string Table::desc() {
	return desc_;
}

void Table::startGame()
{
	// TODO
}

void Table::informPlayers()
{
	for_each(players_.data_.begin(), players_.data_.end(),
		[this](std::pair<int, std::shared_ptr<Session> > a)
		{this->informPlayer(a.second);});
}

void Table::informPlayer(std::shared_ptr<Session> player)
{
	requests::Cards req;
	req.setId(player->id());
	// TODO fill info about cards
	std::string data = requests::RequestFactory::instance()->convert(req);
	player->send(data);
}
