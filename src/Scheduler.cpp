/* Scheduler.cpp
 * Abstract class for the schedulers
 *
 * EECE 315
 * Group BB4
 */

#include "Scheduler.h"

using namespace std;

Scheduler::~Scheduler(){}

void Scheduler::setQuantumTime(int qt){
	if( qt < 1 ){
		mQuantumTime = 1;
	}else{
		mQuantumTime = qt;
	}
}

int Scheduler::getQuantumTime(){
	if(!mDoesTimeSlice){
		return this->DOES_NOT_TIME_SLICE;
	}else{
		return mQuantumTime;
	}
}

void Scheduler::setAlpha(double a){
	if(a > 0){
		mAlpha = a;
	}
}

double Scheduler::getAlpha(){
	return mAlpha;
}

bool Scheduler::doesTimeSlice(){
	return mDoesTimeSlice;
}

void Scheduler::setDoesTimeSlice(bool dts){
	mDoesTimeSlice = dts;
}

bool Scheduler::doesInterrupt(){
	return mDoesInterrupt;
}

void Scheduler::setDoesInterrupt(bool di){
	mDoesInterrupt = di;
}

