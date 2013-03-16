#ifndef GANTTCHART_H
#define GANTTCHART_H
#include "PCB.h"

using namespace std;

class GanttChart{
	public:
		void draw();
		void ganttTableHeader(vector<PCB*> processes);
		void recordPID(PCB* process);

	private:
		vector<int> PIDs;
		vector<int> cpuPIDs;
};
#endif
