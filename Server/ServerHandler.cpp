/*
 * DataStoreServer.cpp
 *
 *  Created on: 14 Aug 2019
 *      Author: Roberto Santana
 */

#include "ServerHandler.h"

ServerHandler::ServerHandler():
	ptrStore(new Store()),
	clientId(1)
{
}

ServerHandler::~ServerHandler() {
	ptrStore->dump();
}

string
ServerHandler::assignClientName() {
  string name = "client_" + boost::lexical_cast<string>(clientId++);
  cout << "asigning client name =" << name << endl;
  return name;
}

void
ServerHandler::connect(std::string& _return)
{
	cout << "Connecting client" << endl;
	_return = assignClientName();
}

bool
ServerHandler::insertUser(const UserData& userData)
{
	if (!ptrStore->insertData(userData.userId, userData.userName)) //improvement: find a way to encapsulate userData.
																   //because the generated code has its members public.
	{
		cout << "user " << userData.userName << " already stored" << endl;
		ptrTimer->restart();
		return false;
	}
	else
	{
		cout << "user " << userData.userName << " stored successfully" << endl;
		ptrTimer->restart();
	    return true;
	}
}

void
ServerHandler::setTimer(TimerIf *theTimer)
{
	ptrTimer.reset(theTimer);
}

void
ServerHandler::dump()
{
	ptrStore->dump();
}
