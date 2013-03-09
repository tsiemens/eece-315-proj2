#include "ReadyQueue.h"

// Constructor
ReadyQueue::ReadyQueue() {}

// Destructor
ReadyQueue::~ReadyQueue() {
	mQueue.~list();
}

// adds PCB to ready queue and resets rel priority
// @input: PCB* to be added.
void ReadyQueue::insert(PCB* process) {
	process->resetRelPriority();
	mQueue.push_back(process);

}

// @return: initialize iterator
void ReadyQueue::begin() {
	i = mQueue.begin();
}

// get next PCB in ready queue. If none, return NULL;
PCB* ReadyQueue::getNext() {
	if (mQueue.empty() || i == mQueue.end()) {
		return NULL;
	}
	PCB* process = *i;
	i++;
	return process;
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
	i = mQueue.begin();
	bool found = false;
	while( i != mQueue.end() || !found )
	{
		if((*i) == pcb){
			mQueue.erase(i);
			found = true;
		}
	}
}


