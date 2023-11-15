/**
 * @file GeneratorHolidays.cpp
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Definitions of GeneratorHolidays class.
*/ 

#include "GeneratorHolidays.h"

// defining global variable
bool holidays = false;
HolidaysType holidaysType = NOT_DEFINED;

void GeneratorHolidays::Behavior() {    
    switch (holidaysType)
    {
        case NOT_DEFINED:
            holidaysType = CHRISTMAS;
            Activate(Time + 22*DAY); // christmas holidays from 22th of december
            break;

        case CHRISTMAS:
            holidaysType = WILL_BE_AUTHUMN;
            holidays = true;
            Activate(Time + 16*DAY); // until 8th of january
            break;
        
        case WILL_BE_AUTHUMN:
            holidays = false;
            holidaysType = AUTHUMN;
            Activate(Time + 46*DAY); // until 23rd of febraury
            break;

        case AUTHUMN:
            holidaysType = WILL_BE_EASTER;
            holidays = true;
            Activate(Time + 11*DAY); // until 4th of march
            break;
        
        case WILL_BE_EASTER:
            holidays = false;
            holidaysType = EASTER;
            Activate(Time + 24*DAY); // until 28th of march
            break;

        case EASTER:
            holidaysType = NO_UPCOMING;
            holidays = true;
            Activate(Time + 6*DAY); // until 2nd of april
            break;

        case NO_UPCOMING:
            holidays = false;
            break;
    
        default:
            break;
    }

}

/*** End of GeneratorHolidays.cpp ***/
