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

// todo comments
// todo valgrind

// rozumne upravit statistiky
// testovanie s roznymi params (viac zakaznikov, prepazky, viac vlekov/cabincarov, vacsia kapacita sedaciek, menej sedaciek/liftov v store,lzsie zjadovky)
// dokumentacia
// precitat zadanie
// todo prepisat automaticky generaovanie slope/facility (slope.h) podla enum
