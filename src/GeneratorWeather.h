#ifndef GENERATORWEATHER_H
#define GENERATORWEATHER_H

#include "simlib.h"
#include "macros.h"
#include "Slope.h"
#include "GeneratorDayTime.h"
#include "Visitor.h"

extern bool sunny;

class GeneratorWeather: public Event {
    private:
        void Behavior();
        void SetWind(bool wind);
};

#endif
