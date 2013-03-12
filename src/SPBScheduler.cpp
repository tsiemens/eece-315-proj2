#include "SPBScheduler.h"

SPBScheduler::SPBScheduler(bool doesTimeSlice, int quantumTime, double weightedAverage){
	mDoesTimeSlice = doesTimeSlice;
	mAlpha = weightedAverage;
	mQuantumTime = quantumTime;
	mDoesInterrupt = false;
}

PCB* SPBScheduler::schedule(ReadyQueue *q){
	q->begin();
	PCB* nextProcess = q->getCurrent();
	return nextProcess;
}
