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
private:

    std::ofstream logFile;
    std::mutex logMutex;
    bool isInitialized;


    Logger() {
        isInitialized = false;
    }

public:

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;


    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void init(const std::string& filePath);
    void log(LogLevel level, const std::string& msg);
    void close();
};

#endif