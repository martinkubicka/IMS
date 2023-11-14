#include "CableCar.h"

void CableCar::Behavior() {
    (void)cashDeskOpened;
    (void)dayTime;

    for (int i = 0; i < rides; i++) {
        Wait(slope->length/KM_H_5 * 2);
    }

    Leave(*slope->cableCar, 1);
}
