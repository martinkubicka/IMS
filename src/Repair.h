#ifndef REPAIR_H
#define REPAIR_H

#include "simlib.h"
#include "Visitor.h"

class Repair: public Process {
    public:
        Repair(Slope* Slope);

    private:
        Slope* slope;
        
        void Behavior();
};


#endif
