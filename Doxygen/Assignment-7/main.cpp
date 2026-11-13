/**
 * @file main.cpp
 * @brief Entry point. Uses CalculationEngine to compute a few powers.
 *
 * @author Tarun Konde (2025UCP1811)
 */

/**
 * @mainpage Calculation Engine - Doxygen Lab (Assignment 7)
 *
 * @section intro Introduction
 * A small multi-file C++ project documented with Doxygen for the
 * Technical Writing lab at MNIT Jaipur.
 *
 * @section files Files
 * - Logger.h : LogLevel enum and the Logger class
 * - CalculationEngine.h : CalculationEngine class, which uses Logger
 * - main.cpp : this file, the program entry point
 *
 * @section build Build and run
 * @code{.sh}
 * g++ -std=c++17 main.cpp -o calc
 * ./calc
 * @endcode
 *
 * @section docs Generating these docs
 * @code{.sh}
 * doxygen Doxyfile          # writes doc_html/ and doc_latex/
 * cd doc_latex && make      # builds refman.pdf
 * @endcode
 *
 * @author Tarun Konde (2025UCP1811)
 */

#include <iostream>
#include "CalculationEngine.h"

/**
 * @brief Runs three sample calculations, including the zero-base edge case.
 * @return 0 on success.
 */
int main() {
    CalculationEngine engine;

    double a = engine.power_calculation(2.0, 8.0);
    double b = engine.power_calculation(9.0, 0.5);
    double c = engine.power_calculation(0.0, -1.0);

    std::cout << "\n2^8   = " << a << std::endl;
    std::cout << "9^0.5 = " << b << std::endl;
    std::cout << "0^-1  = " << c << std::endl;

    return 0;
}
