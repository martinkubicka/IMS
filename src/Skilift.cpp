#include "Skilift.h"

void Skilift::Behavior() {
    (void)cashDeskOpened;
    (void)dayTime;

    for (int i = 0; i < rides; i++) {
        Wait(slope->length/KM_H_5);
    }

    Leave(*slope->lift, 1);
}
