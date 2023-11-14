#ifndef GENERATORWEEK_H
#define GENERATORWEEK_H

#include "simlib.h"
#include "macros.h"

extern bool weekend;

class GeneratorWeek: public Event {
    private:
        void Behavior();
};

#endif
