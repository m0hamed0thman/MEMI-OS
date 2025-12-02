#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <fstream>
#include <string>
#include <mutex>

// using namespace std;

enum class LogLevel {
    INFO,
    WARNING,
    ERROR,
    DEBUG
};

class Logger {


    static std :: ofstream logFile;
    static std :: mutex logMutex;
    static bool isInitialized;

    public:

    static void init(const std :: string& filePath);

    static void log(LogLevel level, const std :: string& msg);

    static void close();
};

#endif