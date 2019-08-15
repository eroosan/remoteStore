/*
 * Timer.h
 *
 *  Created on: 7 Aug 2019
 *      Author: Roberto Santana
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <memory>
#include "Server.h"
#include "TimerIf.h"


#define DEFAULT_TIMER 60

class Timer : public TimerIf {
public:
	Timer(io_service &);
	virtual ~Timer();
	void setTimeoutReceptor(Server *);
 	void run(boost::asio::io_service &io);
 	void restart();
private:
	deadline_timer theTimer;
	unique_ptr<Server> ptrTimeoutReceptor;
	bool isRestart;

	void onTimeout();

};

#endif /* TIMER_H_ */
