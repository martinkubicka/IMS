/**
 * @file Slope.cpp
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Definitions of methods and slopes of Slope class.
*/

#include "Slope.h"

// blue slopes
Slope BlueSlopesSkiLift[BLUE_SLOPE_SKI_LIFT] = {
    {BLUE, SKI_LIFT, 600},
    {BLUE, SKI_LIFT, 500}
};

// red slopes
Slope RedSlopesSkiLift[RED_SLOPE_SKI_LIFT] = {
    {RED, SKI_LIFT, 1000}
};

// black slopes
Slope BlackSlopesCableCar[BLACK_SLOPE_CABLE_CAR] = {
    {BLACK, CABLE_CAR, 2000}
};

void Slope::ClearQueue1() {
    // avoid unused variables warnings
    (void)cashDeskOpened;
    (void)dayTime;

    while (queue.Length() > 0) {
        Visitor* visitor = (Visitor *)queue.GetFirst();
        visitor->interrupted = true;
        visitor->Activate();
    }
}

/*** End of Slope.cpp ***/
