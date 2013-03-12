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
		fileDir.pop_back();
	}
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


