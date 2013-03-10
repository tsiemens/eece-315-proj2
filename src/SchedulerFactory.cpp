/* SchedulerFactory.cpp
 * Factory for schedulers
 *
 * EECE 315
 * Group BB4
 */

#include "SchedulerFactory.h"
#include "FIFOScheduler.h"
#include <iostream>

using namespace std;

Scheduler* SchedulerFactory::makeScheduler(int algIndex){
	Scheduler* scheduler;
	switch(algIndex){
		case FCFS:{
			FIFOScheduler* temp = new FIFOScheduler();
			scheduler = temp;//new FIFOScheduler();
			break;
		}
		//Others here
		default:
			cout<<"Error occured getting algorithm"<<endl;
			scheduler = NULL;
	}
	return scheduler;
}

