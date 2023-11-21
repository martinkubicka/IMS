/**
 * @file GeneratorVisitor.cpp
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Definitions of GeneratorVisitor class.
*/ 

#include "GeneratorVisitor.h"

void GeneratorVisitor::Behavior() {
    // avoid unused parameters warnings
    (void)wind;
    (void)cashDeskOpened;

    int visitorTimeGeneration = 10; // default time in seconds (based on weekend, sunny, morning etc..)

    if (dayTime != NIGHT) { // visitors not being generated at night
        // statistics
        if (weekend && holidays) {
            weekendDayNumberOfVisitorsHolidays++;
        } else if (weekend && !holidays) {
            weekendDayNumberOfVisitorsNotHolidays++;
        } else if (!weekend && holidays) {
            workingDayNumberOfVisitorsHolidays++;
        } else if (!weekend && !holidays) {
            workingDayNumberOfVisitorsNotHolidays++;
        }
        
        if (!holidays) {
            visitorTimeGeneration += 30;
        }

        if (!weekend) { // working day
            visitorTimeGeneration += 12;
        }

        if (!sunny) { // not sunny
            visitorTimeGeneration += 30;
        }

        switch (dayTime)
        {
            case LUNCH:
                visitorTimeGeneration += 60;
                break;

            case AFTERNOON:
                visitorTimeGeneration += 300;
                break;
            
            case AFTERNOON_DESK_CLOSED:
                visitorTimeGeneration += 30*MINUTE;
                break;

            default:
                break;
        }

        (new Visitor)->Activate();
    }

    Activate(Time + Exponential(visitorTimeGeneration));
}

/*** End of GeneratorVisitor.cpp ***/
