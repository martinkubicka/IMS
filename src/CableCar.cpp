/**
 * @file CableCar.cpp
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Definition of methods of CableCar class.
*/

#include "CableCar.h"

void CableCar::Behavior() {
    // avoid unused warnings
    (void)cashDeskOpened;
    (void)dayTime;

    // going down or up
    for (int i = 0; i < rides; i++) {
        Wait(slope->length/KM_H_5 * 2);
    }

    Leave(*slope->cableCar, 1);
}

/*** End of CableCar.cpp ***/
