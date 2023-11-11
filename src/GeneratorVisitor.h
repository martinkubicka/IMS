#ifndef GENERATORVISITOR_H
#define GENERATORVISITOR_H

#include "simlib.h"
#include "macros.h"
#include "GeneratorWeek.h"
#include "Visitor.h"
#include "GeneratorDayTime.h"
#include "GeneratorWeather.h"

class GeneratorVisitor: public Event {
    private:
        void Behavior();
};

#endif
