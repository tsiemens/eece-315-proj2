/* CPU.cpp
 * Class for Simulated CPU
 *
 * EECE 315
 * Group B5
 */

#include <iostream>
#include "CPU.h"

int CPU::getStatus(){
        int TimeRemInBurst = mProcess->getTimeRemInBurst();
        if(TimeRemInBurst <= 0){
                mProcessStatus = NOT_RUNNING;
        }else{
                mProcessStatus = RUNNING;
        }
        return mProcessStatus;
}

void CPU::decPCBTime(){
        int TimeRemInBurst = mProcess->getTimeRemInBurst();
        if(TimeRemInBurst == 0){
                return;
        }else if(TimeRemInBurst > 0){
                mProcess->decTimeRemInBurst();
                mProcessStatus = getStatus();
        }else{
                cout<<"Error, time remaining in CPU burst cannot be below 0.";
        }
}

PCB* CPU::getProcess(){
        return mProcess;
}

void CPU::setProcess(PCB *process){
	mProcessStatus = RUNNING;
        mProcess = process;
}
