/**
 * @file GeneratorDayTime.cpp
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Definitions of methods of GeneratorDayTime class used for generating day time in system.
*/

#include "GeneratorDayTime.h"

// defining global variables
DayTime dayTime = NIGHT;
bool wind = false;
int workingDayNumberOfVisitors = 0;
int weekendDayNumberOfVisitors = 0;

void GeneratorDayTime::ActivateSlopes() {
    for (auto &slope : BlueSlopesSkiLift) {
        slope.isRunning = true;
    }

    for (auto &slope : RedSlopesSkiLift) {
        slope.isRunning = true;
    }

    for(auto &slope : BlackSlopesCableCar) {
        slope.isRunning = wind ? false : true;
    }
}

void GeneratorDayTime::PassivateSlopes() {
    for (auto &slope : BlueSlopesSkiLift) {
        slope.isRunning = false;
        slope.ClearQueue1();
    }

    for (auto &slope : RedSlopesSkiLift) {
        slope.isRunning = false;
        slope.ClearQueue1();        
    }

    for(auto &slope : BlackSlopesCableCar) {
        slope.isRunning = false;
        slope.ClearQueue1();
    }
}

void GeneratorDayTime::Behavior() {
    switch (dayTime)
    {
        case NIGHT: // will be morning
            // statistics
            if (weekend) { // weekend
                NumberOfVisitorsDuringWeekend(weekendDayNumberOfVisitors);
                weekendDayNumberOfVisitors = 0;
            } else { // working week
                NumberOfVisitorsDuringWorkWeek(workingDayNumberOfVisitors);
                workingDayNumberOfVisitors = 0;
            }

            dayTime = MORNING;
            ActivateSlopes();
            cashDeskOpened = true;
            Activate(Time + (4*HOUR));
            break;
        
        case MORNING: // will lunch
            dayTime = LUNCH;
            Activate(Time + (2*HOUR));
            break;

        case LUNCH: // will be afternoon
            dayTime = AFTERNOON;
            Activate(Time + (1*HOUR));
            break;
        
        case AFTERNOON: // will afternoon desk closed
            dayTime = AFTERNOON_DESK_CLOSED;
            cashDeskOpened = false;
            Activate(Time + (1*HOUR));
            break; 

        case AFTERNOON_DESK_CLOSED: // will be night
            PassivateSlopes();
            dayTime = NIGHT;
            Activate(Time + (16*HOUR));
            break;

        default:
            break;
    }
}

/*** End of GeneratorDayTime.cpp ***/
