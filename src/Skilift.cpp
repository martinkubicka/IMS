/**
 * @file Skilift.cpp
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Definition of methods of Skilift class.
*/

#include "Skilift.h"

void Skilift::Behavior() {
    // avoid unused variables warnings
    (void)cashDeskOpened;
    (void)dayTime;

    for (int i = 0; i < rides; i++) {
        Wait(slope->length/KM_H_5);
    }

    Leave(*slope->lift, 1);
}

/*** End of Skilift.cpp ***/
