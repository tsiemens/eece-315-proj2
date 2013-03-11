#include "PriorityScheduler.h"
#include <iostream>

using namespace std;


PriorityScheduler::PriorityScheduler(int quantumTime, bool doesInterrupt) {

	mQuantumTime = quantumTime;
	mDoesInterrupt = doesInterrupt;
	resetTimeSliceTimer();
}

// Returns the PCB with the highest priority
PCB* PriorityScheduler::schedule(ReadyQueue* q) {
	PCB* selectedProcess;
	PCB* currentProcess;
	q->begin();
	selectedProcess = q->getCurrent();
	currentProcess = q->getCurrent();
	while (currentProcess != NULL) {
		if ( currentProcess->getPriority() > selectedProcess->getPriority() ) {
			selectedProcess = q->getCurrent();
		}
		currentProcess = q->getNext();
	}
	return selectedProcess;
}





