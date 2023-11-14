#ifndef SLOPE_H
#define SLOPE_H

#include "simlib.h"
#include "Visitor.h"
#include "SlopeEnums.h"
#include "CashDesk.h"

#define BLUE_SLOPE_SKI_LIFT 2
#define RED_SLOPE_SKI_LIFT 1
#define BLACK_SLOPE_CABLE_CAR 1
#define SEATS_IN_CABLE_CAR 4
#define NUMBER_OF_SKILIFTS 200
#define NUMBER_OF_CABLE_CARS 100

class Slope {
    public:
        SlopeDifficulty difficulty;
        FacilityType type;
        
        // skilift
        Queue queue;
        Store* lift = new Store("Lift", NUMBER_OF_SKILIFTS); // skilift 
        Facility* facility = new Facility(queue); // one platform in case of skilift)
        
        // cable car
        Store* cableCar = new Store("CableCar", NUMBER_OF_CABLE_CARS * SEATS_IN_CABLE_CAR);
        Queue queueCableCar[SEATS_IN_CABLE_CAR];
        Facility platformCableCar[SEATS_IN_CABLE_CAR] = {
            Facility(queueCableCar[0]),
            Facility(queueCableCar[1]),
            Facility(queueCableCar[2]),
            Facility(queueCableCar[3])
        };
        
        bool isRunning = false;
        bool isFailure = false;
        int length; // km

        Slope(SlopeDifficulty difficulty, FacilityType facilityType, int length): difficulty(difficulty), type(facilityType), length(length) {}
        void ClearQueue1();
};

extern Slope BlueSlopesSkiLift[BLUE_SLOPE_SKI_LIFT];

extern Slope RedSlopesSkiLift[RED_SLOPE_SKI_LIFT];

extern Slope BlackSlopesCableCar[BLACK_SLOPE_CABLE_CAR];

#endif
