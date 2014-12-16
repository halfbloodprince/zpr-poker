#include "common/requests/request_factory.hpp"
#include "common/requests/msg.hpp"

#include <string>

using namespace requests;

RequestFactory *RequestFactory::instance_ = 0;

RequestFactory::RequestFactory() {
}

/// @brief Get access to factory instance
RequestFactory *RequestFactory::instance() {
	if (instance_ == 0)
		instance_ = new RequestFactory;
	return instance_;
}

/// @brief Convert given raw data to request object
Request *RequestFactory::convert(const char *buf, int len) {
	/// TODO
	
	// workaround for msg support
	return new Msg(buf, len);
}

/// @brief Convert given request to raw data to be send
std::string& RequestFactory::convert(Request &req) {
	/// TODO (could use visitor for this)

	// workaround for msg support
	Msg *m = dynamic_cast<Msg *>(&req);
	return m->data();
}
