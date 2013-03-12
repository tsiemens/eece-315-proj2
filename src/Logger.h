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

using namespace std;

class Logger{

	public:
		//Constructor
		Logger(string filename);

		//Destructor
		~Logger();

		//Logs the string in the log file
		void log(stringstream& ss);

	private:
		/*@return: the root file path for the log.
		 *         is the same dir as the executable.
		 */
		string getFileDir();

		//Initializes the ofstream to the filename
		void setOFStream(string filename);

		ofstream mLogFile;
		bool mStreamOK;
};
#endif
