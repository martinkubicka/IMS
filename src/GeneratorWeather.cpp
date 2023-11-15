/**
 * @file GeneratorWeather.cpp
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Definitions of methods of GeneratorWeather class.
*/

#include "GeneratorWeather.h"

bool sunny = true; // defining global var

void GeneratorWeather::SetWind(bool windStatus) {
    wind = windStatus;

    // stopping cable cars if wind is true
    for(auto &slope : BlackSlopesCableCar) {
        if (dayTime != NIGHT) {
            slope.isRunning = !wind;

            if (!slope.isRunning) { // clearing queue if not running
                slope.ClearQueue1();
            }
        }
    }
}

void GeneratorWeather::Behavior() {
    // avoid unused variable warning
    (void)cashDeskOpened;
    
    // generating sunny
    if (Random() <= 0.4) {
        sunny = true;
    } else {
        sunny = false;
    }

    // generating wind
    if (Random() <= 0.5) {
        SetWind(true);
    } else {
        SetWind(false);
    }

    Activate(Time + (6*HOUR));
}

/*** End of GeneratorWeather.cpp ***/
