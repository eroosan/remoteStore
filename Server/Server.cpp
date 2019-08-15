/*
 * Server.cpp
 *
 *  Created on: 14 Aug 2019
 *      Author: Roberto Santana
 */

#include "Server.h"

Server::Server()
{
	pServer.reset(nullptr);
	pServerHandler.reset(nullptr);
	startServer();
}

Server::~Server() {
}

void
Server::startServer() {

	boost::asio::io_service io;
	unique_ptr<TimerIf> timer(new Timer(io));
	timer->setTimeoutReceptor(this);

	int port = 9090;

	ServerHandler *serverHandler = new ServerHandler();

    pServerHandler.reset(serverHandler);
    pServerHandler->setTimer(timer.get());

	::apache::thrift::stdcxx::shared_ptr<ServerHandler> handler(serverHandler);
	::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new RemoteOperationsProcessor(handler));
	::apache::thrift::stdcxx::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
	::apache::thrift::stdcxx::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
	::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

	pServer.reset(new TSimpleServer(processor, serverTransport, transportFactory, protocolFactory));

	thread timerThread([&] () {
		timer->run(io);
	});

	cout << "starting server" << endl;
	pServer->serve();
}

void
Server::stopServer(bool isRestart) {
	if (!isRestart)
	{
		cout << "Stopping server" << endl;
		pServer->stop();
		pServerHandler->dump();
	}
}
