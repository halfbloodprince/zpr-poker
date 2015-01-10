#include "server/table/table.hpp"

using namespace table;

void Table::handle(requests::Request &req)
{
	// TODO not supported
}

void Table::addPlayer(Player *player)
{
	players_.push_back(player);
}

void Table::startGame()
{
	// TODO
}

