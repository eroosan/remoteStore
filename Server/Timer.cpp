/*
 * Timer.cpp
 *
 *  Created on: 7 Aug 2019
 *      Author: Roberto Santana
 */

#include "Timer.h"

Timer::Timer(io_service &io):
	theTimer(io, boost::posix_time::seconds(DEFAULT_TIMER)),
	ptrTimeoutReceptor(nullptr),
	isRestart(false)
{

}

void Timer::run(io_service &io) {
	isRestart = false;
	theTimer.async_wait(boost::bind(&Timer::onTimeout, this));
	io.run();
}

Timer::~Timer() {

}

void
Timer::setTimeoutReceptor(Server *serv) {
	ptrTimeoutReceptor.reset(serv);
}

void
Timer::onTimeout() {
	ptrTimeoutReceptor->stopServer(isRestart);
}

void
Timer::restart() {
	theTimer.expires_from_now(boost::posix_time::seconds(DEFAULT_TIMER));
	isRestart = true;
	theTimer.async_wait(boost::bind(&Timer::onTimeout, this));

	//I know this is a hack, but the only way I found. Blame boost and its timers.
	//async_wait cancels the timer, and it fires the callback, which was a hassle.
	//cause it stopped the server every time it restarted. Now I indicated if it is a restart
	//and the sleep is to set the restart flag to false without being passed to the onTimeout
	//with the wrong value.
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	isRestart = false;
}

