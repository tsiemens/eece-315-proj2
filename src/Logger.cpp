/* Logger.cpp
 * Logger for program
 *
 * EECE 315
 * Group BB4
 */

#include "Logger.h"
#include <unistd.h>

using namespace std;

Logger::Logger(string filename){
	mStreamOK = true;
	mTime = 0;
	string filePath = getFileDir();
	if(filePath.empty()){
		mStreamOK = false;
	} else{
		filePath += filename;
		setOFStream(filePath);
	}
}

Logger::~Logger(){
	if(mStreamOK){
		mLogFile.close();
	}
}

void Logger::log(stringstream& ss){
	if(!mLogFile || !mStreamOK){
		return;
	}
	mLogFile << ss.str();
	ss.str("");
}


void Logger::logCreateProcess(PCB* process) {
	if(!mLogFile || !mStreamOK){
		return;
	}
	mLogss<<"Time "<<mTime<<"\t:: Creating PID "<<process->getPID() <<endl;
	mLogFile<<mLogss.str();
	mLogss.str("");
}

void Logger::logDoneIoBurst(PCB* process) {
	if(!mLogFile || !mStreamOK){
		return;
	}
	mLogss<<"Time "<<mTime<<"\t:: PID "<<process->getPID()<<
		" finished IO Burst #"<<process->getCurrentBurst() - 1<<
		" - Sending to Ready Queue"<<endl;
	mLogFile<<mLogss.str();
	mLogss.str("");
}

void Logger::logDoneCPUBurst(PCB* process) {
	if(!mLogFile || !mStreamOK){
		return;
	}
	mLogss<<"Time "<<mTime<<"\t:: PID "<<process->getPID()<<
		" finished CPU Burst #"<<process->getCurrentBurst()<<
		" - Sending to IO Queue"<<endl;
	mLogFile<<mLogss.str();
	mLogss.str("");
}

void Logger::logProcessFinished(PCB* process) {
	if(!mLogFile || !mStreamOK){
		return;
	}
	mLogss<<"Time "<<mTime<<"\t:: PID "<<process->getPID()<<
		" finished executing"<<endl;
	mLogFile<<mLogss.str();
	mLogss.str("");
}

void Logger::logTimeSlice(PCB* process) {
	if(!mLogFile || !mStreamOK){
		return;
	}
	mLogss<<"Time "<<mTime<<"\t:: PID "<<process->getPID()<<
		" finished given time slice - Inserting back into Ready Queue"<<endl;
	mLogFile<<mLogss.str();
	mLogss.str("");
}

void Logger::logInterrupt(PCB* higherProcess, PCB* lowerProcess) {
	if(!mLogFile || !mStreamOK){
		return;
	}
	mLogss<<"Time "<<mTime<<"\t:: INTERRUPT :: PID "<<
	higherProcess->getPID()<<" (priority "<<higherProcess->getPriority()
	<<") in the Ready Queue has replaced PID "<<
	lowerProcess->getPID()<<" (priority "<<
	lowerProcess->getPriority()<<") in the CPU"<<endl;
	mLogFile<<mLogss.str();
	mLogss.str("");
}

void Logger::logNextProcess(PCB* process) {
	if(!mLogFile || !mStreamOK){
		return;
	}
	mLogss<<"Time "<<mTime<<"\t:: PID "<<process->getPID()<<
		" (priority "<<process->getPriority()<<") has been placed"
		" in the CPU"<<endl;
	mLogFile<<mLogss.str();
	mLogss.str("");
}

void Logger::incTime(){
	mTime++;
}


string Logger::getFileDir(){
	char dirBuffer[1024];
	string fileDir;
    ssize_t dirLen = readlink("/proc/self/exe", dirBuffer, sizeof(dirBuffer)-1);
    if (dirLen != -1) {
      dirBuffer[dirLen] = '\0';
      fileDir = string(dirBuffer);
    } else {
		cout << "ERROR: could not open log file"<<endl;
		return NULL;
    }
	while(fileDir[fileDir.size()-1] != '/'){
		fileDir = fileDir.substr(0, fileDir.size() - 1);
	}
	fileDir = fileDir.substr(0, fileDir.size() - 1);
	while(fileDir[fileDir.size()-1] != '/'){
		fileDir = fileDir.substr(0, fileDir.size() - 1);
	}
	fileDir += "log/";

	return fileDir;
}

void Logger::setOFStream(string filename){
	mLogFile.open(filename);
	if( !mLogFile.is_open() ){
		cout << "ERROR: could not open log file"<<endl;
		mStreamOK = false;
		return;
	}
}

void Logger::logDone(int time){
	if(!mLogFile || !mStreamOK){
		return;
	}
	mLogss<<"Time "<<time<<"\t:: All Processes completed"<<endl;
	mLogFile<<mLogss.str();
	mLogss.str("");
}



