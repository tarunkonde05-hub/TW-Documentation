/**
 * @file Logger.h
 * @brief Logging levels and a small console logger.
 *
 * Holds the LogLevel enum and the Logger class. The logger prints
 * messages to standard output with a prefix and a level tag, and
 * drops any message below its minimum level.
 *
 * @author Tarun Konde (2025UCP1811)
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

/**
 * @enum LogLevel
 * @brief Severity of a log message.
 *
 * The values are ordered from least to most severe, so they can be
 * compared with < and >.
 */
enum class LogLevel {
    INFO,    ///< Normal progress messages.
    WARNING, ///< Something unusual happened but the program can continue.
    ERROR    ///< An operation failed.
};

/**
 * @class Logger
 * @brief Prints prefixed, level-tagged messages to the console.
 *
 * Example:
 * @code
 * Logger log("[Main]", LogLevel::WARNING);
 * log.log(LogLevel::INFO, "hidden");     // below WARNING, not printed
 * log.log(LogLevel::ERROR, "printed");   // [Main] [ERROR] printed
 * @endcode
 */
class Logger {
private:
    std::string prefix; ///< Text printed before every message, e.g. "[CalcEngine]".
    LogLevel minLevel;  ///< Messages below this level are ignored.

public:
    /**
     * @brief Creates a logger.
     * @param logPrefix Text printed at the start of each line.
     * @param level     Minimum level that will be printed. Defaults to LogLevel::INFO.
     */
    Logger(const std::string& logPrefix, LogLevel level = LogLevel::INFO)
        : prefix(logPrefix), minLevel(level) {}

    /**
     * @brief Prints a message if its level is at least the minimum level.
     * @param level   Severity of this message.
     * @param message Text to print.
     */
    void log(LogLevel level, const std::string& message) const {
        if (level < minLevel) {
            return;
        }
        std::cout << prefix << " " << toString(level) << " " << message << std::endl;
    }

    /**
     * @brief Converts a level to the tag printed in the output.
     * @param level Level to convert.
     * @return "[INFO]", "[WARNING]" or "[ERROR]".
     */
    static std::string toString(LogLevel level) {
        switch (level) {
            case LogLevel::INFO:    return "[INFO]";
            case LogLevel::WARNING: return "[WARNING]";
            case LogLevel::ERROR:   return "[ERROR]";
        }
        return "[UNKNOWN]";
    }
};

#endif // LOGGER_H
