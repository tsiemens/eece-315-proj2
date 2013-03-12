#include "SPBScheduler.h"

SPBScheduler::SPBScheduler(bool doesTimeSlice, int quantumTime, double weightedAverage){
	mDoesTimeSlice = doesTimeSlice;
	mQuantumTime = quantumTime;
}

PCB* SPBScheduler::schedule(ReadyQueue *q){
	q->begin();
	PCB* nextProcess = q->getCurrent();
	return nextProcess;
}
