/* ReadyQueue.cpp
 * Class for managing the Ready Queue
 *
 * EECE 315
 * Group BB4
 */

#include "ReadyQueue.h"

// adds PCB to ready queue and resets rel priority
// @input: PCB* to be added.
void ReadyQueue::insert(PCB* process, bool resetPriority) {
	if (resetPriority)
		process->resetRelPriority();
	mQueue.push_back(process);

}

// @return: initialize iterator
void ReadyQueue::begin() {
	i = mQueue.begin();
}

// get next PCB in ready queue. If none, return NULL;
PCB* ReadyQueue::getNext() {
	i++;
	if (mQueue.empty() || i == mQueue.end()) {
		return NULL;
	}
	PCB* process = *i;
	
	return process;
}

PCB* ReadyQueue::getCurrent() {
	if (mQueue.empty() || i == mQueue.end()) {
		return NULL;
	}
	return *i;

}

// update PCBs in update
void ReadyQueue::update() {

	for (i = mQueue.begin(); i != mQueue.end(); i++)
	{
		(*i)->incWaitTime();
		(*i)->changeRelPriority(1);
	}
}

void ReadyQueue::remove(PCB* pcb) {
	mQueue.remove(pcb);
}

int ReadyQueue::getSize(){
	return mQueue.size();
}

