/*
 * Client.h
 *
 *  Created on: 9 Aug 2019
 *      Author: Roberto Santana
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <chrono>
#include <iostream>
#include <thread>
#include "../remote_operations_lib/RemoteOperations.h"


using std::chrono::system_clock;
using std::chrono::time_point;

using namespace ::RemoteOperations::thrift::impl;
using namespace std;

using us_int = unsigned short int;

class Client {
public:
	Client();
	virtual ~Client();
	void run();
private:
	string clientName;

	us_int assignId(us_int lastIdGenerated);

};

#endif /* CLIENT_H_ */
