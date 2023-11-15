/**
 * @file Slope.h
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Declaration of Slope class which represents slope.
*/

#ifndef SLOPE_H
#define SLOPE_H

#include "simlib.h"
#include "Visitor.h"
#include "SlopeEnums.h"
#include "CashDesk.h"
#include "macros.h"

/**
 * @class Slope
 * 
 * @brief Class which represents slope.
 */
class Slope {
    public:
        SlopeDifficulty difficulty; // slope difficulty
        FacilityType type; // facility type (skilift or cable car)
        
        // if skilift
        Queue queue; // queue
        Store* lift = new Store("Lift", NUMBER_OF_SKILIFTS); // number of skilifts 
        Facility* facility = new Facility(queue); // one platform in case of skilift)
        
        // if cable car
        Store* cableCar = new Store("CableCar", NUMBER_OF_CABLE_CARS * SEATS_IN_CABLE_CAR); // number of cablecars
        Queue queueCableCar[SEATS_IN_CABLE_CAR]; // array of queues based on seats
        Facility platformCableCar[SEATS_IN_CABLE_CAR] = { // plaforms for seats in cable car
            Facility(queueCableCar[0]),
            Facility(queueCableCar[1]),
            Facility(queueCableCar[2]),
            Facility(queueCableCar[3])
        };
        
        bool isRunning = false; // if skilift or cable car is running
        bool isFailure = false; // if skilift or cable car is in failure
        int length; // km

        /**
         * @brief Constructor of Slope class.
         * 
         * @param difficulty Difficulty of a slope.
         * @param facilityType Type of facility (skilift or cable car).
         * @param length Length of slope.
         */
        Slope(SlopeDifficulty difficulty, FacilityType facilityType, int length): difficulty(difficulty), type(facilityType), length(length) {}
        
        /**
         * @brief Method which clears Q1 of the skilift or cablecar.
         */
        void ClearQueue1();
};

extern Slope BlueSlopesSkiLift[BLUE_SLOPE_SKI_LIFT]; // blue slopes (ski lift)
 
extern Slope RedSlopesSkiLift[RED_SLOPE_SKI_LIFT]; // red slopes (ski lift)

extern Slope BlackSlopesCableCar[BLACK_SLOPE_CABLE_CAR]; // black slopes (cable car)

#endif

/*** End of Slope.h ***/
