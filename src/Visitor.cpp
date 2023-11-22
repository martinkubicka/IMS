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
        Wait(Exponential(3*MINUTE)); // buying a ticket
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

            if (RED_SLOPES_REPRESENTED_BY_SKILIFT) {
                for (int i = 0; i < RED_SLOPE_SKI_LIFT; i++) {
                    if (RedSlopesSkiLift[i].isRunning && !RedSlopesSkiLift[i].isFailure && RedSlopesSkiLift[i].facility->QueueLen() <= RedSlopesSkiLift[shortestQueue].facility->QueueLen()) {
                        shortestQueue = i;
                        choosedSlope = &RedSlopesSkiLift[i];
                    }
                }
            } else {
                for (int i = 0; i < RED_SLOPE_SKI_LIFT; i++) {
                    for (int j = 0; j < SEATS_IN_CABLE_CAR; j++) {
                        if (RedSlopesSkiLift[i].isRunning && !RedSlopesSkiLift[i].isFailure && RedSlopesSkiLift[i].platformCableCar[j].QueueLen() <= RedSlopesSkiLift[shortestQueue].platformCableCar[shortestQueueOfChoosedCableCar].QueueLen()) {
                            shortestQueue = i;
                            shortestQueueOfChoosedCableCar = j;
                            choosedSlope = &RedSlopesSkiLift[i];
                        }
                    }
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
            if (Random() <= 0.1) { // hard slope
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
            if (Random() <= 0.3) { // hard slope
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
                if (Random() <= 0.1) { // easy slope
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
    Wait(Uniform(MINUTE, 5*MINUTE)); // choosing restaurant and going there
    Wait(Uniform(10*MINUTE, 40*MINUTE)); // eating
    Wait(Uniform(1*MINUTE, 5*MINUTE)); // going back to ski area

    if (dayTime == NIGHT) {
        Home();
        return;
    }

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
            Wait(Uniform(static_cast<double>(slope->length)/static_cast<double>(EXPERT_SPEED), static_cast<double>(slope->length)/static_cast<double>(EXPERT_SPEED) + 2*MINUTE));
            break;
        
        case REGULAR:
            Wait(Uniform(static_cast<double>(slope->length)/static_cast<double>(REGULAR_SPEED), static_cast<double>(slope->length)/static_cast<double>(REGULAR_SPEED) + 2*MINUTE));
            break;
        
        case NEWBIE:
            Wait(Uniform(static_cast<double>(slope->length)/static_cast<double>(NEWBIE_SPEED), static_cast<double>(slope->length)/static_cast<double>(NEWBIE_SPEED) + 2*MINUTE));
            break;
        
        default:
            break;
    }

    WhatToDo();
}

void Visitor::AddStats(double inQueue, Slope* slope) {
    if (weekend && holidays) {
        if (slope->difficulty == BLUE) {
            VisitorInBlueQueueWeekendHolidays((Time - inQueue) / MINUTE);
        } else if (slope->difficulty == RED) {
            VisitorInRedQueueWeekendHolidays((Time - inQueue) / MINUTE);
        } else {
            VisitorInBlackQueueWeekendHolidays((Time - inQueue) / MINUTE);
        }
    } else if (weekend && !holidays) {
        if (slope->difficulty == BLUE) {
            VisitorInBlueQueueWeekendNotHolidays((Time - inQueue) / MINUTE);
        } else if (slope->difficulty == RED) {
            VisitorInRedQueueWeekendNotHolidays((Time - inQueue) / MINUTE);
        } else {
            VisitorInBlackQueueWeekendNotHolidays((Time - inQueue) / MINUTE);
        }
    } else if (!weekend && holidays) {
        if (slope->difficulty == BLUE) {
            VisitorInBlueQueueWorkWeekHolidays((Time - inQueue) / MINUTE);
        } else if (slope->difficulty == RED) {
            VisitorInRedQueueWorkWeekHolidays((Time - inQueue) / MINUTE);
        } else {
            VisitorInBlackQueueWorkWeekHolidays((Time - inQueue) / MINUTE);
        }
    } else if (!weekend && !holidays) {
        if (slope->difficulty == BLUE) {
            VisitorInBlueQueueWorkWeekNotHolidays((Time - inQueue) / MINUTE);
        } else if (slope->difficulty == RED) {
            VisitorInRedQueueWorkWeekNotHolidays((Time - inQueue) / MINUTE);
        } else {
            VisitorInBlackQueueWorkWeekNotHolidays((Time - inQueue) / MINUTE);
        }
    }
}

void Visitor::GoUp(Slope *slope) {
    double inQueue = Time;

    if (slope->difficulty == BLUE) {
        BlueSlopesQueueLength(slope->facility->QueueLen());
    } else if (slope->difficulty == RED) {
        if (RED_SLOPES_REPRESENTED_BY_SKILIFT) {
            RedSlopesQueueLength(slope->facility->QueueLen());
        } else {
            RedSlopesQueueLength(slope->platformCableCar[shortestQueueOfChoosedCableCar].QueueLen());
        }
    } else {
        BlackSlopesQueueLength(slope->platformCableCar[shortestQueueOfChoosedCableCar].QueueLen());
    }

    if (slope->type == SKI_LIFT) {
        Seize(*slope->facility); // platform
        
        if (interrupted) {
            interrupted = false;
            Ride();
            return;
        }

        // stats
        AddStats(inQueue, slope);

        Wait(5); // 5 seconds

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
        
        if (interrupted) {
            interrupted = false;
            Ride();
            return;
        }

        // stats
        AddStats(inQueue, slope);
        
        Wait(10); // 10 seconds

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
    Wait(Uniform(3*MINUTE, 10*MINUTE)); // leaving ski area
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
            ChoosingActivity(.9, .1, .95, .05, 
                            .3, .70, .95, .05, 
                            .30, .70, .30, .70, 
                            .10, .90, .10, .90
                            );
            break;

        case REGULAR:
            ChoosingActivity(.95, .05, .98, .02, 
                            .45, .55, .98, .02, 
                            .45, .65, .5, .5, 
                            .20, .80, .30, .70
                            );
            break;

        case EXPERT:
            ChoosingActivity(.99, .01, .99, .01, 
                            .5, .5, .99, .01, 
                            .50, .50, .50, .50, 
                            .30, .70, .40, .60
                            );
            break;

        default:
            break;
    }
}

void Visitor::GetRandomExperience() {
    if (Random() < 0.40) {
        experience = REGULAR;
    } else {
        if (Random() < 0.5) {
            experience = NEWBIE;
        } else {
            experience = EXPERT;
        }
    }
}

void Visitor::Behavior() {
    double arrival = Time; // statistics of time spent in system

    GetRandomExperience(); // generating experience

    Wait(Uniform(2*MINUTE, 5*MINUTE)); // going to/around cash desks

    Ticket();

    Wait(Uniform(1*MINUTE, 3*MINUTE)); // going to ski area

    WhatToDo();

    VisitorInSystem((Time - arrival) / 60 / 60);
}   

/*** End of Visitor.cpp ***/
