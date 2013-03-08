/* FIFOScheduler.h
 * Scheduler which uses the FIFO algorithm
 *
 * EECE 315
 * Group BB4
 */

#ifndef FIFO_SCHEDULER_H
#define	FIFO_SCHEDULER_H

#include "PCB.h"
#include "Scheduler.h"

using namespace std;

class FIFOScheduler: public Scheduler{

public:

	/* Initializes the FIFO scheduler to not interrupt, or time slice.
	 */
	FIFOScheduler();

	/* Selects the next process to be run in the CPU
	 * Uses the First In First Out algorithm.
	 * @return: pointer to the process to be run next
	 *          returns NULL if empty
	 */
	PCB* schedule(/*ReadyQueue rq*/);

};
#endif
