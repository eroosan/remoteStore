/*
 * Client.cpp
 *
 *  Created on: 9 Aug 2019
 *      Author: Roberto Santana
 */

#include "Client.h"

#include <stdlib.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <boost/lexical_cast.hpp>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

Client::Client()
{

}

Client::~Client() {

}

void
Client::run() {

	std::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
	std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
	RemoteOperationsClient rmClient(protocol);

	try {
		transport->open();
		cout << "Client connected" << endl;

		rmClient.connect(clientName);
		cout << "Client name assigned by server:" << clientName << endl;

		time_point<system_clock> startPoint, endPoint;

		string userName = "user";
		us_int userId = 0;
		us_int numberOfIds = 0;

		do {

			startPoint = system_clock::now();

			userId = assignId(userId);
			UserData userData;
			userData.__set_userId(userId);
			userData.__set_userName(userName + boost::lexical_cast<string>(userId));

			auto retCode = rmClient.insertUser(userData);
			endPoint = system_clock::now();
			std::chrono::duration<double> elapsedTime = endPoint - startPoint;

			cout << "User sent: " << userName << ",Id: " << userId << endl;
			cout << "Time elapsed until server response: " << elapsedTime.count() << endl;
			cout << "Response from the server :" << (retCode? "success":"failure") << endl;

			if (retCode) numberOfIds++;

			cout << "Number of free IDs = " << boost::lexical_cast<string>(250 - numberOfIds) << endl;
			cout << endl;

			std::this_thread::sleep_for(std::chrono::seconds(1));

		} while (numberOfIds < 250);

		transport->close();
	}
	catch (TException& tx) {
	    cout << "ERROR: " << tx.what() << endl;
	}
}

us_int
Client::assignId(us_int lastIdGenerated)
{
	us_int id;
	do {
		id = rand() % 250 + 1;
	} while (lastIdGenerated == id); //I doubt it is going to repeat the same random
									 //number , but just in case.
	return id;
}

