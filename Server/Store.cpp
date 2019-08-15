/*
 * Store.cpp
 *
 *  Created on: 4 Aug 2019
 *      Author: Roberto Santana
 */

#include "Store.h"

Store::Store() {

}

Store::~Store() {
}

bool
Store::insertData(us_int id, string name)
{
    auto ret = dataStore.emplace(id, name);
    return ret.second;
}

void
Store::dump()
{
	ofstream dumpStream;
	dumpStream.open("./dump.txt");

	if (!dumpStream)
		throw "Cannot open the dump file!!";

	for (auto it = dataStore.begin(); it != dataStore.end(); ++it)
	{
		dumpStream << "ID: " << boost::lexical_cast<string>(it->first) << ", Name: " << it->second << endl;
	}

	dumpStream.close();
}
