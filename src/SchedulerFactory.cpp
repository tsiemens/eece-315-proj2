/* SchedulerFactory.cpp
 * Factory for schedulers
 *
 * EECE 315
 * Group BB4
 */

#include "SchedulerFactory.h"
#include "FirstScheduler.h"
#include "PriorityScheduler.h"
#include "SPBScheduler.h"
#include <iostream>

using namespace std;

Scheduler* SchedulerFactory::makeScheduler(int algIndex, int quantumTime, double weightedAverage){
	Scheduler* scheduler;

	switch(algIndex){
		case FCFS:{
			//FCFS has no time slicing
			scheduler = new FirstScheduler(false);
			break;
		}
		case RR:{
			//Round robin has time slicing
			scheduler = new FirstScheduler(true, quantumTime);
			break;	
		}
		case PPP:{
			// Premptive Priority Polite
			scheduler = new PriorityScheduler(quantumTime, false, true);
			break;
		}
		case IPP:{
			// Premptive Priority Impolite
			scheduler = new PriorityScheduler(quantumTime, true, true);
			break;
		}
		case NPP:{
			// Non Premptive Priority
			scheduler = new PriorityScheduler(quantumTime, false, false);
			break;
		}
		case SPB:{
			//Shortest Previous Burst
			scheduler = new SPBScheduler(true, quantumTime, weightedAverage);
			break;
		}
		
		//Others here
		default:
			cout<<"Error occured getting algorithm"<<endl;
			scheduler = NULL;
	}
	return scheduler;
}
