/**
 * @file GeneratorWeather.h
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Declaration of GeneratorWeather class which is responsible for changing weathers.
*/

#ifndef GENERATORWEATHER_H
#define GENERATORWEATHER_H

#include "simlib.h"
#include "macros.h"
#include "Slope.h"
#include "GeneratorDayTime.h"
#include "Visitor.h"

extern bool sunny; // true if weather is sunny

/**
 * @class GeneatorWeather
 * 
 * @brief Generator of weather.
 */
class GeneratorWeather: public Event {
    private:
        /**
         * @brief Behavior of GeneratorWeather event.
         */
        void Behavior();

        /**
         * @brief Method which sets wind global variable and stops cable cars if wind is true.
         * 
         * @param wind bool value which will be set
         */
        void SetWind(bool wind);
};

#endif

/*** End of GeneratorWeather.h ***/
