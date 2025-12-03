#include "../include/kernel/logging/Logger.hpp"
#include "../include/shell/Shell.hpp"
#include <string>
#include <iostream>
#include <cstdlib> // عشان دالة system
#include <cstring> // عشان strcmp

int main(int argc, char* argv[]) {
    bool isNewWindow = false;
    if (argc > 1 && std::strcmp(argv[1], "--new-window") == 0) {
        isNewWindow = true;
    }

    if (!isNewWindow) {

        std::cout << "Launching MIME-OS in a new console..." << std::endl;

        std::string myPath = argv[0];
        std::string command = "gnome-terminal -- " + myPath + " --new-window";

        int result = std::system(command.c_str());

        if (result != 0) {
            command = "xterm -e " + myPath + " --new-window";
            std::system(command.c_str());
        }

        return 0;
    }
    Logger::init("data/logs/system.log");
    Logger::log(LogLevel::INFO, "System Booted Successfully in New Window.");

    Shell shell;
    shell.run();
    Logger::close();
    std::cout << "Press Enter to close window...";
    std::cin.get();

    return 0;
}