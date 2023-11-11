#include "simlib.h"
#include "macros.h"
#include "GeneratorWeek.h"
#include "GeneratorVisitor.h"
#include "GeneratorWeather.h"
#include "CashDesk.h"
#include "GeneratorDayTime.h"

int main() {
    // avoid unused variable warnings
    (void)cashDeskOpened;
    (void)sunny;
    (void)weekend;
    (void)dayTime;
    (void)wind;

    RandomSeed(time(NULL));

    Init(0, SEASON);   

	(new GeneratorWeek)->Activate();
    (new GeneratorDayTime)->Activate();
    (new GeneratorWeather)->Activate();
	
	Run();
}

// todo comments
// statistiky
// dokumentacia
// precitat zadanie
