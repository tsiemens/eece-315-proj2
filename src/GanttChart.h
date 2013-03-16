/* GanttChart.h
 * Outputs the gantt chart and metrics
 *
 * EECE 315
 * Group BB4
 */
#ifndef GANTTCHART_H
#define GANTTCHART_H
#include "PCB.h"
#include "Logger.h"

using namespace std;

class GanttChart{
	public:
		//Constructor
		GanttChart();

		/* Draw the Gantt chart to stdout and to log file
		 */
		void draw(vector<PCB*> processes);

		/* Record the current process in the CPU
		 */
		void recordPID(PCB* process);

	private:
		/* Set the PIDs for the header of the Gantt
		 */
		void ganttTableHeader(vector<PCB*> processes);

		/*Total waiting time for each process - Total execution time for each process - Average waiting time for the total set of process - Throughput for the total set of processes - The turnaround for the total set of processes*/
		stringstream mSS;	
		const string logFile = "metrics.log";
		Logger mLogger;
		vector<int> PIDs;
		vector<int> cpuPIDs;
};
#endif
