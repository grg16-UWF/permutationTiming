/*  Twig Griffin
    2024-10-23
    Project3 - Timer Class

    Calculate the time between calling start() and report()
*/

#include "Timer.hpp"
#include <sstream>
using namespace std;

Timer::Timer() {
	timev = (struct timeval *)malloc(sizeof(struct timeval));
	timez = (struct timezone *)malloc(sizeof(struct timezone));
}

Timer::~Timer() {
	free(timev);
	free(timez);
}

void Timer::start() {
	gettimeofday(timev, timez);
	startTime = timev->tv_sec;
	startUSec = timev->tv_usec;
}

int Timer::report() {
	gettimeofday(timev, timez);
	int endTime = timev->tv_sec;
	int endUsec = timev->tv_usec;

	int numSec = endTime - startTime;
	int numUSec = endUsec - startUSec;
	if( numUSec < 0 ) {
		numSec--;
		numUSec += 1000000;
	}

	int ms = (numUSec / 1000) + 1000*numSec;
	return ms;
}