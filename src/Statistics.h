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
#include <iostream>

using namespace std;

extern Histogram VisitorInSystem; // Time spent by visitor in system (Hours)

extern Histogram NumberOfVisitorsDuringWeekendNotHolidays; // Number of visitor during weekend day (not holidays)
extern Histogram NumberOfVisitorsDuringWorkWeekNotHolidays; // Number of visitor during work day (not holidays)
extern Histogram NumberOfVisitorsDuringWeekendHolidays; // Number of visitor during weekend day (holidays)
extern Histogram NumberOfVisitorsDuringWorkWeekHolidays; // Number of visitor during work day (holidays)

extern Histogram VisitorInBlueQueueWeekendNotHolidays; // Time spent by visitor in BLUE slope queue during weekend (not holidays) (Minutes)
extern Histogram VisitorInBlueQueueWorkWeekNotHolidays; // Time spent by visitor in BLUE slope queue during work week (not holidays) (Minutes)
extern Histogram VisitorInBlueQueueWeekendHolidays; // Time spent by visitor in BLUE slope queue during weekend (holidays) (Minutes)
extern Histogram VisitorInBlueQueueWorkWeekHolidays; // Time spent by visitor in BLUE slope queue during work week (holidays) (Minutes)

extern Histogram VisitorInRedQueueWeekendNotHolidays; // Time spent by visitor in RED slope queue during weekend (not holidays) (Minutes)
extern Histogram VisitorInRedQueueWorkWeekNotHolidays; // Time spent by visitor in RED slope queue during work week (not holidays) (Minutes)
extern Histogram VisitorInRedQueueWeekendHolidays; // Time spent by visitor in RED slope queue during weekend (holidays) (Minutes)
extern Histogram VisitorInRedQueueWorkWeekHolidays; // Time spent by visitor in RED slope queue during work week (holidays) (Minutes)

extern Histogram VisitorInBlackQueueWeekendNotHolidays; // Time spent by visitor in BLACK slope queue during weekend (not holidays) (Minutes)
extern Histogram VisitorInBlackQueueWorkWeekNotHolidays; // Time spent by visitor in BLACK slope queue during work week (not holidays) (Minutes)
extern Histogram VisitorInBlackQueueWeekendHolidays; // Time spent by visitor in BLACK slope queue during weekend (holidays) (Minutes)
extern Histogram VisitorInBlackQueueWorkWeekHolidays; // Time spent by visitor in BLACK slope queue during work week (holidays) (Minutes)

extern Histogram BlueSlopesQueueLength; // Blue slopes queue length
extern Histogram RedSlopesQueueLength; // Red slopes queue length
extern Histogram BlackSlopesQueueLength; // Black slopes queue length

/**
 * @brief Function which prints statistics.
 */
void PrintStatistics();

#endif

/*** End of Statistics.h ***/
