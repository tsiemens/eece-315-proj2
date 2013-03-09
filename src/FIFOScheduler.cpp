/* FIFOScheduler.cpp
 * Scheduler which uses the FIFO algorithm
 *
 * EECE 315
 * Group BB4
 */

#include "FIFOScheduler.h"

using namespace std;

FIFOScheduler::FIFOScheduler(){
	mDoesTimeSlice = false;
	mDoesInterrupt = false;
	mQuantumTime = DOES_NOT_TIME_SLICE;
	resetTimeSliceTimer();
}

PCB* FIFOScheduler::schedule(ReadyQueue* q){
	q->begin();
	PCB* nextProcess = q->getNext();
	if(nextProcess != NULL){
		q->remove(nextProcess);
	}
	return nextProcess;
}

