#ifndef VISITOR_H
#define VISITOR_H

#include "simlib.h"
#include "macros.h"
#include "CashDesk.h"
#include "GeneratorDayTime.h"
#include "SlopeEnums.h"
#include "Slope.h"
#include "Skilift.h"
#include "CableCar.h"

enum Experience {
    NEWBIE,
    REGULAR,
    EXPERT
};

class Slope; // forward declaration

class Visitor: public Process {
    public:
        bool interrupted = false;

    private:
        Experience experience;
        int shortestQueueOfChoosedCableCar = 0;

        void Behavior();
        void Ticket();
        void WhatToDo();
        void ChoosingActivity(double morningRideProbability, double morningPauseOrHomeProbability, double morningPauseProbalility, double morningHomeProbability,
                                double lunchRideProbability, double lunchPauseOrHomeProbability, double lunchPauseProbalility, double lunchHomeProbability,
                                double afternoonRideProbability, double afternoonPauseOrHomeProbability, double afternoonPauseProbability, double afternoonHomeProbability,
                                double afternoonCashDeskClosedRideProbability, double afternoonCashDeskClosedPauseOrHomeProbability, double afternoonCashDeskClosedPauseProbability, double afternoonCashDeskClosedHomeProbability
        );
        void Ride();
        void Pause(double rideProbability, double homeProbability);
        void Home();
        void GoUp(Slope *slope);
        Slope* ChooseSlopeBasedOnDifficulty(SlopeDifficulty difficulty);
        SlopeDifficulty ChooseSlopeColorBasedOnExperience();

};

#endif
