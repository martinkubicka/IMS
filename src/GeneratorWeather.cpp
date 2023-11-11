#include "GeneratorWeather.h"

void GeneratorWeather::SetWind(bool windStatus) {
    wind = windStatus;

    for (auto &slope : RedSlopesCableCar) {
        if (!slope.isFailure && dayTime != NIGHT) {
            slope.isRunning = !wind;
        }
    }

    for(auto &slope : BlackSlopesCableCar) {
        if (!slope.isFailure && dayTime != NIGHT) {
            slope.isRunning = !wind;
        }
    }

    // TODO vyprazdnit frontu
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