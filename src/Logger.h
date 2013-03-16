/* Logger.h
 * Logger for program
 *
 * EECE 315
 * Group BB4
 */
#ifndef LOGGER_H
#define	LOGGER_H

#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include"PCB.h"

using namespace std;

class Logger{

	public:
		//Constructor
		Logger(string filename);

		//Destructor
		~Logger();

		//Logs the string in the log file
		void log(stringstream& ss);

		void logCreateProcess(PCB* process);
		void logDoneIoBurst(PCB* process);
		void logDoneCPUBurst(PCB* process);
		void logProcessFinished(PCB* process);
		void logTimeSlice(PCB* process);
		void logInterrupt(PCB* higherProcess, PCB* lowerProcess);
		void logNextProcess(PCB* process);
		void logDone(int time);
		
		void incTime();

	private:
		/*@return: the root file path for the log.
		 *         is in log/ dir from root of project.
		 */
		string getFileDir();

		//Initializes the ofstream to the filename
		void setOFStream(string filename);

		ofstream mLogFile;
		bool mStreamOK;
		int mTime;
		stringstream mLogss;
};
#endif
