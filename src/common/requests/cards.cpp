#include "common/requests/cards.hpp"
#include "common/requests/request_handler.hpp"

using namespace requests;

Cards::Cards()
{}
Cards::~Cards()
{}

void Cards::addHand(card::Card card)
{
	hand_.push_back(card);
}

void Cards::addTable(card::Card card)
{
	table_.push_back(card);
}

void Cards::acceptHandler(RequestHandler &handler)
{
	handler.handle(*this);
}
