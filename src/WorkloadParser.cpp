#include<iostream>
#include<sstream>
#include<sys/stat.h>
#include "WorkloadParser.h"

bool WorkloadParser::validFileName(string filename){
	struct stat st_buf;
	
	stat(filename.c_str(), &st_buf);
	
	if(S_ISREG(st_buf.st_mode))
		return true;
	else{
		cout<<"Please enter a valid workload file name: ";	
		return false;
	}
}

vector<PCB*> WorkloadParser::parseWorkload(string filename){
	string line;
	vector<PCB*> processes;
	
	inFile.open(filename.c_str());
	while(getline(inFile, line)){
		processes.push_back(parseLine(line));
	}

	inFile.close();
	return processes;
}

PCB* WorkloadParser::parseLine(string line){
	PCB *process = new PCB;
	string token;
	vector<string> fields;
	vector<int> bursts;
	stringstream ss(line);
	
	while(getline(ss,token,' '))
		fields.push_back(token);

	for(unsigned int i=4; i<fields.size();i++)
		bursts.push_back(stoi(fields[i]));
		
	process->setPCB(stoi(fields[0]), stoi(fields[1]), stoi(fields[2]), bursts);
	return process;
}
