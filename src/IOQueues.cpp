/* IOQueues.cpp
 * Class for managing the infinite IO Queues
 *
 * EECE 315
 * Group BB4
 */

#include "IOQueues.h"

void IOQueues::insert(PCB* process) {
	mQueue.push_back(process);
}


void IOQueues::updateTimeRemaining(){
	for (i = mQueue.begin(); i != mQueue.end(); i++)
	{
		(*i)->decTimeRemInBurst();
	}
}

PCB* IOQueues::removeReadyProcess(){
	PCB* readyProcess = NULL;
	i = mQueue.begin();
	while( readyProcess == NULL && i != mQueue.end() ){
		//IO bursts are odd
		if( ((*i)->getCurrentBurst() % 2) == 0 ){
			readyProcess = (*i);
			mQueue.erase(i);
		} else{
			i++;
		}
	}
	return readyProcess;
}

int IOQueues::getSize(){
	return mQueue.size();
}
