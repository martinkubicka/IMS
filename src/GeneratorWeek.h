#ifndef GENERATORWEEK_H
#define GENERATORWEEK_H

#include "simlib.h"
#include "macros.h"

static bool weekend = true;

class GeneratorWeek: public Event {
    private:
        void Behavior();
};

#endif
