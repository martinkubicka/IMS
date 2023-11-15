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

    int visitorTimeGeneration = 1; // minutes (based on weekend, sunny, morning etc..)

    if (dayTime != NIGHT) { // visitors not being generated at night
        if (!weekend) { // working day
            workingDayNumberOfVisitors++; // statistics
            visitorTimeGeneration += 5;
        } else {
            weekendDayNumberOfVisitors++; // statistics
        }

        if (!sunny) { // not sunny
            visitorTimeGeneration += 5;
        }

        switch (dayTime)
        {   
            case LUNCH:
                visitorTimeGeneration += 10;
                break;

            case AFTERNOON:
                visitorTimeGeneration += 20;
                break;
            
            case AFTERNOON_DESK_CLOSED:
                visitorTimeGeneration += 30;
                break;

            default:
                break;
        }

        (new Visitor)->Activate();
    }

    Activate(Time + Exponential(visitorTimeGeneration));
}

/*** End of GeneratorVisitor.cpp ***/
