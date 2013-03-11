/* FIFOScheduler.cpp
 * Scheduler which uses the FIFO algorithm
 *
 * EECE 315
 * Group BB4
 */

#include "FirstScheduler.h"

using namespace std;

FirstScheduler::FirstScheduler(bool doesTimeSlice, int quantumTime){
	mDoesTimeSlice = doesTimeSlice;
	mDoesInterrupt = false;
	mQuantumTime = quantumTime;
	resetTimeSliceTimer();
}

PCB* FirstScheduler::schedule(ReadyQueue* q){
	q->begin();
	PCB* nextProcess = q->getNext();
	if(nextProcess != NULL){
		q->remove(nextProcess);
	}
	return nextProcess;
}

