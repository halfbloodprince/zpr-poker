#ifndef POKER_REQUEST_H
#define POKER_REQUEST_H

namespace requests {

	/// @brief Base class for all requests coming from client
	class RequestFactory
	{
	public:
		static RequestFactory *instance();
	private:
		RequestFactory();
		RequestFactory *instance_;
	};

}

#endif
