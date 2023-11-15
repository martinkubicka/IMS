/**
 * @file Statistics.cpp
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Definitions of statistics.
*/

#include "Statistics.h"

Histogram VisitorInSystem("Time spent by visitor in system (Hours)", 0, HOUR, 8);
Histogram NumberOfVisitorsDuringWeekend("Number of visitor during weekend day", 0, 500, 10000/500);
Histogram NumberOfVisitorsDuringWorkWeek("Number of visitor during work day", 0, 500, 10000/500);
Histogram VisitorInQueueWeekend("Time spent by visitor in queue during weekend (Minutes)", 0, 5, HOUR/5);
Histogram VisitorInQueueWorkWeek("Time spent by visitor in queue during work week (Minutes)", 0, 5, HOUR/5);
Histogram BlueSlopesQueueLength("Blue slopes queue length", 0, 5, 100/5);
Histogram RedSlopesQueueLength("Red slopes queue length", 0, 5, 100/5);
Histogram BlackSlopesQueueLength("Black slopes queue length", 0, 5, 100/5);

void PrintStatistics() {
    VisitorInSystem.Output();
    NumberOfVisitorsDuringWeekend.Output();
    NumberOfVisitorsDuringWorkWeek.Output();
    VisitorInQueueWeekend.Output();
    VisitorInQueueWorkWeek.Output();
    BlueSlopesQueueLength.Output();
    RedSlopesQueueLength.Output();
    BlackSlopesQueueLength.Output();
}

/*** End of Statistics.cpp ***/
