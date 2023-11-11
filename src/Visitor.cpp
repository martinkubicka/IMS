#include "Visitor.h"

void Visitor::Ticket() {
    if (Random() <= 0.4 && !cashDeskOpened) { // ticket not bought online
        int shortestQueue = 0;
        for (int i = 0; i < CASHDESK; i++) { // finding the shortest queue
            if (CashDesk[i].QueueLen() < CashDesk[shortestQueue].QueueLen()) {
                shortestQueue = i;
            }
        }

        Seize(CashDesk[shortestQueue]);
        Wait(Exponential(3)); // buying a ticket
        Release(CashDesk[shortestQueue]);
    }
}

void Visitor::ChooseSlopeBasedOnDifficulty(SlopeDifficulty difficulty) {
    (void) difficulty;
    // TODO
    // implement odstavky (vyprazdnit frontu) - zle pocasie
    // implement poruchy (vyprazdnit frontu) - random
    // implement samotne vybratie najkratsie fronta + musi fungovat
    // implement samotnu jazdu + nehoda
}

void Visitor::Ride() {
    switch(this->experience) { // choosing slope based on experience
        case NEWBIE:
            if (Random() <= 0.5) { // hard slope
                ChooseSlopeBasedOnDifficulty(BLACK);
            } else { // medium or easy slope
                if (Random() <= 0.1) { // medium slope
                    ChooseSlopeBasedOnDifficulty(RED);
                } else { // easy slope
                    ChooseSlopeBasedOnDifficulty(BLUE);
                }
            }

            break;

        case REGULAR:
            if (Random() <= 0.4) { // hard slope
                ChooseSlopeBasedOnDifficulty(BLACK);
            } else { // medium or easy slope
                if (Random() <= 0.3) { // easy slope
                    ChooseSlopeBasedOnDifficulty(BLUE);
                } else { // medium slope
                    ChooseSlopeBasedOnDifficulty(RED);
                }
            }
            break;
        
        case EXPERT:
            if (Random() <= 0.3) { // medium or easy slope
                if (Random() <= 0.2) { // easy slope
                    ChooseSlopeBasedOnDifficulty(BLUE);
                } else { // medium slope
                    ChooseSlopeBasedOnDifficulty(RED);
                }
            } else { // hard slope
                ChooseSlopeBasedOnDifficulty(BLACK);
            }
            break;
        
        default:
            break;
    }
}

bool Visitor::Pause(int rideProbability, int homeProbability) {
    Wait(Uniform(1, 5)); // choosing restaurant and going there
    Wait(Uniform(10, 40)); // eating
    Wait(Uniform(1, 5)); // going back to ski area

    if (rideProbability < homeProbability) {
        if (Random() <= rideProbability) {
            Ride();
            return true;
        } else {
            Home();
            return false;
        }
    } else {
        if (Random() <= homeProbability) {
            Home();
            return false;
        } else {
            Ride();
            return true;
        }
    }
}

void Visitor::Home() {
    Wait(Uniform(3, 10)); // leaving ski area
}

bool Visitor::ChoosingActivity(int morningRideProbability, int morningPauseOrHomeProbability,int morningPauseProbalility, int morningHomeProbability,
                                int lunchRideProbability, int lunchPauseOrHomeProbability, int lunchPauseProbalility, int lunchHomeProbability,
                                int afternoonRideProbability, int afternoonPauseOrHomeProbability, int afternoonPauseProbability, int afternoonHomeProbability,
                                int afternoonCashDeskClosedRideProbability, int afternoonCashDeskClosedPauseOrHomeProbability, int afternoonCashDeskClosedPauseProbability, int afternoonCashDeskClosedHomeProbability
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
                    return false;
                } else {
                    return Pause(morningRideProbability, morningPauseOrHomeProbability);
                }          
            } else {
                Ride();
                return true;
            }

        case LUNCH:
            if (Random() <= lunchRideProbability) {
                Ride();
                return true;
            } else {
                if (Random() <= lunchHomeProbability) {
                    Home();
                    return false;
                } else {
                    return Pause(lunchRideProbability, lunchPauseOrHomeProbability);
                }
            }

        case AFTERNOON:
            if (Random() <= afternoonRideProbability) {
                Ride();
                return true;
            } else {
                if (Random() <= afternoonPauseProbability) {
                    return Pause(afternoonRideProbability, afternoonPauseOrHomeProbability);
                } else {
                    Home();
                    return false;
                }
            }
        
        case AFTERNOON_DESK_CLOSED:
            if (Random() <= afternoonCashDeskClosedRideProbability) {
                Ride();
                return true;
            } else {
                if (Random() <= afternoonCashDeskClosedPauseProbability) {
                    return Pause(afternoonCashDeskClosedRideProbability, afternoonCashDeskClosedPauseOrHomeProbability);
                } else {
                    Home();
                    return false;
                }
            }
              
        case NIGHT:
            Home();
            return false;

        default:
            return true;
    }
}

bool Visitor::WhatToDo() {
    switch(experience) { // choosing what to do based on experience
        case NEWBIE:
            return ChoosingActivity(.75, .25, .90, .1, 
                                    .25, .75, .80, .20, 
                                    .20, .80, .30, .70, 
                                    .10, .90, .10, .90
                                    );

        case REGULAR:
            return ChoosingActivity(.80, .20, .95, .5, 
                                    .40, .60, .85, .15, 
                                    .45, .65, .35, .65, 
                                    .20, .80, .30, .70
                                    );

        case EXPERT:
            return ChoosingActivity(.85, .15, .95, .5, 
                                    .45, .55, .90, .10, 
                                    .50, .50, .40, .60, 
                                    .30, .70, .40, .60
                                    );
        
        default:
            return true;
    }
}

void Visitor::Behavior() {
    experience = (Experience)(1 + (int)(Random()*2));

    Wait(Uniform(2, 5)); // going to/around cash desks

    Ticket();

    Wait(Uniform(1, 3)); // going to ski area

    while (WhatToDo()); // doing activities
}   
