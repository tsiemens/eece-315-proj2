/* PCB.cpp
 * Class for Process Control Block
 *
 * EECE 315
 * Group BB4
 */

#include "PCB.h"

PCB::PCB(){
	mRelPriority = 0;
	mCurrentBurst = 0;
	mWaitTime = 0;
	mAvPrevBurst = 0;
	mTimeRemInBurst = 0;
}

PCB::~PCB(){
	mBursts.clear();
}

void PCB::setPCB(int pid, int TARQ, int priority, vector<int> bursts){
	mPID = pid;
	mTARQ = TARQ;
	mBasePriority = priority;
	mBursts = bursts;
	
	if( isDone() ){
		mTimeRemInBurst = 0;
	}else{
		mTimeRemInBurst = mBursts[0];
	}
}


int PCB::getPID(){
	return mPID;
}

int PCB::getTARQ(){
	return mTARQ;
}

int PCB::getWaitTime(){
	return mWaitTime;
}

void PCB::incWaitTime(){
	mWaitTime++;
}

int PCB::getPriority(){
	return mBasePriority + mRelPriority;
}

void PCB::resetRelPriority(){
	mRelPriority = 0;
}

void PCB::changeRelPriority(int val){
	mRelPriority += val;
	if(mRelPriority < 0){
		mRelPriority = 0;
	}
}

int PCB::getCurrentBurst(){
	return mCurrentBurst;
}

int PCB::getTimeRemInBurst(){
	return mTimeRemInBurst;
}

bool PCB::decTimeRemInBurst(){
	mTimeRemInBurst--;
	if( mTimeRemInBurst == 0 ){
		mCurrentBurst++;
		if ( (unsigned)mCurrentBurst < mBursts.size() ){
			mTimeRemInBurst = mBursts.at(mCurrentBurst);
		}
		return true;	
	}else{
		return false;
	}
}

bool PCB::isDone(){
	if( mCurrentBurst >= (signed)mBursts.size() ){
		return true;
	}else{
		return false;
	}
}

double PCB::getAvPrevBurst(){
	return mAvPrevBurst;
}

void PCB::updateAvPrevBurst(int lastBurst, double alpha){
	mAvPrevBurst = alpha*lastBurst + (1.0 - alpha)*mAvPrevBurst;
}

int PCB::getTotalExecTime(){
	int total = 0;
	for(unsigned int i = 0; i < mBursts.size(); i++ ){
		total += mBursts[i];
		i++;
	}
	return total;
}

int PCB::getTurnaroundTime(){
	int total = 0;
	for(unsigned int i = 0; i < mBursts.size(); i++){
		total += mBursts[i];
	}
	total += getWaitTime();
	return total;
}
