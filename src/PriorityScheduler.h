#include "PCB.h"
#include "Scheduler.h"
#include <iostream>
#include <list>

#ifndef _PRIORITYSCHEDULER_H
#define _PRIORITYSCHEDULER_H

using namespace std;

class PriorityScheduler : public Scheduler {

public:
	
	PriorityScheduler(int quantumTime, bool doesInterrupt);

	PCB* schedule(ReadyQueue* q); 
};

#endif
