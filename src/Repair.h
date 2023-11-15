/**
 * @file Repair.h
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Declaration of Repair class which represents repair of skilift or cable car.
*/

#ifndef REPAIR_H
#define REPAIR_H

#include "simlib.h"
#include "Visitor.h"

/**
 * @class Repair
 * 
 * @brief Class which represents repair of skilift or cable car.
 */
class Repair: public Process {
    public:
        /**
         * @brief Constructor of Repair class.
         * 
         * @param Slope pointer to slope which needs to be repaired
         */
        Repair(Slope* Slope);

    private:
        Slope* slope; // pinter to slope which needs to be repaired
        
        /**
         * @brief Behavior of repair process.
         */
        void Behavior();
};

#endif

/*** End of Repair.h ***/
