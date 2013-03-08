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

using namespace std;

class ReadyQueue{

	public:
		// Default Constructor
		ReadyQueue(Scheduler* scheduler);

		// Destructor
		~ReadyQueue();

		
		//	@Input: PCB to be added to ready Queue
		//	@Output: If preemtive with immediate switch, 
		PCB* Insert(PCB* process);

		// @return: PCB the scheduler removes and return from Queue. 
		PCB* Get() const;

		// Updates PCB time variables
		void Update();




	private:

	list<PCB*> mQueue;
	Scheduler* mScheduler;
	bool mDoesInterrupt;
};

