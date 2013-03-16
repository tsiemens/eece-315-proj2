/* GanttChart.cpp
 * Outputs the gantt chart and metrics
 *
 * EECE 315
 * Group BB4
 */

#include "GanttChart.h"
#include<iostream>

GanttChart::GanttChart() 
	: mLogger(this->logFile) {}

void GanttChart::ganttTableHeader(vector<PCB*> processes){
	for(unsigned int i = 0; i<processes.size(); i++)
		PIDs.push_back(processes[i]->getPID());
}

void GanttChart::draw(vector<PCB*> processes){
	ganttTableHeader(processes);

	mSS<<endl<<endl<<"Gantt Chart:"<<endl;
	mSS<<"\t";

	for(unsigned int i = 0; i<PIDs.size(); i++)
		mSS<<"PID:"<<PIDs[i]<<"\t";
	mSS<<endl;

	for(unsigned int i = 0; i<cpuPIDs.size(); i++){
		mSS<<"\t";
		for(unsigned int j = 0; j<PIDs.size(); j++){
			if(PIDs[j] == cpuPIDs[i])
				mSS<<"  X"<<"\t";
			else
				mSS<<"  |"<<"\t";
		}
		mSS<<endl;
	}
	mSS<<endl;
	cout<<mSS.str();
	mLogger.log(mSS);
	
	cout<<"Gantt Chart and metrics can also be viewed in log/"
		<<logFile<<endl;	
}

void GanttChart::recordPID(PCB* process){
	if(process == NULL)
		cpuPIDs.push_back(-1);
	else
		cpuPIDs.push_back(process->getPID());
}
