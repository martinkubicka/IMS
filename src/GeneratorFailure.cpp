#include "GeneratorFailure.h"

GeneratorFailure::GeneratorFailure(Slope* slope): Event(), slope(slope) {}

void GeneratorFailure::Behavior() {
    (void)cashDeskOpened;
    (void)dayTime;

    if (slope->isFailure || !slope->isRunning) {
        return;
    }

    slope->isFailure = true;

    slope->ClearQueue1();

    (new Repair(slope))->Activate();
    Activate(Time + Exponential(7*DAY));
}
