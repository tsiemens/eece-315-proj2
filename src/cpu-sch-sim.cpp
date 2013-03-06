/* cpu-sch-sim.cpp
 * Main loop for CPU scheduler
 *
 * EECE 315
 * Group B5
 */

#include<iostream>
#include<fstream>
#include<string>

int main(){
	using namespace std;
	int algorithm_index;
	string filename;
	ifstream infile;

	cout<<"Please enter workload filename:";
	cin>>filename;

	cout<<endl<<"\t"<<"1) FCFS 2) RR 3) Polite Premptive Priority 4) Impatient Premptive Priority 5) Non Premprive Priority 6) SJF 7) SPB"<<endl<<endl;	
	cout<<"Select scheduling algorithm:";
	cin>>algorithm_index;	

	infile.open(filename.c_str());
	if(infile.is_open())
		cout<<"open success"<<endl;
	else
		cout<<"File not found"<<endl;

	infile.close();
	return 0;

}
