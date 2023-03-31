#include <ctime>
#include "logger.hpp"

Logger::Logger() {
    logFile.open(logFileName);
    errorFile.open(errorFileName);
    debugFile.open(debugFileName, std::ios::out | std::ios::app);
}

Logger::~Logger() {
    logFile.close();
    errorFile.close();
    debugFile.close();
}

void Logger::log(const char * message) {
    std::time_t t = std::time(0);
    logFile << std::asctime(std::localtime(&t)) << message<<"\n\n";
}

void Logger::error(const char * message) {
    std::time_t t = std::time(0);
    errorFile << std::asctime(std::localtime(&t)) << message<<"\n\n";
}

void Logger::debug(const char * message) {
    std::time_t t = std::time(0);
    debugFile << std::asctime(std::localtime(&t)) << message<<"\n\n";
}

Logger &Logger::getInstance() {
    static Logger instance;
    return instance;
}

Logger &Logger::operator<<(const char *message) {
    log(message);
    return *this;
}
