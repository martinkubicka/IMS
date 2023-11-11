#include "GeneratorWeek.h"

void GeneratorWeek::Behavior() {
    if (weekend) { // working week
        weekend = false;
        Activate(Time + (5*DAY));
    } else { // weekend
        weekend = true;
        Activate(Time + (2*DAY));
    }
}
