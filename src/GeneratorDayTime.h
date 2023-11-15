/**
 * @file GeneratorDayTime.h
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Declarations of methods of GeneratorDayTime class.
*/

#ifndef GENERATORDAYTIME_H
#define GENERATORDAYTIME_H

#include "simlib.h"
#include "macros.h"
#include "CashDesk.h"
#include "Slope.h"
#include "Statistics.h"

// represent day time
enum DayTime {
    MORNING,
    LUNCH,
    AFTERNOON,
    AFTERNOON_DESK_CLOSED,
    NIGHT
};

// declaration of global variables
extern DayTime dayTime;
extern bool wind;
extern int workingDayNumberOfVisitors;
extern int weekendDayNumberOfVisitors;

/**
 * @class GeneratorDayTime
 * 
 * @brief Class which generates day time.
 */
class GeneratorDayTime: public Event {
    private:
        /**
         * @brief Behavior of generating day time event.
         */
        void Behavior();

        /**
         * @brief Merhod which passivates all slopes.
         */
        void PassivateSlopes();

        /**
         * @brief Method which activates all slopes.
         */
        void ActivateSlopes();
};

#endif

/*** End of GeneratorDayTime.h ***/
