/**
 * @file Visitor.h
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Declaration of Visitor class which represents visitor and his behavior.
*/

#ifndef VISITOR_H
#define VISITOR_H

#include "simlib.h"
#include "macros.h"
#include "CashDesk.h"
#include "GeneratorDayTime.h"
#include "SlopeEnums.h"
#include "Slope.h"
#include "Skilift.h"
#include "CableCar.h"
#include "Statistics.h"
#include "GeneratorWeek.h"

/**
 * @enum Experience
 * 
 * @brief Enum which represents experience of visitor.
*/
enum Experience {
    NEWBIE,
    REGULAR,
    EXPERT
};

class Slope; // forward declaration

/**
 * @class Visitor
 * 
 * @brief Class which represents visitor and his behavior.
 */
class Visitor: public Process {
    public:
        bool interrupted = false; // if visitor was removed from queue

    private:
        Experience experience; // visitor experience
        int shortestQueueOfChoosedCableCar = 0; // shortest queue of choosed cable car

        /**
         * @brief Behavior of visitor.
         */
        void Behavior();

        /**
         * @brief Method which simulate visitors ticket purchase.
         */
        void Ticket();

        /**
         * @brief Method which simulate what will visitor do.
         */
        void WhatToDo();

        /**
         * @brief Method which simulate visitors activity choosing.
         * 
         * @param morningRideProbability Probability of ride in morning.
         * @param morningPauseOrHomeProbability Probability of pause or going home in morning.
         * @param morningPauseProbalility Probability of pause in morning.
         * @param morningHomeProbability Probability of going home in morning.
         * @param lunchRideProbability Probability of ride in lunch.
         * @param lunchPauseOrHomeProbability Probability of pause or going home in lunch.
         * @param lunchPauseProbalility Probability of pause in lunch.
         * @param lunchHomeProbability Probability of going home in lunch.
         * @param afternoonRideProbability Probability of ride in afternoon.
         * @param afternoonPauseOrHomeProbability Probability of pause or going home in afternoon.
         * @param afternoonPauseProbability Probability of pause in afternoon.
         * @param afternoonHomeProbability Probability of going home in afternoon.
         * @param afternoonCashDeskClosedRideProbability Probability of ride in afternoon when cash desk is closed.
         * @param afternoonCashDeskClosedPauseOrHomeProbability Probability of pause or going home in afternoon when cash desk is closed.
         * @param afternoonCashDeskClosedPauseProbability Probability of pause in afternoon when cash desk is closed.
         * @param afternoonCashDeskClosedHomeProbability Probability of going home in afternoon when cash desk is closed.
         */
        void ChoosingActivity(double morningRideProbability, double morningPauseOrHomeProbability, double morningPauseProbalility, double morningHomeProbability,
                                double lunchRideProbability, double lunchPauseOrHomeProbability, double lunchPauseProbalility, double lunchHomeProbability,
                                double afternoonRideProbability, double afternoonPauseOrHomeProbability, double afternoonPauseProbability, double afternoonHomeProbability,
                                double afternoonCashDeskClosedRideProbability, double afternoonCashDeskClosedPauseOrHomeProbability, double afternoonCashDeskClosedPauseProbability, double afternoonCashDeskClosedHomeProbability
        );
        
        /**
         * @brief Method which simulate visitors ride.
         */
        void Ride();

        /**
         * @brief Method which simulate visitors pause.
         */
        void Pause(double rideProbability, double homeProbability);

        /**
         * @brief Method which simulate visitors going home.
         */
        void Home();

        /**
         * @brief Method which simulate visitors going up to slope by cable car or skilift.
         */
        void GoUp(Slope *slope);

        /**
         * @brief Method which simulate visitors going down on slope.
         */
        Slope* ChooseSlopeBasedOnDifficulty(SlopeDifficulty difficulty);

        /**
         * @brief Method which simulate visitors choosing slope based on difficulty.
         */
        SlopeDifficulty ChooseSlopeColorBasedOnExperience();

};

#endif

/*** End of Visitor.h ***/
