#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "PCB.h"
#include "Workload_Parser.h"

int main(){
	using namespace std;
	int algorithm_index;
	Workload_Parser parser;
	vector<PCB*> processes;
	string filename;
	ifstream infile;
	
	cout<<"Please enter workload filename: ";
	do{
		cin>>filename;
	}while(!(Workload_Parser::valid_file_name(filename)));

	processes = parser.parse_workload(filename);

	cout<<endl<<"\t"<<"1) FCFS 2) RR 3) Polite Premptive Priority 4) Impatient Premptive Priority 5) Non Premprive Priority 6) SJF 7) SPB"<<endl<<endl;	
	cout<<"Select scheduling algorithm:";
	cin>>algorithm_index;
	
	for(unsigned int i=0; i< processes.size();i++)
		delete processes[i];

	return 0;
}
