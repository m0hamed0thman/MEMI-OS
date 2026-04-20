#include "../../../include/kernel/logging/Logger.hpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>



void Logger::close() {
    std::lock_guard<std::mutex> lock(logMutex);
    if (isInitialized && logFile.is_open()) {
        logFile << "[SYSTEM] === System Logger Closed ===" << std::endl;
        logFile.close();
        isInitialized = false;
    }
}


void Logger::init(const std::string& filePath) {
    std::lock_guard<std::mutex> lock(logMutex);

    if (isInitialized) return;

    logFile.open(filePath, std::ios::app);

    if (logFile.is_open()) {
        isInitialized = true;
        logFile << "[SYSTEM] === MIME-OS System Logger Initialized ===" << std::endl;
    } else {
        std::cerr << "[CRITICAL ERROR] Failed to open log file at: " << filePath << std::endl;
    }
}
void Logger::log(LogLevel level, const std::string& msg) {
    std::lock_guard<std::mutex> lock(logMutex);

    std::string levelStr;
    std::string colorCode;

    switch (level) {
        case LogLevel::INFO:
            levelStr = "INFO";
            colorCode = "\033[32m";
            break;
        case LogLevel::WARNING:
            levelStr = "WARN";
            colorCode = "\033[33m";
            break;
        case LogLevel::ERROR:
            levelStr = "ERROR";
            colorCode = "\033[31m";
            break;
        case LogLevel::DEBUG:
            levelStr = "DEBUG";
            colorCode = "\033[36m";
            break;
    }
    std::string resetColor = "\033[0m";


    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);


    if (isInitialized && logFile.is_open()) {
        logFile << "[" << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S") << "] "
                << "[" << levelStr << "] "
                << msg << std::endl;

        logFile.flush();
    }
}