/**
 * @file GeneratorFailure.cpp
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Definitions of methods of GeneratorFailure class used for generating failures in system.
*/

#include "GeneratorFailure.h"

GeneratorFailure::GeneratorFailure(Slope* slope): Event(), slope(slope) {}

void GeneratorFailure::Behavior() {
    // avoiding unused parameters warnings
    (void)cashDeskOpened;
    (void)dayTime;

    // not running -> not generating failures
    if (slope->isFailure || !slope->isRunning) {
        return;
    }

    slope->isFailure = true;

    // clearing queue 1, people in queue 2 needs to way until they will be freed from ski lift or cable car
    slope->ClearQueue1();

    (new Repair(slope))->Activate();
    Activate(Time + Exponential(7*DAY));
}

/*** End of GeneratorFailure.cpp ***/
