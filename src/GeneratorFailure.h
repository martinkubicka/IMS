#ifndef FAILURE_H
#define FAILURE_H

#include "simlib.h"
#include "Visitor.h"
#include "Repair.h"

class GeneratorFailure: public Event {
    public:
        explicit GeneratorFailure(Slope* slope);

    private:
        Slope* slope;
        
        void Behavior();
};


#endif
