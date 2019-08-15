/*
 * StoreIf.h
 *
 *  Created on: 4 Aug 2019
 *      Author: Roberto Santana
 */

#ifndef STOREIF_H_
#define STOREIF_H_

#include <string>
using namespace std;

class StoreIf {
public:
	StoreIf() = default;
	virtual ~StoreIf() = default;
	virtual bool insertData(unsigned short int, string) = 0;
	virtual void dump() = 0;
};

#endif /* SERVER_H_ */
