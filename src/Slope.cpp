#include "Slope.h"

Slope BlueSlopesSkiLift[BLUE_SLOPE_SKI_LIFT] = {
    {BLUE, SKI_LIFT, 600},
    {BLUE, SKI_LIFT, 500}
};

Slope RedSlopesSkiLift[RED_SLOPE_SKI_LIFT] = {
    {RED, SKI_LIFT, 1000}
};

Slope BlackSlopesCableCar[BLACK_SLOPE_CABLE_CAR] = {
    {BLACK, CABLE_CAR, 2000}
};

void Slope::ClearQueue1() {
    (void)cashDeskOpened;
    (void)dayTime;

    while (queue.Length() > 0) {
        Visitor* visitor = (Visitor *)queue.GetFirst();
        visitor->interrupted = true;
        visitor->Activate();
    }
}
