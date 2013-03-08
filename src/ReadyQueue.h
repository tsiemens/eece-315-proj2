/* ReadyQueue.h
 * Class for managing the Ready Queue
 *
 * EECE 315
 * Group BB4
 */

#ifndef _PCB_HPP_
#define _PCB_HPP_
#include <vector>
#include <list>
#include "PCB.h"
#include "Scheduler.h"
#include <iostream>

using namespace std;

class ReadyQueue{

	public:
		// Constructor
		ReadyQueue();

		// Destructor
		~ReadyQueue();

		
		//	@Input: PCB to be added to ready Queue
		void Insert(PCB* process);

		// initialize iterator 
		void begin();

		// get next PCB in ready queue
		PCB* getNext();

		// Updates PCB time variables
		void Update();




	private:

	list<PCB*> mQueue;
	list<PCB*>::iterator i;
};

#endif

