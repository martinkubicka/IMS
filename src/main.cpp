/**
 * @file main.cpp
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Main file of the project containing main function, where simulation starts and generators are activated.
*/

#include "simlib.h"
#include "macros.h"
#include "GeneratorWeek.h"
#include "GeneratorVisitor.h"
#include "GeneratorWeather.h"
#include "CashDesk.h"
#include "GeneratorDayTime.h"
#include "GeneratorFailure.h"
#include "Slope.h"
#include "Statistics.h"
#include "GeneratorHolidays.h"

// definition of extern global variables from cashDesk.h
bool cashDeskOpened = false;
Facility CashDesk[CASHDESK];

int main() {
    // avoid unused variable warnings
    (void)sunny;
    (void)weekend;
    (void)dayTime;
    (void)wind;

    RandomSeed(time(NULL));

    Init(0, SEASON);   

    // generators
    (new GeneratorHolidays)->Activate();
	(new GeneratorWeek)->Activate();
    (new GeneratorDayTime)->Activate();
    (new GeneratorWeather)->Activate();

    for (auto &slope : BlueSlopesSkiLift) {
        (new GeneratorFailure(&slope))->Activate();
    }

    for (auto &slope : RedSlopesSkiLift) {
        (new GeneratorFailure(&slope))->Activate();
    }

    for (auto &slope : BlackSlopesCableCar) {
        (new GeneratorFailure(&slope))->Activate();
    }
	
    (new GeneratorVisitor)->Activate();

	Run();

    PrintStatistics();
}

/*** End of main.cpp ***/

// todo red na cablecar
// testovanie s roznymi params (viac zakaznikov, prepazky, viac vlekov/cabincarov, vacsia kapacita sedaciek, menej sedaciek/liftov v store,lzsie zjadovky)
// dokumentacia (zadanie + demo)

