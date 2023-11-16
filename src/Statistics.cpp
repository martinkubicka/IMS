/**
 * @file Statistics.cpp
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Definitions of statistics.
*/

#include "Statistics.h"

Histogram VisitorInSystem("Time spent by visitor in system (Hours)", 0, 1, 8);
Histogram NumberOfVisitorsDuringWeekendNotHolidays("Number of visitor during weekend day (not holidays)", 0, 500, 10000/500);
Histogram NumberOfVisitorsDuringWorkWeekNotHolidays("Number of visitor during work day (not holidays)", 0, 500, 10000/500);
Histogram NumberOfVisitorsDuringWeekendHolidays("Number of visitor during weekend day (holidays)", 0, 500, 10000/500);
Histogram NumberOfVisitorsDuringWorkWeekHolidays("Number of visitor during work day (holidays)", 0, 500, 10000/500);
Histogram VisitorInQueueWeekendNotHolidays("Time spent by visitor in queue during weekend (not holidays) (Minutes)", 0, 5, 60/5);
Histogram VisitorInQueueWorkWeekNotHolidays("Time spent by visitor in queue during work week (not holidays) (Minutes)", 0, 5, 60/5);
Histogram VisitorInQueueWeekendHolidays("Time spent by visitor in queue during weekend (holidays) (Minutes)", 0, 5, 60/5);
Histogram VisitorInQueueWorkWeekHolidays("Time spent by visitor in queue during work week (holidays) (Minutes)", 0, 5, 60/5);
Histogram BlueSlopesQueueLength("Blue slopes queue length", 0, 5, 100/5);
Histogram RedSlopesQueueLength("Red slopes queue length", 0, 5, 100/5);
Histogram BlackSlopesQueueLength("Black slopes queue length", 0, 5, 100/5);

void PrintStatistics() {
    VisitorInSystem.Output();
    NumberOfVisitorsDuringWeekendNotHolidays.Output();
    NumberOfVisitorsDuringWorkWeekNotHolidays.Output();
    NumberOfVisitorsDuringWeekendHolidays.Output();
    NumberOfVisitorsDuringWorkWeekHolidays.Output();
    VisitorInQueueWeekendNotHolidays.Output();
    VisitorInQueueWorkWeekNotHolidays.Output();
    VisitorInQueueWeekendHolidays.Output();
    VisitorInQueueWorkWeekHolidays.Output();
    BlueSlopesQueueLength.Output();
    RedSlopesQueueLength.Output();
    BlackSlopesQueueLength.Output();
}

/*** End of Statistics.cpp ***/
