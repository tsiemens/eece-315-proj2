/* FIFOScheduler.h
 * Scheduler which uses the FIFO algorithm
 *
 * EECE 315
 * Group B5
 */

#ifndef FIFO_SCHEDULER_H
#define	FIFO_SCHEDULER_H

#include "Scheduler.h"

using namespace std;

class FIFOScheduler: public Scheduler{

public:

	/* Initializes the FIFO scheduler to not interrupt, or time slice.
	 */
	FIFOScheduler();

	/* Selects the next process to be run in the CPU
	 * Uses the First In First Out algorithm.
	 * @return: the index in the ready queue of the process to be run next
	 *          returns QUEUE_EMPTY if empty
	 */
	int schedule(/*ReadyQueue rq*/);

};
#endif
