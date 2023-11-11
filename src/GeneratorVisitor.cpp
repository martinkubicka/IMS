#include "GeneratorVisitor.h"



void GeneratorVisitor::Behavior() {
    (void) wind;
    (void)cashDeskOpened;

    int visitorTimeGeneration = 1; // minutes (weekend, sunny, morning)

    if (dayTime != NIGHT) { // visitors not generated at night
        if (!weekend) {
            visitorTimeGeneration += 5;
        }

        if (!sunny) {
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