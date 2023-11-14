#ifndef SKILIFT_H
#define SKILIFT_H

#include "simlib.h"
#include "Slope.h"

class Slope; // forward declaration

class Skilift: public Process {
    public:
        Skilift(int rides, Slope* slope): rides(rides), slope(slope) {}
        void Behavior();
    private:
        int rides;
        Slope* slope;
};

#endif
