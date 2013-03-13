/* Scheduler.h
 * Abstract class for the schedulers
 *
 * EECE 315
 * Group BB4
 */

#ifndef SCHEDULER_H
#define	SCHEDULER_H

#include "PCB.h"
#include "ReadyQueue.h"

using namespace std;

class Scheduler{

public:
	//destructor
	virtual ~Scheduler();

	/* Selects the next process to be run in the CPU
	 * @return: pointer to the process to be run next.
	 *          should return NULL if the queue is empty.
	 */
	virtual PCB* schedule(ReadyQueue* q) = 0;

	/* @param: value to set the quantum time to. Must be >= 1.
	 */
	void setQuantumTime(int qt);

	/* @return: the value of the quantum time 
	 *          if the scheduler does not implement time slice, it
	 *          returns DOES_NOT_TIME_SLICE
	 */
	int getQuantumTime();

	/* Sets the value for average weighting (defaulted at 0.7)
	 * @param: a - value to be set. must be positive.
	 */
	void setAlpha(double a);

	/* @return: the value for average weighting
	 */
	double getAlpha();

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
	//Returned from getQuantumTime if does not time slice
	static const int DOES_NOT_TIME_SLICE = 0;

protected:
	int mQuantumTime;
	int mTimeSliceTimer;
	double mAlpha;
	bool mDoesTimeSlice;
	bool mDoesInterrupt;
};
#endif
