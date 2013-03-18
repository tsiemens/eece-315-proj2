/* GanttChart.cpp
 * Outputs the gantt chart and metrics
 *
 * EECE 315
 * Group BB4
 */

#include "GanttChart.h"
#include<iostream>

GanttChart::GanttChart() 
	: logFile("metrics.log"), mLogger(this->logFile) {}

void GanttChart::ganttTableHeader(vector<PCB*> processes){
	for(unsigned int i = 0; i<processes.size(); i++)
		PIDs.push_back(processes[i]->getPID());
}

void GanttChart::getMetrics(vector<PCB*> processes, int time) {
	float TAWT = 0;
	mSS<<endl<<"Metrics:"<<endl<<endl;
	mSS<<"Total waiting time for each process (CPU cycles):"<<endl;
	for(unsigned int i = 0; i < processes.size(); i++) {
		mSS<<"\tPID "<<PIDs.at(i)<<" : "<<processes.at(i)->getWaitTime()<<endl;
		TAWT += processes.at(i)->getWaitTime();
	}
	TAWT /= processes.size();
	mSS<<endl<<"Total execution time for each process (CPU cycles):"<<endl;
	for(unsigned int i = 0; i < processes.size(); i++) {
		mSS<<"\tPID "<<PIDs.at(i)<<" : "<<processes.at(i)->getTotalExecTime()<<endl;
	}
	mSS<<endl<<"Turnaround time for each process (CPU cycles):"<<endl;
	for(unsigned int i = 0; i < processes.size(); i++){
		mSS<<"\tPID "<<PIDs.at(i)<<" : "<<processes.at(i)->getTurnaroundTime()<<endl;
	}
	mSS<<endl<<"Average waiting time (CPU cyles):\t"<<TAWT<<endl;
	mSS<<endl<<"Throughput (processes per CPU cycle):\t"<<processes.size()/(float)time<<endl;
	mSS<<endl<<"Total turnaround time (CPU cycles):\t"<<time<<endl;
	cout<<mSS.str();
	mLogger.log(mSS);
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
