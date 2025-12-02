
#include "../../include/kernel/logging/Logger.hpp"
#include "../../include/shell/Commands.hpp"

#include <iostream>
#include <algorithm>

std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

bool Commands::execute(const std::string &cmd, const std::vector<std::string> &args) {

    std::string command = toLower(cmd);

    if (command == "help") {
        Logger::log(LogLevel::INFO, "Call Help");
        cmdHelp();
    }else if (command == "exit") {
        Logger::log(LogLevel::INFO, " Call Exit");
        return false;
    }else if (command == "clear" || command == "cls") {
        Logger::log(LogLevel::INFO, "Call Clear");
        cmdClear();
    }else if (command == "sum") {
        Logger::log(LogLevel::INFO, "Call Sum");
        std :: string a = args[1];
        std :: string b = args[2];
        int x = stoi(a);
        int y = stoi(b);
        cmdSum(x,y);
    }
    else {
        Logger::log(LogLevel::WARNING, "Call Unknown Command");
        std::cerr << "Unknown command: " << command << std::endl;
    }

    return true;
}


void Commands::cmdHelp() {
    Logger::log(LogLevel::INFO, "Execute  Help Command");
    std::cout << "\n--- MIME-OS Available Commands ---\n";
    std::cout << "  help, ?      : Show this help menu\n";
    std::cout << "  clear, cls   : Clear the screen\n";
    std::cout << "  exit  : Shutdown the system\n";
    std::cout << "  sum  : Sum the number of arguments\n";
    std::cout << "----------------------------------\n";
}

void Commands::cmdClear() {
    Logger::log(LogLevel::INFO, "Clearing Screen");
    std::cout << "\033[2J\033[1;1H";
}

void Commands::cmdSum(const int a, const int b) {
    Logger::log(LogLevel::INFO, "execute Sum");
    std :: cout << a << " + " << b << " = " << a + b << "\n";
}