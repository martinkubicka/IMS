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

Histogram VisitorInBlueQueueWeekendNotHolidays("Time spent by visitor in BLUE slope queue during weekend (not holidays) (Minutes)", 0, 5, 60/5);
Histogram VisitorInBlueQueueWorkWeekNotHolidays("Time spent by visitor in BLUE slope queue during work week (not holidays) (Minutes)", 0, 5, 60/5);
Histogram VisitorInBlueQueueWeekendHolidays("Time spent by visitor in BLUE Slope queue during weekend (holidays) (Minutes)", 0, 5, 60/5);
Histogram VisitorInBlueQueueWorkWeekHolidays("Time spent by visitor in BLUE Slope queue during work week (holidays) (Minutes)", 0, 5, 60/5);

Histogram VisitorInRedQueueWeekendNotHolidays("Time spent by visitor in RED slope queue during weekend (not holidays) (Minutes)", 0, 5, 60/5);
Histogram VisitorInRedQueueWorkWeekNotHolidays("Time spent by visitor in RED slope queue during work week (not holidays) (Minutes)", 0, 5, 60/5);
Histogram VisitorInRedQueueWeekendHolidays("Time spent by visitor in RED Slope queue during weekend (holidays) (Minutes)", 0, 5, 60/5);
Histogram VisitorInRedQueueWorkWeekHolidays("Time spent by visitor in RED Slope queue during work week (holidays) (Minutes)", 0, 5, 60/5);

Histogram VisitorInBlackQueueWeekendNotHolidays("Time spent by visitor in BLACK slope queue during weekend (not holidays) (Minutes)", 0, 5, 60/5);
Histogram VisitorInBlackQueueWorkWeekNotHolidays("Time spent by visitor in BLACK slope queue during work week (not holidays) (Minutes)", 0, 5, 60/5);
Histogram VisitorInBlackQueueWeekendHolidays("Time spent by visitor in BLACK Slope queue during weekend (holidays) (Minutes)", 0, 5, 60/5);
Histogram VisitorInBlackQueueWorkWeekHolidays("Time spent by visitor in BLACK Slope queue during work week (holidays) (Minutes)", 0, 5, 60/5);

Histogram BlueSlopesQueueLength("Blue slopes queue length", 0, 5, 100/5);
Histogram RedSlopesQueueLength("Red slopes queue length", 0, 5, 100/5);
Histogram BlackSlopesQueueLength("Black slopes queue length", 0, 5, 100/5);

void PrintStatistics() {
    cout << "========== VISITORS IN SYSTEM ==========" << endl;
    VisitorInSystem.Output();

    cout << "========== NUMBER OF VISITORS ==========" << endl;
    NumberOfVisitorsDuringWeekendNotHolidays.Output();
    NumberOfVisitorsDuringWorkWeekNotHolidays.Output();
    NumberOfVisitorsDuringWeekendHolidays.Output();
    NumberOfVisitorsDuringWorkWeekHolidays.Output();

    cout << "========== BLUE SLOPE QUEUE TIME SPENT ==========" << endl;
    VisitorInBlueQueueWeekendNotHolidays.Output();
    VisitorInBlueQueueWorkWeekNotHolidays.Output();
    VisitorInBlueQueueWeekendHolidays.Output();
    VisitorInBlueQueueWorkWeekHolidays.Output();

    cout << "========== RED SLOPE QUEUE TIME SPENT ==========" << endl;
    VisitorInRedQueueWeekendNotHolidays.Output();
    VisitorInRedQueueWorkWeekNotHolidays.Output();
    VisitorInRedQueueWeekendHolidays.Output();
    VisitorInRedQueueWorkWeekHolidays.Output();

    cout << "========== BLACK SLOPE QUEUE TIME SPENT ==========" << endl;
    VisitorInBlackQueueWeekendNotHolidays.Output();
    VisitorInBlackQueueWorkWeekNotHolidays.Output();
    VisitorInBlackQueueWeekendHolidays.Output();
    VisitorInBlackQueueWorkWeekHolidays.Output();

    cout << "========== QUEUE LENGTH ==========" << endl;
    BlueSlopesQueueLength.Output();
    RedSlopesQueueLength.Output();
    BlackSlopesQueueLength.Output();
}

/*** End of Statistics.cpp ***/
