#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>

class Logger {
private:
    Logger();
    static constexpr const char* logFileName = "log.txt";
    static constexpr const char* errorFileName = "error.txt";
    static constexpr const char* debugFileName = "debug.txt";
    std::ofstream logFile;
    std::ofstream errorFile;
    std::ofstream debugFile;
public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    ~Logger();

    void log(const char*);
    void error(const char*);
    void debug(const char*);

    static Logger& getInstance();
    Logger& operator<<(const char* message);
};

#endif

#define logger Logger::getInstance()