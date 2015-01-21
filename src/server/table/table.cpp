#include "server/table/table.hpp"

using namespace table;

Table::Table() {
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

void Table::addPlayer(Player *player)
{
	players_.push_back(player);
}

std::string Table::desc() {
	return desc_;
}

void Table::startGame()
{
	// TODO
}

