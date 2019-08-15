/*
 * DataStoreServer.h
 *
 *  Created on: 14 Aug 2019
 *      Author: Roberto Santana
 */

#ifndef SERVERHANDLER_H_
#define SERVERHANDLER_H_

#include <string>
#include <stdlib.h>
#include <iostream>
#include "TimerIf.h"

#include "Store.h"
#include "../remote_operations_lib/RemoteOperations.h"

using namespace ::RemoteOperations::thrift::impl;
using namespace std;

class TimerIf;

class ServerHandler: virtual public RemoteOperationsIf {
public:
	ServerHandler();
	virtual ~ServerHandler();

	void connect(std::string& _return);
	bool insertUser(const UserData& userData);

	void setTimer(TimerIf *ptrTimer);
	void dump();

private:
	string assignClientName();
	unique_ptr<TimerIf> ptrTimer;
    unique_ptr<StoreIf> ptrStore;
    unsigned int clientId;
};

#endif /* SERVERHANDLER_H_ */
