/* PCB.hpp
 * Class for Process Control Block
 *
 * EECE 315
 * Group B5
 */
#include<vector>

using namespace std;

class PCB{

public:
	/*Constructor
	 * @param: pid - the process id
	 * @param: priority - the base priority for the process
	 * @param: busrts - a vector containing all the cpu and io bursts
	 */
	PCB( int pid, int priority, vector<int> bursts );

	//Desctructor
	~PCB();

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

	/* Resets the aged priority of the process to zero
	 */
	void resetPriority();

	/* Increments the aged priority of the process
	 * @param: add - the about the aged priority should be increased by
	 *         Accepts negative numbers
	 */
	void incAgePriority(int add);

	/* @return: the current burst of the process (starts at zero)
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

private:
	int mPID;
	int mWaitTime;
	int mBasePriority;
	int mAgePriority;
	int mCurrentBurst;
	int mTimeRemInBurst;
	vector <int> mBursts;
};
