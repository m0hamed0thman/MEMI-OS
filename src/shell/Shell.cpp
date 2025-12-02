#include "../../include/shell/Shell.hpp"
#include "../../include/shell/Commands.hpp"   // استدعاء المنفذ
#include "../../include/utils/StringUtils.hpp" // استدعاء الأدوات
#include "../../include/kernel/logging/Logger.hpp"    // استدعاء اللوجر
#include <iostream>

void Shell::run() {
    Logger::log(LogLevel::INFO, "Shell session started interactively.");
    std::cout << "Welcome to MIME-OS v0.1" << std::endl;
    std::cout << "Type 'help' to see available commands." << std::endl;

    std::string input;
    bool isRunning = true;

    while (isRunning) {
        std :: cout << "MIME-OS: " ;
        getline(std :: cin, input);

        std :: string cleanInput = StringUtils::trim(input);

        if ((int)cleanInput.size() == 0) {
            continue;
        }

        std::vector<std::string> args = StringUtils::split(cleanInput, ' ');

        if (!args.empty()) {
            std::string cmd = args[0];


            isRunning = Commands :: execute(cmd,args);

        }

    }
    Logger::log(LogLevel::INFO, "Shell session ended.");
}