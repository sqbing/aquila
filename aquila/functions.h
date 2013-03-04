/**
 * @file functions.h
 *
 * Miscellaneous utility functions.
 *
 * This file is part of the Aquila DSP library.
 * Aquila is free software, licensed under the MIT/X11 License. A copy of
 * the license is provided with the library in the LICENSE file.
 *
 * @package Aquila
 * @version 3.0.0-dev
 * @author Zbigniew Siciarz
 * @date 2007-2013
 * @license http://www.opensource.org/licenses/mit-license.php MIT
 * @since 3.0.0
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "global.h"
#include <algorithm>
#include <cmath>
#include <cstdlib>

namespace Aquila
{
    /**
     * Converts the value to decibels (assuming reference value equal to 1).
     *
     * @param value input value
     * @return value in dB
     */
    template<typename Numeric>
    AQUILA_EXPORT inline Numeric dB(Numeric value)
    {
        return 20.0 * std::log10(value);
    }

    /**
     * Convert the magnitude of a complex number to decibels.
     *
     * @param value input value (complex number)
     * @return magnitude in dB
     */
    AQUILA_EXPORT inline double dB(ComplexType value)
    {
        return dB(std::abs(value));
    }

    /**
     * Converts the value to decibels, relative to the reference value.
     *
     * @param value input value
     * @param refValue reference value
     * @return value in dB, relative to reference value
     */
    template<typename Numeric>
    AQUILA_EXPORT inline Numeric dB(Numeric value, Numeric refValue)
    {
        return 20.0 * std::log10(value / refValue);
    }

    /**
     * Clamps (limits) the value inside a range.
     *
     * @param min lower limit
     * @param value numver to clamp
     * @param max upper limit
     * @return bounded value
     */
    template<typename Numeric>
    AQUILA_EXPORT inline Numeric clamp(Numeric min, Numeric value, Numeric max)
    {
        return std::max(min, std::min(value, max));
    }

    /**
     * Returns a pseudorandom value from a range.
     *
     * @param from lower limit
     * @param to upper limit
     * @return random number
     */
    AQUILA_EXPORT inline int random(int from, int to)
    {
        return std::rand() % (to - from) + from;
    }

    /**
     * Returns a pseudorandom double number from 0 to 1.
     */
    AQUILA_EXPORT inline double randomDouble()
    {
        return std::rand() / static_cast<double>(RAND_MAX);
    }
}

#endif // FUNCTIONS_H