/* SJFScheduler.h
 * Scheduler which uses the SJF algorithm
 *
 * EECE 315
 * Group BB4
 */

#ifndef SJFSCHEDULER_H
#define SJFSCHEDULER_H

#include "PCB.h"
#include "ReadyQueue.h"
#include "Scheduler.h"

using namespace std;

class SJFScheduler: public Scheduler{

	public:
		/* Constructor for SJF
		 */
		SJFScheduler(bool doesTimeSlice, int quantumTime);

		/* Selects the next process to be run in the CPU
		 * Uses the SJF algorithm
		 * @return: pointer to the process to be run next
		 */
		PCB* schedule(ReadyQueue* q);		
};

#endif
