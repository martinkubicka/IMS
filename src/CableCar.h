#ifndef CABLE_CAR_H
#define CABLE_CAR_H

#include "simlib.h"
#include "Slope.h"

class Slope; // forward declaration

class CableCar: public Process {
    public:
        CableCar(int rides, Slope* slope): rides(rides), slope(slope) {}
        void Behavior();
    private:
        int rides;
        Slope* slope;
};

#endif
