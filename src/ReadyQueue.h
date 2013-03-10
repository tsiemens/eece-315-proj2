/* ReadyQueue.h
 * Class for managing the Ready Queue
 *
 * EECE 315
 * Group BB4
 */

#ifndef READY_QUEUE_H
#define READY_QUEUE_H
#include <vector>
#include <list>
#include "PCB.h"
#include <iostream>

using namespace std;

class ReadyQueue{

	public:
		// Constructor
		ReadyQueue();

		// Destructor
		~ReadyQueue();

		
		//	@Input: PCB to be added to ready Queue
		void insert(PCB* process);

		// initialize iterator 
		void begin();

		// get next PCB in ready queue
		PCB* getNext();

		// Updates PCB time variables
		void update();

		//Removes pcb from the ready queue if it exists in the ready queue
		void remove(PCB* pcb);


	private:

	list<PCB*> mQueue;
	list<PCB*>::iterator i;
};

#endif

