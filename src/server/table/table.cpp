#include "server/table/table.hpp"

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

