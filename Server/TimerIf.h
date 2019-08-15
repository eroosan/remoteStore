/*
 * Timer.h
 *
 *  Created on: 7 Aug 2019
 *      Author: Roberto Santana
 */

#ifndef TIMERIF_H_
#define TIMERIF_H_

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "ServerHandler.h"

using namespace boost::asio;
using namespace std;

class Server;

class TimerIf {
public:
	TimerIf() = default;
	virtual ~TimerIf() = default;
	virtual void setTimeoutReceptor(Server *) = 0;
	virtual void run(boost::asio::io_service &io) = 0;
	virtual void restart() = 0;
private:
	virtual void onTimeout() = 0;
};

#endif /* TIMERIF_H_ */
