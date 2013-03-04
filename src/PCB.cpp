/* PCB.cpp
 * Class for Process Control Block
 *
 * EECE 315
 * Group B5
 */

#include <iostream>
#include <string>
#include "PCB.hpp"

using namespace std;

PCB::PCB(int pid, int priority, vector<int> bursts){
	mPID = pid;
	mBasePriority = priority;
	mAgePriority = 0;
	mCurrentBurst = 0;
	mWaitTime = 0;
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
	return mBasePriority + mAgePriority;
}

void PCB::resetPriority(){
	mAgePriority = 0;
}

void PCB::incAgePriority(int add){
	mAgePriority += add;
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
		return true;	
	}else{
		return false;
	}
}

bool PCB::isDone(){
	if( mCurrentBurst >= mBursts.size() ){
		return true;
	}else{
		return false;
	}
}

