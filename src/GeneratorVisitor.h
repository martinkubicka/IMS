/**
 * @file GeneratorVisitor.h
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Declaration of GeneratorVisitor class used for generating visitors in the system.
*/

#ifndef GENERATORVISITOR_H
#define GENERATORVISITOR_H

#include "simlib.h"
#include "macros.h"
#include "GeneratorWeek.h"
#include "Visitor.h"
#include "GeneratorDayTime.h"
#include "GeneratorWeather.h"

/**
 * @class GeneratorVisitor
 *
 * @brief Class which generates visitors in the system.
 */
class GeneratorVisitor: public Event {
    private:
        /**
         * @brief Behavior of generating visitor event.
         */
        void Behavior();
};

#endif

/*** End of GeneratorVisitor.h ***/
