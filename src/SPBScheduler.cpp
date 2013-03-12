#include "SPBScheduler.h"

SPBScheduler::SPBScheduler(bool doesTimeSlice, int quantumTime, double weightedAverage){
	mDoesTimeSlice = doesTimeSlice;
	mAlpha = weightedAverage;
	mQuantumTime = quantumTime;
	mDoesInterrupt = false;
}

PCB* SPBScheduler::schedule(ReadyQueue *q){
	PCB* selectedProcess;
	PCB* currentProcess;
	q->begin();
	selectedProcess = q->getCurrent();
	currentProcess = q->getCurrent();
	while (currentProcess != NULL) {
		if ( currentProcess->getAvPrevBurst() < selectedProcess->getAvPrevBurst() ) {
			selectedProcess = q->getCurrent();
		}		
		currentProcess = q->getNext();
	}
	q->remove(selectedProcess);
	return selectedProcess;
}
