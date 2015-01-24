#include "server/table/table.hpp"
#include "common/requests/cards.hpp"
#include "common/requests/request_factory.hpp"

#include <boost/bind.hpp>
#include <exception>
#include <iostream>

using namespace table;

Table::Table(requests::RequestHandler *parent) : parent_(parent) {
	desc_ = "Default table";

	Py_Initialize();
    	PyRun_SimpleString("import sys; sys.path.append('./scripting')");
	PyObject *name = PyUnicode_FromString("game");
	PyObject *module = PyImport_Import(name);
	PyObject *game_class = PyObject_GetAttrString(module, "Game");
	game_ = PyObject_CallObject(game_class, NULL);

	if (!game_)
		std::cout << "not a game!\n";
	Py_DECREF(name);
}

Table::~Table() {
	Py_DECREF(game_);
	Py_Finalize();
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
	PyObject *func = PyObject_GetAttrString(game_, "fun");
	if (!func || !PyCallable_Check(func))
		std::cout << "no function!\n";

	PyObject *args = PyTuple_New(1);
	PyObject *val = PyLong_FromLong(7);
	PyTuple_SetItem(args, 0, val);
	std::cout << "calling\n";

	PyObject *res = PyObject_CallObject(func, args);
	std::cout << "called\n";
	std::cout << PyLong_AsLong(res) << std::endl;

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
