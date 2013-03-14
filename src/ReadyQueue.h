/* ReadyQueue.h
 * Class for managing the Ready Queue
 *
 * EECE 315
 * Group BB4
 */

#ifndef READY_QUEUE_H
#define READY_QUEUE_H
#include <list>
#include "PCB.h"
#include <iostream>

using namespace std;

class ReadyQueue{

	public:
		//	@Input: PCB to be added to ready Queue
		void insert(PCB* process, bool resetPriority);

		// initialize iterator 
		void begin();

		// get next PCB in ready queue
		PCB* getNext();
		
		// get current PCB in ready queue
		PCB* getCurrent();

		// Updates PCB time variables
		void update();

		//Removes pcb from the ready queue if it exists in the ready queue
		void remove(PCB* pcb);
		
		//returns size of ready queue
		int getSize();
	private:
		list<PCB*> mQueue;
		list<PCB*>::iterator i;
};

#endif

