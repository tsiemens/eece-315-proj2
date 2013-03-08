/* PCB.cpp
 * Class for Process Control Block
 *
 * EECE 315
 * Group B5
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
		mTimeRemInBurst = mBursts[mCurrentBurst];
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

int PCB::getAvPrevBurst(){
	return mAvPrevBurst;
}

void PCB::setAvPrevBurst(int average){
	mAvPrevBurst = average;
}

int PCB::getTotalExecTime(){
	int total = 0;
	for(unsigned int i = 0; i < mBursts.size(); i++ ){
		total += mBursts[i];
		i++;
	}
	return total;
}
