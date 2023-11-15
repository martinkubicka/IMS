/**
 * @file GeneratorFailure.h
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Declaration of GeneratorFailure class used for generating failures in system.
*/

#ifndef FAILURE_H
#define FAILURE_H

#include "simlib.h"
#include "Visitor.h"
#include "Repair.h"

/**
 * @class GeneratorFailure
 *
 * @brief Class which generates failures in the system.
 */
class GeneratorFailure: public Event {
    public:
        /**
         * @brief Constructor of GeneratorFailure class.
         * 
         * @param slope pointer to slope on which failure will be generated
         */
        GeneratorFailure(Slope* slope);

    private:
        Slope* slope; // pointer to slope on which failure will be generated
        
        /**
         * @brief Behavior of generating failure event.
         */
        void Behavior(); 
};

#endif

/*** End of GeneratorFailure.h ***/
