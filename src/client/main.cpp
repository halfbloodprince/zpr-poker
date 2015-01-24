#include "client.hpp"
#include <iostream>
#include <string>
#include <boost/thread/thread.hpp>

using namespace client;

int main() {
	boost::asio::io_service io_service;
	std::string line;
	std::string local = "127.0.0.1";
	Client c(io_service, local, 1337);

	boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));

	while (std::cin >> line)
		c.write(line);
	
	t.join();

	return 0;
}
