/* SPB.h
 * Scheduler which uses the SPB algorithm
 *
 * EECE 315
 * Group BB4
 */

#ifndef SPBSCHEDULER_H
#define SPBSCHEDULER_H

#include "PCB.h"
#include "ReadyQueue.h"
#include "Scheduler.h"

using namespace std;

class SPBScheduler: public Scheduler{

	public:
		/* Constructor for SPB
		 */
		SPBScheduler(bool doesTimeSlice, int quantumTime, double weightedAverage);

		/* Selects the next process to be run in the CPU
		 * Uses the SPB algorithm
		 * @return: pointer to the process to be run next
		 */
		PCB* schedule(ReadyQueue* q);	

};
#endif
