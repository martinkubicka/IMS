/**
 * @file Skilift.h
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Declaration of Skilift class which represents skilift.
*/

#ifndef SKILIFT_H
#define SKILIFT_H

#include "simlib.h"
#include "Slope.h"

class Slope; // forward declaration

/**
 * @class Skilift
 * 
 * @brief Class which represents skilift.
 */
class Skilift: public Process {
    public:
        /**
         * @brief Constructor of Skilift class.
         * 
         * @param rides number of rides (for example: 1 - only down or 2 - up and down)
         * @param slope pointer to slope where skilift is going
         */
        Skilift(int rides, Slope* slope): rides(rides), slope(slope) {}

        /**
         * @brief Behavior of skilift.
         */
        void Behavior();
    private:
        int rides; // number of rides (for example: 1 - only down or 2 - up and down)
        Slope* slope; // ointer to slope where skilift is going
};

#endif

/*** End of Skilift.h ***/
