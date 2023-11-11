#ifndef SLOPE_H
#define SLOPE_H

#define BLUE_SLOPE_SKI_LIFT 2
#define RED_SLOPE_SKI_LIFT 1
#define RED_SLOPE_CABLE_CAR 1
#define BLACK_SLOPE_CABLE_CAR 1

enum SlopeDifficulty {
    BLACK,
    RED,
    BLUE
};

enum FacilityType {
    SKI_LIFT,
    CABLE_CAR
};

class Slope {
    public:
        SlopeDifficulty difficulty;
        FacilityType type;
        Facility facility;
        bool isRunning = false;
        bool isFailure = false;
        int length; // km

        Slope(SlopeDifficulty difficulty, FacilityType facilityType, int length): difficulty(difficulty), type(facilityType), length(length) {}
};

static Slope BlueSlopesSkiLift[BLUE_SLOPE_SKI_LIFT] = {
    {BLUE, SKI_LIFT, 600},
    {BLUE, SKI_LIFT, 500}
};

static Slope RedSlopesSkiLift[RED_SLOPE_SKI_LIFT] = {
    {RED, SKI_LIFT, 1000}
};

static Slope RedSlopesCableCar[RED_SLOPE_CABLE_CAR] = {
    {RED, CABLE_CAR, 1300}
};

static Slope BlackSlopesCableCar[BLACK_SLOPE_CABLE_CAR] = {
    {BLACK, CABLE_CAR, 2000}
};

#endif
