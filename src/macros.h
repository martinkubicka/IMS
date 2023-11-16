/**
 * @file macros.h
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Macros definitions used in the project.
*/

#ifndef MACROS_H
#define MACROS_H

#define SEASON 5*31*24*60*60 // 5 months
#define DAY 24*60*60 // 1 day
#define HOUR 60*60 // 1 hour
#define MINUTE 60 // 1 minute

#define KM_H_5 285/60 // divider for speed 5 km/h

#define EXPERT_SPEED 7*KM_H_5 // speed of expert skier
#define REGULAR_SPEED 5*KM_H_5 // speed of regular skier
#define NEWBIE_SPEED 3*KM_H_5 // speed of newbie skier

#define CASHDESK 5 // number of cash desks in area

// number of skilift and cable cars
#define BLUE_SLOPE_SKI_LIFT 2
#define RED_SLOPE_SKI_LIFT
#define BLACK_SLOPE_CABLE_CAR 1

// number of seats in cable car
#define SEATS_IN_CABLE_CAR 4

// number of skilifts and cable cars in "store"
#define NUMBER_OF_SKILIFTS 200
#define NUMBER_OF_CABLE_CARS 100

#endif

/*** End of macros.h ***/
