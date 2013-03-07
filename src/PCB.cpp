/* PCB.cpp
 * Class for Process Control Block
 *
 * EECE 315
 * Group BB4
 */

#include <iostream>
#include <string>
#include "PCB.h"

using namespace std;

PCB::PCB(int pid, int priority, vector<int> bursts){
	mPID = pid;
	mBasePriority = priority;
	mRelPriority = 0;
	mCurrentBurst = 0;
	mWaitTime = 0;
	mAvPrevBurst = 0;
	mBursts = bursts;

	if( isDone() ){
		mTimeRemInBurst = 0;
	}else{
		mTimeRemInBurst = mBursts[0];
	}
}

PCB::~PCB(){
	mBursts.clear();
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
	for(int i = 0; i < (signed)mBursts.size(); i++ ){
		total += mBursts[i];
		i++;
	}
	return total;
}
