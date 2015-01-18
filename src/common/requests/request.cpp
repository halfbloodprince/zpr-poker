#include "common/requests/request.hpp"

using namespace requests;

int Request::id() {
	return id_;
}

void Request::setId(int id) {
	id_ = id;
}
