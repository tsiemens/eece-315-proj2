/* SchedulerFactory.cpp
 * Factory for schedulers
 *
 * EECE 315
 * Group BB4
 */

#include "SchedulerFactory.h"
#include "FirstScheduler.h"
#include <iostream>

using namespace std;

Scheduler* SchedulerFactory::makeScheduler(int algIndex, int quantumTime){
	Scheduler* scheduler;
	switch(algIndex){
		case FCFS:{
			//FCFS has no time slicing
			FirstScheduler* temp = new FirstScheduler(false);
			scheduler = temp;
			break;
		}
		case RR:{
			//Round robin has time slicing
			FirstScheduler* temp = new FirstScheduler(true, quantumTime);
			scheduler = temp;
			break;	
		}
		//Others here
		default:
			cout<<"Error occured getting algorithm"<<endl;
			scheduler = NULL;
	}
	return scheduler;
}

