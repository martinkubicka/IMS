#ifndef GENERATORDAYTIME_H
#define GENERATORDAYTIME_H

#include "simlib.h"
#include "macros.h"
#include "CashDesk.h"
#include "Slope.h"

enum DayTime {
    MORNING,
    LUNCH,
    AFTERNOON,
    AFTERNOON_DESK_CLOSED,
    NIGHT
};

extern DayTime dayTime;
extern bool wind;

class GeneratorDayTime: public Event {
    private:
        void Behavior();
        void PassivateSlopes();
        void ActivateSlopes();
};

#endif
