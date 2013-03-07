#include<iostream>
#include<sstream>
#include "Workload_Parser.h"

bool Workload_Parser::valid_file_name(string filename){
	ifstream testfile;

	testfile.open(filename.c_str());
	if(testfile.is_open()){
		testfile.close();
		return true;
	}
	else{
		cout<<"Please enter a valid workload file name: ";
		return false;
	}
}

vector<PCB*> Workload_Parser::parse_workload(string filename){
	string line;
	vector<PCB*> processes;
	
	infile.open(filename.c_str());
	while(getline(infile, line)){
		processes.push_back(parse_line(line));
	}

	infile.close();
	return processes;
}

PCB* Workload_Parser::parse_line(string line){
	PCB *process = new PCB;
	string token;
	vector<string> fields;
	vector<int> bursts;
	stringstream ss(line);
	
	while(getline(ss,token,' '))
		fields.push_back(token);

	for(unsigned int i=4; i<fields.size();i++)
		bursts.push_back(stoi(fields[i]));
		
	process->setPCB(stoi(fields[0]), stoi(fields[1]), stoi(fields[2]), stoi(fields[3]), bursts);
	return process;
}
