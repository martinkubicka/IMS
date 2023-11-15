/**
 * @file GeneratorWeek.cpp
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Definitions of GeneratorWeek class.
*/ 

#include "GeneratorWeek.h"

bool weekend = true; // defining global variable

void GeneratorWeek::Behavior() {
    if (weekend) { // working week
        weekend = false;
        Activate(Time + (5*DAY));
    } else { // weekend
        weekend = true;
        Activate(Time + (2*DAY));
    }
}

/*** End of GeneratorWeek.cpp ***/
