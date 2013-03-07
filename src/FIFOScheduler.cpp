/* FIFOScheduler.cpp
 * Scheduler which uses the FIFO algorithm
 *
 * EECE 315
 * Group BB4
 */

#include "FIFOScheduler.h"
//#include "ReadyQueue.h"

using namespace std;

FIFOScheduler::FIFOScheduler(){
	mDoesTimeSlice = false;
	mDoesInterrupt = false;
	mQuantumTime = DOES_NOT_TIME_SLICE;
	resetTimeSliceTimer();
}

int FIFOScheduler::schedule(/*ReadyQueue rq*/){
	if(/*Is queue empty?*/true){
		return this->QUEUE_EMPTY;
	}else{
		return 0;
	}
}

