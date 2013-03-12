#include "PCB.h"
#include "Scheduler.h"
#include <iostream>
#include <list>

#ifndef PRIORITY_SCHEDULER_H
#define PRIORITY_SCHEDULER_H

using namespace std;

class PriorityScheduler : public Scheduler {

public:
	
	PriorityScheduler(int quantumTime, bool doesInterrupt, bool doesTimeSlice);

	PCB* schedule(ReadyQueue* q); 
};

#endif
