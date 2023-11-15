/**
 * @file Repair.cpp
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Definition of methods of Repair class.
*/

#include "Repair.h"

Repair::Repair(Slope* slope): Process(), slope(slope) {}

void Repair::Behavior() {
    // avoid unused variables warnings
    (void)cashDeskOpened;
    (void)dayTime;

    Seize(*slope->facility, 1);

    // note: people using facility have to wait until repaired and then they can continue (Q2)

    Wait(Exponential(HOUR));

    slope->isFailure = false;

    Release(*slope->facility);
}

/*** End of Repair.cpp ***/
