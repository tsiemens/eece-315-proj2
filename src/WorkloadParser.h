#ifndef WORKLOAD_PARSER_H
#define WORKLOAD_PARSER_H
#include<string>
#include<fstream>
#include "PCB.h"

using namespace std;

class WorkloadParser{
	public:
		static bool validFileName(string filename);
		vector<PCB*> parseWorkload(string filename);
	private:
		PCB* parseLine(string line);

		ifstream inFile;
};
#endif
