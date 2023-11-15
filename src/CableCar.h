/**
 * @file CableCar.h
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Declaration of CableCar class which represents cable car.
*/

#ifndef CABLE_CAR_H
#define CABLE_CAR_H

#include "simlib.h"
#include "Slope.h"

class Slope; // forward declaration

/**
 * @class CableCar
 *
 * @brief Represents cable car process.
 */
class CableCar: public Process {
    public:
        /**
         * @brief Constructor of CableCar class.
         * 
         * @param rides number of rides (for example: 1 - only down or 2 - up and down)
         * @param slope pointer to slope where cable car is going
         */
        CableCar(int rides, Slope* slope): rides(rides), slope(slope) {}

        /**
         * @brief Behavior of cable car process.
         */
        void Behavior();
    private:
        int rides; // number of rides (for example: 1 - only down or 2 - up and down)
        Slope* slope; // pointer to slope where cable car is going
};

#endif

/*** End of CableCar.h ***/
