#include "Repair.h"

Repair::Repair(Slope* slope): Process(), slope(slope) {}

void Repair::Behavior() {
    (void)cashDeskOpened;
    (void)dayTime;

    Seize(*slope->facility, 1);

    // people using facility have to wait until repaired and then they can continue (Q2)

    Wait(Exponential(HOUR));

    slope->isFailure = false;

    Release(*slope->facility);
}
