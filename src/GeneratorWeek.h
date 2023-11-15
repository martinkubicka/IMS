/**
 * @file GeneratorWeek.h
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Declaration of GeneratorWeek class which is responsible for changing between work days and weekend.
*/

#ifndef GENERATORWEEK_H
#define GENERATORWEEK_H

#include "simlib.h"
#include "macros.h"

extern bool weekend; // global variable which indicates if it is weekend or not

/**
 * @class GeneratorWeek
 * 
 * @brief Class which is responsible for changing between work days and weekend.
 */
class GeneratorWeek: public Event {
    private:
        /**
         * @brief Behavior of generating week event.
         */
        void Behavior();
};

#endif

/*** End of GeneratorWeek.h ***/
