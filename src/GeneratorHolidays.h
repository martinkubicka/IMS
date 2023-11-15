/**
 * @file GeneratorHolidays.h
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Declaration of GeneratorHolidays class which is responsible for generating holidays.
*/

#ifndef GENERATORHOLIDAYS_H
#define GENERATORHOLIDAYS_H

#include "simlib.h"
#include "macros.h"

/**
 * @enum HolidaysType
 * 
 * @brief Enum which represents type of holidays.
*/
enum HolidaysType {
    NOT_DEFINED,
    CHRISTMAS,
    WILL_BE_AUTHUMN,
    AUTHUMN,
    WILL_BE_EASTER,
    EASTER,
    NO_UPCOMING
};

extern bool holidays; // global variable which indicates if there are holidays or not
extern HolidaysType holidaysType; // global variable which indicates type of holidays in the moment.

/**
 * @class GeneratorWeek
 * 
 * @brief Class which is responsible for generating holidays.
 */
class GeneratorHolidays: public Event {
    private:
        /**
         * @brief Behavior of generating holidays.
         */
        void Behavior();
};

#endif

/*** End of GeneratorHolidays.h ***/
