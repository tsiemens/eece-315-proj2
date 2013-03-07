/* Scheduler.h
 * Abstract class for the schedulers
 *
 * EECE 315
 * Group BB4
 */

#ifndef SCHEDULER_H
#define	SCHEDULER_H

using namespace std;

class Scheduler{

	//Default Constructor
protected: Scheduler();

public:
	/* Selects the next process to be run in the CPU
	 * @return: the index in the ready queue of the process to be run next.
	 *          should return -1 if the queue is empty.
	 */
	virtual int schedule(/*ReadyQueue rq*/) = 0;

	/* @param: value to set the quantum time to. Must be >= 1.
	 */
	void setQuantumTime(int qt);

	/* @return: the value of the quantum time 
	 *          if the scheduler does not implement time slice, it
	 *          returns DOES_NOT_TIME_SLICE
	 */
	int getQuantumTime();

	/* Sets the time slice timer back to the quantum time
	 */
	void resetTimeSliceTimer();

	/* Decrements the time slice timer, then returns the value.
	 * @return: the time remaining in the time slice
	 */
	int decTimeSliceTimer();

	/* @return: does the scheduler perform time slices
	 */
	bool doesTimeSlice();

	/* @param: if the scheduler should perform time slices
	 */
	void setDoesTimeSlice(bool dts);

	/* @return: does the scheduler perform interrupts
	 */
	bool doesInterrupt();

	/* @param if the scheduler should perform interrupts
	 */
	void setDoesInterrupt(bool di);

	/*Constants*/

	//Returned from schedule if queue is empty
	static const int QUEUE_EMPTY = -1;
	//Returned from getQuantumTime if does not time slice
	static const int DOES_NOT_TIME_SLICE = 0;

protected:
	int mQuantumTime;
	int mTimeSliceTimer;
	bool mDoesTimeSlice;
	bool mDoesInterrupt;
};
#endif
