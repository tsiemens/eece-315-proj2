/* SJFScheduler.cpp
 * Scheduler which uses the SJF algorithm
 *
 * EECE 315
 * Group BB4
 */

#include "SJFScheduler.h"

SJFScheduler::SJFScheduler(bool doesTimeSlice, int quantumTime){
	mDoesTimeSlice = doesTimesSlice;
	mQuantumTime = quantumTime;
	mDoesInterrupt = false;
}

PCB* SJFScheduler::schedule(ReadyQueue* q){
	PCB* currentProcess;
	PCB* selectedProcess;

	//Bring iterator to beginning of ready queue
	q->begin();

	//Intially set current and selected processes to the current process
	currentProcess = q->getCurrent();
	selectedProcss = q->getCurrent();

	//Iterate through the ready queue and find the shortest process
	while(currentProcess != NULL){
		if(currentProcess->getTimeRemInBurst() < selectedProcess->getTimeRemInBurst()){
			selectedProcess = q->getCurrent();
		}
		currentProcess = q->getNext();
	}

	//Remove the shortest process from the ready queue and return it
	q->remove(selectedProcess);
	return selectedProcess;
}
