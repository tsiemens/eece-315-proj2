/* SchedulerFactory.cpp
 * Factory for schedulers
 *
 * EECE 315
 * Group BB4
 */

#include "SchedulerFactory.h"
#include "FirstScheduler.h"
#include "PriorityScheduler.h"
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
		case PPP:{
			// Premptive Priority Polite
			PriorityScheduler* temp = new PriorityScheduler(quantumTime, false);
			scheduler = temp;
			break;
		}
		case IPP:{
			// Premptive Priority Impolite
			PriorityScheduler* temp = new PriorityScheduler(quantumTime, true);
			scheduler = temp;
			break;
		}
		case NPP:{
			// Non Premptive Priority
			PriorityScheduler* temp = new PriorityScheduler(quantumTime, false);
			temp.setDoesTimeSlice(false);
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

