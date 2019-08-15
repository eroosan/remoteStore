/*
 * Store.h
 *
 *  Created on: 4 Aug 2019
 *      Author: Roberto Santana
 */

#ifndef STORE_H_
#define STORE_H_

#include "StoreIf.h"
#include <map>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using us_int = unsigned short int;

class Store: public StoreIf {
public:
	Store();
	virtual ~Store();
	bool insertData(us_int, string);
	void dump();
private:
    map<us_int,string> dataStore;
};

#endif /* STORE_H_ */
