#ifndef POKER_CLIENT_H
#define POKER_CLIENT_H

#include <boost/asio.hpp>
#include <string>

class Client {
public:
	/// @brief Construct client based on given service and connect to given address
	Client(boost::asio::io_service &io_service, std::string &ip, int port);

	/// @brief write data to server
	void write(std::string &req);

private:
	/// @brief Do after successfull connection
	void handle_connect(const boost::system::error_code &e);
	
	/// @brief Handle read data
	void handle_read(const boost::system::error_code &e);
	
	/// @brief Do after writting
	void handle_write(const boost::system::error_code &e);

	boost::asio::io_service &io_service_;
	boost::asio::ip::tcp::socket socket_;
	boost::asio::ip::tcp::endpoint endpoint_;
};

#endif
