
#include "../../include/kernel/logging/Logger.hpp"
#include "../../include/shell/Commands.hpp"

#include "../../include/fileSystem/FileSystem.hpp"
#include <iostream>
#include <algorithm>

std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

bool Commands::execute(const std::string &cmd, const std::vector<std::string> &args, FileSystem& fs) {

    std::string command = toLower(cmd);

    if (command == "exit" || command == "quit") {
        return false;
    }
    else if (command == "help") {
        cmdHelp();
    }
    else if (command == "clear" || command == "cls") {
        cmdClear();
    }
    // === أوامر الملفات (الجديد) ===
    else if (command == "ls" || command == "dir") {
        // بننادي ls من الـ fs ونطبع النتيجة
        std::cout << fs.ls();
    }
    else if (command == "pwd") {
        std::cout << fs.pwd() << "\n";
    }
    else if (command == "mkdir") {
        if (args.size() < 2) {
            std::cout << "Usage: mkdir <directory_name>\n";
        } else {
            // args[1] هو اسم الفولدر
            std::cout << fs.mkdir(args[1]) << "\n";
        }
    }
    else if (command == "touch") {
        if (args.size() < 2) {
            std::cout << "Usage: touch <file_name>\n";
        } else {
            std::cout << fs.touch(args[1]) << "\n";
        }
    }
    else if (command == "cd") {
        if (args.size() < 2) {
            std::cout << "Usage: cd <path>\n";
        } else {
            std::cout << fs.cd(args[1]) << "\n";
        }
    }else if (command == "sum") {
        std :: string a = args[1];
        std :: string b = args[2];
        int x = stoi(a);
        int y = stoi(b);
        cmdSum(x,y);
    }



    else {
        std::cout << "Unknown command: " << cmd << "\n";
    }

    return true;
}


void Commands::cmdHelp() {
    std::cout << "\n--- MIME-OS Available Commands ---\n";
    std::cout << "  help, ?      : Show this help menu\n";
    std::cout << "  clear, cls   : Clear the screen\n";
    std::cout << "  exit  : Shutdown the system\n";
    std::cout << "  sum  : Sum the number of arguments\n";
    std::cout << "----------------------------------\n";
}

void Commands::cmdClear() {
    std::cout << "\033[2J\033[1;1H";
}

void Commands::cmdSum(const int a, const int b) {
    std :: cout << a << " + " << b << " = " << a + b << "\n";
}