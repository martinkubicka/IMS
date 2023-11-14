#include "GeneratorWeather.h"

bool sunny = true;

void GeneratorWeather::SetWind(bool windStatus) {
    wind = windStatus;

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
    (void)cashDeskOpened;

    if (Random() <= 0.4) {
        sunny = true;
    } else {
        sunny = false;
    }

    if (Random() <= 0.5) {
        SetWind(true);
    } else {
        SetWind(false);
    }

    Activate(Time + (6*HOUR));
}