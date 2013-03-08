/* PCB.h
 * Class for Process Control Block
 *
 * EECE 315
 * Group BB4
 */
#ifndef PCB_H
#define	PCB_H
#include<vector>

using namespace std;

class PCB{

	public:
		//Default Constructor	
		PCB();

		//Destructor
		~PCB();

		 /* @param: pid - the process id
		 * @param: TARQ - time of arrival on queue
		 * @param: priority - the base priority for the process
		 * @param: busrts - a vector containing all the cpu and io bursts
		 */
		void setPCB( int pid, int TARQ, int priority, vector<int> bursts );

		/* @return: the pid for the process
		 */
		int getPID();

		/* @return: the total time the process as been waiting.
		 */
		int getWaitTime();

		/* Increments the time the process has been waiting by 1
		 */
		void incWaitTime();

		/* @return: the net priority of the process (base + aged)
		 */
		int getPriority();

		/* Resets the relative priority of the process to zero
		 */
		void resetRelPriority();

		/* Increments the relative priority of the process
		 * @param: val - the about the aged priority should be changed by
		 *         Accepts negative numbers
		 */
		void changeRelPriority(int val);

		/* @return: the # of the current burst of the process (starts at zero)
		 */
		int getCurrentBurst();

		/* @return: the time remaining on the current burst
		 */
		int getTimeRemInBurst();

		/* Decrements the time remaining in the current burst by 1.
		 * If the current burst has ended, the process is set 
		 * to start the next burst.
		 * @return: true if the current burst is now over, false otherwise
		 */
		bool decTimeRemInBurst();

		/* @return: true if the process has no more bursts, false otherwise.
		 */
		bool isDone();

		/* @return: the average duration of CPU bursts
		 */
		int getAvPrevBurst();

		/* Sets the average burst time for the process
		 * @param: average - the average to set
		 */
		void setAvPrevBurst(int average);

		/* @return: the total time the process will or has spent in CPU burst
		 */
		int getTotalExecTime();

	private:
		int mPID;
		int mTARQ;
		int mWaitTime;
		int mBasePriority;
		int mRelPriority;
		int mCurrentBurst;
		int mTimeRemInBurst;
		int mAvPrevBurst;
		vector <int> mBursts;
};
#endif
