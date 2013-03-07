#ifndef WORKLOAD_PARSER_H
#define WORKLOAD_PARSER_H
#include<string>
#include<fstream>
#include "PCB.h"

using namespace std;

class Workload_Parser{
	public:
		static bool valid_file_name(string filename);
		vector<PCB*> parse_workload(string filename);
	private:
		PCB* parse_line(string line);

		ifstream infile;
};
#endif
