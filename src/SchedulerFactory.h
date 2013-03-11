/* SchedulerFactory.h
 * Factory for schedulers
 *
 * EECE 315
 * Group BB4
 */

#ifndef SCHEDULER_FACTORY_H
#define	SCHEDULER_FACTORY_H

#include "Scheduler.h"

enum AlgType { FCFS = 1, RR = 2, PPP = 3, IPP = 4, 
               NPP = 5, SJF = 6, SPB = 7 };

class SchedulerFactory{

	public:
		/* Creates the appropriate scheduler type
		 * @param: algIndex - the algorithm. 
		           Must be number defined by AlgType
		 * @param: quantumTime - the max time for a time slice
		 * @return: pointer to a Scheduler. Null if an error occurs.
		 */
		Scheduler* makeScheduler(int algIndex, int quantumTime);
};
#endif
