/**
 * @file Visitor.cpp
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Declaration of Visitor class and class methods.
*/

#include "Visitor.h"

void Visitor::Ticket() {
    if (Random() <= 0.4 && !cashDeskOpened) { // ticket not bought online
        int shortestQueue = 0;
        for (int i = 0; i < CASHDESK; i++) { // choosing the shortest queue
            if (CashDesk[i].QueueLen() < CashDesk[shortestQueue].QueueLen()) {
                shortestQueue = i;
            }
        }

        Seize(CashDesk[shortestQueue]);
        Wait(Exponential(3)); // buying a ticket
        Release(CashDesk[shortestQueue]);
    }
}

Slope* Visitor::ChooseSlopeBasedOnDifficulty(SlopeDifficulty difficulty) {
    Slope* choosedSlope = nullptr;
    int shortestQueue;

    switch(difficulty) {
        case BLACK:
            shortestQueue = 0;
            for (int i = 0; i < BLACK_SLOPE_CABLE_CAR; i++) {
                for (int j = 0; j < SEATS_IN_CABLE_CAR; j++) {
                    if (BlackSlopesCableCar[i].isRunning && !BlackSlopesCableCar[i].isFailure && BlackSlopesCableCar[i].platformCableCar[j].QueueLen() <= BlackSlopesCableCar[shortestQueue].platformCableCar[shortestQueueOfChoosedCableCar].QueueLen()) {
                        shortestQueue = i;
                        shortestQueueOfChoosedCableCar = j;
                        choosedSlope = &BlackSlopesCableCar[i];
                    }
                }
            }

            if (choosedSlope != nullptr) {
                break;
            }
            
            [[fallthrough]];

        case RED:
            shortestQueue = 0;
            for (int i = 0; i < RED_SLOPE_SKI_LIFT; i++) {
                if (RedSlopesSkiLift[i].isRunning && !RedSlopesSkiLift[i].isFailure && RedSlopesSkiLift[i].facility->QueueLen() <= RedSlopesSkiLift[shortestQueue].facility->QueueLen()) {
                    shortestQueue = i;
                    choosedSlope = &RedSlopesSkiLift[i];
                }
            }

            if (choosedSlope != nullptr) {
                break;
            }

            [[fallthrough]];

        case BLUE:
            shortestQueue = 0;
            for (int i = 0; i < BLUE_SLOPE_SKI_LIFT; i++) {
                if (BlueSlopesSkiLift[i].isRunning && !BlueSlopesSkiLift[i].isFailure && BlueSlopesSkiLift[i].facility->QueueLen() <= BlueSlopesSkiLift[shortestQueue].facility->QueueLen()) {
                    shortestQueue = i;
                    choosedSlope = &BlueSlopesSkiLift[i];
                }
            }

            if (choosedSlope != nullptr) {
                break;
            }
            
            [[fallthrough]];

        default:
            break;
    }

    return choosedSlope;

}

SlopeDifficulty Visitor::ChooseSlopeColorBasedOnExperience() {
    switch(this->experience) { // choosing slope based on experience
        case NEWBIE:
            if (Random() <= 0.5) { // hard slope
                return BLACK;
            } else { // medium or easy slope
                if (Random() <= 0.1) { // medium slope
                    return RED;
                } else { // easy slope
                    return BLUE;
                }
            }

            break;

        case REGULAR:
            if (Random() <= 0.4) { // hard slope
                return BLACK;
            } else { // medium or easy slope
                if (Random() <= 0.3) { // easy slope
                    return BLUE;
                } else { // medium slope
                    return RED;
                }
            }
            break;
        
        case EXPERT:
            if (Random() <= 0.3) { // medium or easy slope
                if (Random() <= 0.2) { // easy slope
                    return BLUE;
                } else { // medium slope
                    return RED;
                }
            } else { // hard slope
                return BLACK;
            }
            break;
        
        default:
            return BLUE; // warning
            break;
    }
}

void Visitor::Pause(double rideProbability, double homeProbability) {
    Wait(Uniform(1, 5)); // choosing restaurant and going there
    Wait(Uniform(10, 40)); // eating
    Wait(Uniform(1, 5)); // going back to ski area

    // cant go to pause again after pause
    if (rideProbability < homeProbability) {
        if (Random() <= rideProbability) {
            Ride();
        } else {
            Home();
        }
    } else {
        if (Random() <= homeProbability) {
            Home();
        } else {
            Ride();
        }
    }
}

void Visitor::Ride() {
    SlopeDifficulty difficulty = ChooseSlopeColorBasedOnExperience();
    Slope* slope = ChooseSlopeBasedOnDifficulty(difficulty);

    if (slope == nullptr) {
        Pause(0.8, 0.2);
        return;
    }

    GoUp(slope);
   
    switch(experience) { // speed of ride based on experience
        case EXPERT:
            Wait(Uniform(slope->length/EXPERT_SPEED - 1, slope->length/EXPERT_SPEED + 1));
            break;
        
        case REGULAR:
            Wait(Uniform(slope->length/REGULAR_SPEED - 1, slope->length/REGULAR_SPEED + 1));
            break;
        
        case NEWBIE:
            Wait(Uniform(slope->length/NEWBIE_SPEED - 1, slope->length/NEWBIE_SPEED + 1));
            break;
        
        default:
            break;
    }

    WhatToDo();
}

void Visitor::GoUp(Slope *slope) {
    double inQueue = Time;

    if (slope->difficulty == BLUE) {
        BlueSlopesQueueLength(slope->facility->QueueLen());
    } else if (slope->difficulty == RED) {
        RedSlopesQueueLength(slope->facility->QueueLen());
    } else {
        BlackSlopesQueueLength(slope->platformCableCar[shortestQueueOfChoosedCableCar].QueueLen());
    }

    if (slope->type == SKI_LIFT) {
        Seize(*slope->facility); // platform

        if (weekend && holidays) {
            VisitorInQueueWeekendHolidays(Time - inQueue);
        } else if (weekend && !holidays) {
            VisitorInQueueWeekendNotHolidays(Time - inQueue);
        } else if (!weekend && holidays) {
            VisitorInQueueWorkWeekHolidays(Time - inQueue);
        } else if (!weekend && !holidays) {
            VisitorInQueueWorkWeekNotHolidays(Time - inQueue);
        }

        Wait(0.08); // 5 seconds 0.08
        if (interrupted) {
            Ride();
            return;
        }

        tryagainSkiLift:

        Enter(*slope->lift, 1); // skilift
        
        if (Random() <= 0.1) { // fail when trying to catch skilift
            (new Skilift(2, slope))->Activate();
            goto tryagainSkiLift;
        }

        Release(*slope->facility);
        Wait(slope->length/KM_H_5);
        
        (new Skilift(1, slope))->Activate();
    } else {
        Seize(*slope->platformCableCar[shortestQueueOfChoosedCableCar]);
        Wait(0.16); // 10 seconds 0.16

        if (interrupted) {
            Ride();
            return;
        }

        tryagainCableCar:

        Enter(*slope->cableCar, 1); // cable car
        if (Random() <= 0.1) { // fail when trying to catch skilift
            (new CableCar(2, slope))->Activate();
            goto tryagainCableCar;
        }

        Release(*slope->platformCableCar[shortestQueueOfChoosedCableCar]);
        Wait(slope->length/KM_H_5*2);
        
        (new CableCar(1, slope))->Activate();
    }
}

void Visitor::Home() {
    Wait(Uniform(3, 10)); // leaving ski area
}

void Visitor::ChoosingActivity(double morningRideProbability, double morningPauseOrHomeProbability, double morningPauseProbalility, double morningHomeProbability,
                                double lunchRideProbability, double lunchPauseOrHomeProbability, double lunchPauseProbalility, double lunchHomeProbability,
                                double afternoonRideProbability, double afternoonPauseOrHomeProbability, double afternoonPauseProbability, double afternoonHomeProbability,
                                double afternoonCashDeskClosedRideProbability, double afternoonCashDeskClosedPauseOrHomeProbability, double afternoonCashDeskClosedPauseProbability, double afternoonCashDeskClosedHomeProbability
) {
    // avoid unused variables warnings
    (void)morningPauseProbalility;
    (void)lunchPauseProbalility;
    (void)afternoonHomeProbability;
    (void)afternoonCashDeskClosedHomeProbability;

    switch(dayTime) {
        case MORNING:
            if (Random() <= morningPauseOrHomeProbability) {
                if (Random() <= morningHomeProbability) {
                    Home();
                } else {
                    Pause(morningRideProbability, morningPauseOrHomeProbability);
                }          
            } else {
                Ride();
            }
            break;

        case LUNCH:
            if (Random() <= lunchRideProbability) {
                Ride();
            } else {
                if (Random() <= lunchHomeProbability) {
                    Home();
                } else {
                    Pause(lunchRideProbability, lunchPauseOrHomeProbability);
                }
            }
            break;

        case AFTERNOON:
            if (Random() <= afternoonRideProbability) {
                Ride();
            } else {
                if (Random() <= afternoonPauseProbability) {
                    Pause(afternoonRideProbability, afternoonPauseOrHomeProbability);
                } else {
                    Home();
                }
            }
            break;
        
        case AFTERNOON_DESK_CLOSED:
            if (Random() <= afternoonCashDeskClosedRideProbability) {
                Ride();
            } else {
                if (Random() <= afternoonCashDeskClosedPauseProbability) {
                    Pause(afternoonCashDeskClosedRideProbability, afternoonCashDeskClosedPauseOrHomeProbability);
                } else {
                    Home();
                }
            }  
            break;

        case NIGHT:
            Home();
            break;

        default:
            break;
    }
}

void Visitor::WhatToDo() {
    switch(experience) { // choosing what to do based on experience
        case NEWBIE:
            ChoosingActivity(.75, .25, .90, .1, 
                                    .25, .75, .80, .20, 
                                    .20, .80, .30, .70, 
                                    .10, .90, .10, .90
                                    );
            break;

        case REGULAR:
            ChoosingActivity(.80, .20, .95, .5, 
                                    .40, .60, .85, .15, 
                                    .45, .65, .35, .65, 
                                    .20, .80, .30, .70
                                    );
            break;

        case EXPERT:
            ChoosingActivity(.85, .15, .95, .5, 
                                    .45, .55, .90, .10, 
                                    .50, .50, .40, .60, 
                                    .30, .70, .40, .60
                                    );
            break;

        default:
            break;
    }
}

void Visitor::Behavior() {
    double arrival = Time; // statistics of time spent in system

    experience = (Experience)((int)(Random()*3)); // random experience

    Wait(Uniform(2, 5)); // going to/around cash desks

    Ticket();

    Wait(Uniform(1, 3)); // going to ski area

    WhatToDo();

    VisitorInSystem(Time - arrival);
}   

/*** End of Visitor.cpp ***/
