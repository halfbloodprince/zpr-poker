#include <iostream>
#include <boost/lexical_cast.hpp>

#include "server.hpp"

int main(int argc, char* argv[])
{
	try
	{
		if (argc != 2)
		{
			std::cerr << "Usage: pokerd <port>\n";
			return 1;
		}
		boost::asio::io_service io_service;

		Server s(io_service, boost::lexical_cast<short>(argv[1]));
		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}
