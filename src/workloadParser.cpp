#include<iostream>
#include<sstream>
#include "Workload_Parser.h"

bool workloadParser::validFileName(string filename){
	ifstream testFile;

	testFile.open(filename.c_str());
	if(testFile.is_open()){
		testFile.close();
		return true;
	}
	else{
		cout<<"Please enter a valid workload file name: ";
		return false;
	}
}

vector<PCB*> workloadParser::parseWorkload(string filename){
	string line;
	vector<PCB*> processes;
	
	inFile.open(filename.c_str());
	while(getline(inFile, line)){
		processes.push_back(parseLine(line));
	}

	inFile.close();
	return processes;
}

PCB* workloadParser::parseLine(string line){
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
