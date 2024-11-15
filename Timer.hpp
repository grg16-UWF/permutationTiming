/*  Twig Griffin
    2024-10-23
    Project3 - Timer Header

    Calculate the time between calling start() and report()
*/

#ifndef TIMER_H
#define TIMER_H

#include <iostream>

#include <sys/time.h>
#include <time.h>
#include <stdlib.h>  /*  for malloc */

using namespace std;

class Timer {
	private:
		struct timeval* timev;
		struct timezone* timez;

		int startTime;
		int startUSec;
		
	public:
		Timer();
		~Timer();
		void start();
		int report(); // reports the time since start in milliseconds
};

#endif
