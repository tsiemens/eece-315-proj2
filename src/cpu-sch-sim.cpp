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
#include "Scheduler.h"
#include "SchedulerFactory.h"
#include "ReadyQueue.h"

int main(){
	using namespace std;

	int algorithmIndex = 0;
	int quantumTime = 0;
	int time = 0;
	WorkloadParser parser;
	vector<PCB*> processes;
	string filename;
	Scheduler* scheduler;
	SchedulerFactory schFactory;
	ReadyQueue readyQueue;
	
	cout<<"Please enter workload file name: ";
	/* for testing smoothness
	do{
		cin>>filename;
	}while(!(WorkloadParser::validFileName(filename)));
	*/
	filename = "workloads/testWorkload1.txt";
	processes = parser.parseWorkload(filename);

	//Get the algorithm to be used
	cout<<endl<<"\t"<<"1) FCFS   2) RR   3) Polite Premptive Priority"<<endl
		      <<"\t"<<"4) Impatient Premptive Priority"<<endl
			  <<"\t"<<"5) Non Premprive Priority   6) SJF   7) SPB"<<endl<<endl;

	while( algorithmIndex < FCFS || algorithmIndex > SPB ){
		cout<<"Select scheduling algorithm:";
		cin>>algorithmIndex;
	}

	if( algorithmIndex != FCFS ){
		while( quantumTime <= 0 ){
			cout<<"Please enter a value for quantum time:";
			cin>>quantumTime;
		}
	}

	scheduler = schFactory.makeScheduler(algorithmIndex, quantumTime);
	readyQueue.begin();

	while(time < 10){
		for(unsigned int i = 0; i < processes.size();i++){
			if(processes[i]->getTARQ() == time)
				readyQueue.insert(processes[i]);
		}
		
		/*Make IO queue*/
		/*Make CPU*/

		/*Check IO queue for done processes*/
		/*Move any to ready queue that are done*/
		
		/*Check if CPU is empty*/
		/*If not empty*/
			/*If done burst*/ 
				/*put into IO queue (if not finished), 
				  then get new process from deady queue*/
			/*If process is not done, but interrupts are on, 
			 and there is a higher priority process*/
				/*Pull from CPU and insert higher priority process*/
			/*If process is not done, and interrupts are off*/
				//Do nothing

		/*Increment wait time on wait queue*/
		/*Decrement time remianing on CPU*/
		/*Decrement time remaining on IO*/

		time++;
	}				

	for(unsigned int i=0; i< processes.size();i++)
		delete processes[i];	

	return 0;
}
