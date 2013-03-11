/* CPU.h
 * Class for Simulated CPU
 *
 * EECE 315
 * Group B5
 */

#ifndef CPU_H
#define CPU_H
#include "PCB.h"

static const int RUNNING = 1;
static const int NOT_RUNNING = 0;

using namespace std;

class CPU{

	public:
		//default constructor
		CPU();	
	
		/* Gets the status of the process being checked.
		 * @param: mProcess - the current process being checked
		 * @return:getStatus - the current status of the process
		 *                   - 0 for not running
		 *                   - 1 for currently running
		 */
		int getStatus();

		/* Determine the time remaining in the current CPU burst
		 * and decrement that time if the process is not done.
		 */
		void decPCBTime();

		/* Getter for the current process being checked.
		 * @return: mProcess - the current process being checked
		 */
		PCB * getProcess();

		/* Setter for the current process being checked.Sets
		 * mProcess as the input process to be checked.
		 */
		void setProcess(PCB * process);

	private:
		//insert some private class variables
		PCB *mProcess;
		int mProcessStatus;
};
#endif
