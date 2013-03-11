/* IOQueues.h
 * Class for managing the infinite IO Queues
 *
 * EECE 315
 * Group BB4
 */

#ifndef IO_QUEUES_H
#define IO_QUEUES_H
#include <list>
#include "PCB.h"
#include <iostream>

using namespace std;

class IOQueues{

	public:
		// Constructor
		IOQueues();

		// Destructor
		~IOQueues();

		/* Adds the PCB to its own IO queue
	   	 * @param: PCB to be added to IO Queues
		 */
		void insert(PCB* process);

		// Updates time remaining in IO bursts for all PCBs
		void updateTimeRemaining();

		/* Removes one pcb from the IO queues if there are any which are
		 * finished their IO burst. 
		 * **Should be called until returns NULL**
		 *
		 * @return PCB pointer of process done IO. NULL if no processes done.
		 */
		PCB* removeReadyProcess();


	private:

	list<PCB*> mQueue;
	list<PCB*>::iterator i;
};

#endif

