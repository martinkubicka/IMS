#ifndef GENERATORWEATHER_H
#define GENERATORWEATHER_H

#include "simlib.h"
#include "macros.h"
#include "Slope.h"
#include "GeneratorDayTime.h"

static bool sunny = true;
static bool wind = false;

class GeneratorWeather: public Event {
    private:
        void Behavior();
        void SetWind(bool wind);
};

#endif
