/*
 * Server.h
 *
 *  Created on: 14 Aug 2019
 *      Author: osboxes
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <thread>
#include <mutex>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

#include "Timer.h"
#include "ServerHandler.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

class Server {
public:
	Server();
	virtual ~Server();

	void startServer();
	void stopServer(bool isRestart);
private:
	unique_ptr<ServerHandler> pServerHandler;
	mutex lock;
	unique_ptr<TSimpleServer> pServer;
};

#endif /* SERVER_H_ */
