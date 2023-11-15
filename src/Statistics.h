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
extern Histogram NumberOfVisitorsDuringWeekend; // Number of visitors during weekend
extern Histogram NumberOfVisitorsDuringWorkWeek; // Number of visitors during work week
extern Histogram VisitorInQueueWeekend; // Time spent by visitor in queue during weekend (Minutes)
extern Histogram VisitorInQueueWorkWeek; // Time spent by visitor in queue during work week (Minutes)
extern Histogram BlueSlopesQueueLength; // Blue slopes queue length
extern Histogram RedSlopesQueueLength; // Red slopes queue length
extern Histogram BlackSlopesQueueLength; // Black slopes queue length

/**
 * @brief Function which prints statistics.
 */
void PrintStatistics();

#endif

/*** End of Statistics.h ***/
