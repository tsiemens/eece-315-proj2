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
#include "FIFOScheduler.h"

enum AlgType { FCFS = 1, RR = 2, PPP = 3, IPP = 4, 
               NPP = 5, SJF = 6, SPB = 7 };

Scheduler* createScheduler(int algIndex);

int main(){
	using namespace std;
	int algorithmIndex = 0;
	WorkloadParser parser;
	vector<PCB*> processes;
	string filename;
	ifstream inFile;
	
	cout<<"Please enter workload file name: ";
	/* for testing smoothness
	do{
		cin>>filename;
	}while(!(WorkloadParser::validFileName(filename)));
	*/
	filename = "workloads/";
	processes = parser.parseWorkload(filename);

	/*Get the algorithm to be used*/
	cout<<endl<<"\t"<<"1) FCFS   2) RR   3) Polite Premptive Priority"<<endl
		      <<"\t"<<"4) Impatient Premptive Priority"<<endl
			  <<"\t"<<"5) Non Premprive Priority   6) SJF   7) SPB"<<endl<<endl;

	while( algorithmIndex < FCFS || algorithmIndex > SPB ){
		cout<<"Select scheduling algorithm:";
		cin>>algorithmIndex;
	}
	Scheduler* scheduler = createScheduler(algorithmIndex);

	/*Make Ready queue*/
	/*Make IO queue*/
	/*Make CPU*/

	/*While not all processes are done*/
		/*Put all new processes in ready queue*/

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
						

	processes.clear();
	return 0;
}


/* Depending on the user input, creates the appropriate scheduler type
 * @param: algIndex - the algorithm. Should be number defined by AlgType
 * @return: pointer to a Scheduler. Null if an error occurs.
 */
Scheduler* createScheduler(int algIndex){
	Scheduler* scheduler;
	switch(algIndex){
		case FCFS:
			scheduler = new FIFOScheduler();
			break;
		//Others here
		default:
			cout<<"Error occured getting algorithm"<<endl;
			scheduler = NULL;
			break;
	}
	return scheduler;
}


