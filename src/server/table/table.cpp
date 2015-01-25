#include "server/table/table.hpp"
#include "common/requests/cards.hpp"
#include "common/requests/request_factory.hpp"

#include <boost/bind.hpp>
#include <exception>
#include <iostream>

using namespace table;

Table::Table(requests::RequestHandler *parent)
	: parent_(parent)
	, turn_(0) {
	desc_ = "Default table";

	Py_Initialize();
    	PyRun_SimpleString("import sys; sys.path.append('./scripting')");
	PyObject *name = PyUnicode_FromString("table");
	if (!name)
		throw std::exception();
	PyObject *module = PyImport_Import(name);
	PyObject *game_class = PyObject_GetAttrString(module, "Table");
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
	PyObject *pFunc = PyObject_GetAttrString(game_, "start");
	if (!pFunc || !PyCallable_Check(pFunc))
		throw std::exception();

	PyObject *res = PyObject_CallObject(pFunc, NULL);
}

void Table::handle(requests::Act &req)
{
	PyObject *func = PyObject_GetAttrString(game_, "auction");
	if (!func || !PyCallable_Check(func))
		std::cout << "no function!\n";

	PyObject *args = PyTuple_New(3);

	PyObject *pid = PyLong_FromLong(req.id());
	PyTuple_SetItem(args, 0, pid);

	PyObject *pname = PyUnicode_FromString(req.name().c_str());
	PyTuple_SetItem(args, 1, pname);

	PyObject *pbet = PyLong_FromLong(req.bet());
	PyTuple_SetItem(args, 2, pbet);

	PyObject *pres = PyObject_CallObject(func, args);
	int left = PyLong_AsLong(PyList_GetItem(pres, 0));
	int success = PyLong_AsLong(PyList_GetItem(pres, 1));

	if (left == 0 && success >= 0) {
		playNext();
	}

	Py_DECREF(pid);
	Py_DECREF(pname);
	Py_DECREF(pbet);
	Py_DECREF(args);
}

void Table::handle(requests::Quit &req)
{
	players_.get(req.id())->setHandler(parent_);
	players_.remove(req.id());
}

void Table::addPlayer(std::shared_ptr<Session> player)
{
	int id = players_.add(player);

	PyObject *pFunc = PyObject_GetAttrString(game_, "add_players");
	if (!pFunc || !PyCallable_Check(pFunc))
		throw std::exception();
	
	PyObject *pArgs = PyTuple_New(2);
	PyTuple_SetItem(pArgs, 0, PyLong_FromLong(player->id()));
	PyTuple_SetItem(pArgs, 1, PyLong_FromLong(player->cash_));

	PyObject *res = PyObject_CallObject(pFunc, pArgs);
	Py_DECREF(pArgs);
}

std::string Table::desc() {
	return desc_;
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

	
	PyObject *fun = PyObject_GetAttrString(game_, "board");
	if (!fun || !PyCallable_Check(fun))
		throw std::exception();
	PyObject *board = PyObject_CallObject(fun, NULL);

	for (int i = 0; i < PyList_Size(board); ++i) {
		PyObject *val = PyList_GetItem(board, i);
		req.addTable(PyUnicode_AsUTF8(val));
	}

	std::string data = requests::RequestFactory::instance()->convert(req);
	player->send(data);
}

void Table::playNext()
{	
	PyObject *fun = NULL;

	if (turn_ == 0)
		fun = PyObject_GetAttrString(game_, "play_flop");
	else if (turn_ == 1)
		fun = PyObject_GetAttrString(game_, "play_turn");
	else
		fun = PyObject_GetAttrString(game_, "play_river");

	if (!fun || !PyCallable_Check(fun))
		throw std::exception();

	PyObject_CallObject(fun, NULL);
	++turn_;
	informPlayers();
	Py_DECREF(fun);
}
