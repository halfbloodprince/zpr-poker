#include "common/requests/create_table.hpp"
#include "common/requests/request_handler.hpp"

using namespace requests;

CreateTable::CreateTable() {}
CreateTable::~CreateTable() {}

void CreateTable::acceptHandler(RequestHandler &handler)
{
	handler.handle(*this);
}
