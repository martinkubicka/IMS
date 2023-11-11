#ifndef VISITOR_H
#define VISITOR_H

#include "simlib.h"
#include "macros.h"
#include "CashDesk.h"
#include "GeneratorDayTime.h"
#include "Slope.h"

enum Experience {
    NEWBIE,
    REGULAR,
    EXPERT
};

class Visitor: public Process {
    private:
        Experience experience;

        void Behavior();
        void Ticket();
        bool WhatToDo();
        bool ChoosingActivity(int morningRideProbability, int morningPauseOrHomeProbability,int morningPauseProbalility, int morningHomeProbability,
                                int lunchRideProbability, int lunchPauseOrHomeProbability, int lunchPauseProbalility, int lunchHomeProbability,
                                int afternoonRideProbability, int afternoonPauseOrHomeProbability, int afternoonPauseProbalility, int afternoonHomeProbability,
                                int afternoonCashDeskClosedRideProbability, int afternoonCashDeskClosedPauseOrHomeProbability, int afternoonCashDeskClosedPauseProbalility, int afternoonCashDeskClosedHomeProbability
        );
        void Ride();
        bool Pause(int rideProbability, int homeProbability);
        void Home();
        void ChooseSlopeBasedOnDifficulty(SlopeDifficulty difficulty);
};

#endif
