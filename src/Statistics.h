#ifndef STATISTICS_H
#define STATISTICS_H

#include "simlib.h"
#include "macros.h"
#include "Slope.h"

extern Histogram VisitorInSystem;
extern Histogram NumberOfVisitorsDuringWeekend;
extern Histogram NumberOfVisitorsDuringWorkWeek;
extern Histogram VisitorInQueueWeekend;
extern Histogram VisitorInQueueWorkWeek;
extern Histogram BlueSlopesQueueLength;
extern Histogram RedSlopesQueueLength;
extern Histogram BlackSlopesQueueLength;

void PrintStatistics();

#endif
