#include "GeneratorDayTime.h"

void GeneratorDayTime::ActivateSlopes() {
    for (auto &slope : BlueSlopesSkiLift) {
        slope.isRunning = true;
    }

    for (auto &slope : RedSlopesSkiLift) {
        slope.isRunning = true;
    }

    for (auto &slope : RedSlopesCableCar) {
        slope.isRunning = true;
    }

    for(auto &slope : BlackSlopesCableCar) {
        slope.isRunning = true;
    }
}

void GeneratorDayTime::PassivateSlopes() {
    for (auto &slope : BlueSlopesSkiLift) {
        slope.isRunning = false;
    }

    for (auto &slope : RedSlopesSkiLift) {
        slope.isRunning = false;
    }

    for (auto &slope : RedSlopesCableCar) {
        slope.isRunning = false;
    }

    for(auto &slope : BlackSlopesCableCar) {
        slope.isRunning = false;
    }
}

void GeneratorDayTime::Behavior() {
    switch (dayTime)
    {
        case NIGHT: // morning
            dayTime = MORNING;
            ActivateSlopes();
            cashDeskOpened = true;
            Activate(Time + (4*HOUR));
            break;
        
        case MORNING: // lunch
            dayTime = LUNCH;
            Activate(Time + (2*HOUR));
            break;

        case LUNCH: // afternoon
            dayTime = AFTERNOON;
            Activate(Time + (1*HOUR));
            break;
        
        case AFTERNOON: // afternoon desk closed
            dayTime = AFTERNOON_DESK_CLOSED;
            cashDeskOpened = false;
            Activate(Time + (1*HOUR));
            break; 

        case AFTERNOON_DESK_CLOSED: // night
            PassivateSlopes();
            dayTime = NIGHT;
            Activate(Time + (16*HOUR));
            break;
        default:
            break;
    }
}
