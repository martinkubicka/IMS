/**
 * @file Statistics.h
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Declaration of statistics.
*/

#ifndef STATISTICS_H
#define STATISTICS_H

#include "simlib.h"
#include "macros.h"
#include "Slope.h"

extern Histogram VisitorInSystem; // Time spent by visitor in system (Hours)
extern Histogram NumberOfVisitorsDuringWeekendNotHolidays; // Number of visitor during weekend day (not holidays)
extern Histogram NumberOfVisitorsDuringWorkWeekNotHolidays; // Number of visitor during work day (not holidays)
extern Histogram NumberOfVisitorsDuringWeekendHolidays; // Number of visitor during weekend day (holidays)
extern Histogram NumberOfVisitorsDuringWorkWeekHolidays; // Number of visitor during work day (holidays)
extern Histogram VisitorInQueueWeekendNotHolidays; // Time spent by visitor in queue during weekend (not holidays) (Minutes)
extern Histogram VisitorInQueueWorkWeekNotHolidays; // Time spent by visitor in queue during work week (not holidays) (Minutes)
extern Histogram VisitorInQueueWeekendHolidays; // Time spent by visitor in queue during weekend (holidays) (Minutes)
extern Histogram VisitorInQueueWorkWeekHolidays; // Time spent by visitor in queue during work week (holidays) (Minutes)
extern Histogram BlueSlopesQueueLength; // Blue slopes queue length
extern Histogram RedSlopesQueueLength; // Red slopes queue length
extern Histogram BlackSlopesQueueLength; // Black slopes queue length

/**
 * @brief Function which prints statistics.
 */
void PrintStatistics();

#endif

/*** End of Statistics.h ***/
