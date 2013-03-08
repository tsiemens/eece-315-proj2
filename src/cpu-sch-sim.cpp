/* cpu-sch-sim.cpp
 * Main loop for CPU scheduler
 *
 * EECE 315
 * Group BB4
 */

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "PCB.h"
#include "WorkloadParser.h"

int main(){
	using namespace std;
	int algorithm_index;
	WorkloadParser parser;
	vector<PCB*> processes;
	string filename;
	ifstream inFile;
	
	cout<<"Please enter workload file name: ";
	do{
		cin>>filename;
	}while(!(WorkloadParser::validFileName(filename)));

	processes = parser.parseWorkload(filename);

	cout<<endl<<"\t"<<"1) FCFS 2) RR 3) Polite Premptive Priority 4) Impatient Premptive Priority 5) Non Premprive Priority 6) SJF 7) SPB"<<endl<<endl;	
	cout<<"Select scheduling algorithm:";
	cin>>algorithm_index;
	
	for(unsigned int i=0; i< processes.size();i++)
		delete processes[i];

	return 0;
}
