/**
 * @file CalculationEngine.h
 * @brief Declares the CalculationEngine class.
 *
 * @author Tarun Konde (2025UCP1811)
 */

#ifndef CALCULATION_ENGINE_H
#define CALCULATION_ENGINE_H

#include "Logger.h"
#include <cmath>
#include <limits>

/**
 * @class CalculationEngine
 * @brief Performs mathematical operations and logs each step.
 *
 * @details Every public method writes what it is doing through its own
 * Logger, so the caller can see the steps and any edge cases (such as
 * division by zero) without adding print statements.
 *
 * @see Logger
 */
class CalculationEngine {
private:
    Logger logger; ///< Logger used by every operation of this engine.

public:
    /**
     * @brief Creates an engine whose log lines start with "[CalcEngine]".
     * @param level Minimum level the internal logger will print.
     */
    explicit CalculationEngine(LogLevel level = LogLevel::INFO)
        : logger("[CalcEngine]", level) {}

    /**
     * @brief Raises @p base to the power @p exponent.
     *
     * Computes \f$ base^{exponent} \f$ using std::pow.
     *
     * @param base     The number being raised.
     * @param exponent The power to raise it to.
     * @return \f$ base^{exponent} \f$, or positive infinity when
     *         @p base is 0 and @p exponent is negative.
     *
     * @warning 0 raised to a negative power is a division by zero.
     *          It is logged as an error and infinity is returned.
     *
     * @todo Detect overflow for very large results and handle a negative
     *       base with a fractional exponent (std::pow returns NaN there).
     */
    double power_calculation(double base, double exponent) {
        logger.log(LogLevel::INFO, "power_calculation(" + std::to_string(base) +
                                   ", " + std::to_string(exponent) + ")");

        if (base == 0.0 && exponent < 0.0) {
            logger.log(LogLevel::ERROR, "0 raised to a negative power (division by zero)");
            return std::numeric_limits<double>::infinity();
        }

        double result = std::pow(base, exponent);
        logger.log(LogLevel::INFO, "result = " + std::to_string(result));
        return result;
    }
};

#endif // CALCULATION_ENGINE_H
