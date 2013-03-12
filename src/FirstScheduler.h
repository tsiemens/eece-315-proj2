/* FIFOScheduler.h
 * Scheduler which uses the FIFO algorithm
 *
 * EECE 315
 * Group BB4
 */

#ifndef FIRST_SCHEDULER_H
#define	FIRST_SCHEDULER_H

#include <iostream>
#include "PCB.h"
#include "ReadyQueue.h"
#include "Scheduler.h"

using namespace std;

class FirstScheduler: public Scheduler{

	public:

		/* Initializes the first type algorithm 
		 * scheduler to not interrupt.
		 * @param: doesTimeSlice - if false, scheduler is FCFS, if true is RR
		 * @param: quantumTime - quantum time, defaulted to DOES_NOT_TIME_SLICE  
		 */
		FirstScheduler(bool doesTimeSlice, int quantumTime = DOES_NOT_TIME_SLICE);

		/* Selects the next process to be run in the CPU
		 * Uses the First In First Out / Round robin algorithms.
		 * @return: pointer to the process to be run next
		 *          returns NULL if empty
		 */
		PCB* schedule(ReadyQueue* q);

};
#endif
