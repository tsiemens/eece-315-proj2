#include "GanttChart.h"
#include<iostream>

void GanttChart::ganttTableHeader(vector<PCB*> processes){
	for(unsigned int i = 0; i<processes.size(); i++)
		PIDs.push_back(processes[i]->getPID());
}

void GanttChart::draw(){
	cout<<endl<<endl<<"Gantt Chart:"<<endl;
	cout<<"\t";

	for(unsigned int i = 0; i<PIDs.size(); i++)
		cout<<"PID:"<<PIDs[i]<<"\t";
	cout<<endl;

	for(unsigned int i = 0; i<cpuPIDs.size(); i++){
		cout<<"\t";
		for(unsigned int j = 0; j<PIDs.size(); j++){
			if(PIDs[j] == cpuPIDs[i])
				cout<<"  X"<<"\t";
			else
				cout<<"  |"<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;	
}

void GanttChart::recordPID(PCB* process){
	if(process == NULL)
		cpuPIDs.push_back(-1);
	else
		cpuPIDs.push_back(process->getPID());
}
