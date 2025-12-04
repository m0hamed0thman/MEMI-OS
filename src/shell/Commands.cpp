
#include "../../include/kernel/logging/Logger.hpp"
#include "../../include/shell/Commands.hpp"

#include "../../include/fileSystem/FileSystem.hpp"
#include <iostream>
#include <algorithm>

std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

bool Commands::execute(const std::string &cmd, const std::vector<std::string> &args, FileSystem& fs, ProcessManager& pm) {

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
    }
    else if (command == "ps") {

        std::cout << pm.listProcesses();
    }
    else if (command == "exec") {

        if (args.size() < 2) {
            std::cout << "Usage: exec <program_name>\n";
        } else {

            int pid = pm.createProcess(args[1]);
            std::cout << "Process created with PID: " << pid << "\n";
            Logger::log(LogLevel::INFO, "Process created: " + args[1]);
        }
    }
    else if (command == "kill") {

        if (args.size() < 2) {
            std::cout << "Usage: kill <pid>\n";
        } else {
            try {
                int pid = std::stoi(args[1]);
                if (pm.killProcess(pid)) {
                    std::cout << "Process " << pid << " killed successfully.\n";
                    Logger::log(LogLevel::INFO, "Killed process PID: " + std::to_string(pid));
                } else {
                    std::cout << "Error: Process " << pid << " not found.\n";
                }
            } catch (...) {
                std::cout << "Error: Invalid PID format.\n";
            }
        }
    }

    else {
        std::cout << "Unknown command: " << cmd << "\n";
    }

    return true;
}


void Commands::cmdHelp() {
    std::cout << "\n================= MIME-OS v0.1 Help =================\n";


    std::cout << "[System Commands]\n";
    std::cout << "  help, ?      : Show this help menu\n";
    std::cout << "  clear, cls   : Clear the screen\n";
    std::cout << "  exit, quit   : Shutdown the system\n";

    std::cout << "\n[File System]\n";
    std::cout << "  ls, dir      : List files and directories\n";
    std::cout << "  pwd          : Print working directory\n";
    std::cout << "  cd <path>    : Change directory (use .. to go back)\n";
    std::cout << "  mkdir <name> : Create a new directory\n";
    std::cout << "  touch <name> : Create a new empty file\n";
    std::cout << "  cat <name>   : Display file content\n";
    std::cout << "  write <name> <text> : Write text to a file\n";


    std::cout << "\n[Process Management]\n";
    std::cout << "  ps           : List all active processes\n";
    std::cout << "  exec <name>  : Run a new program (create process)\n";
    std::cout << "  kill <pid>   : Terminate a process by its ID\n";

    std::cout << "=====================================================\n";
}

void Commands::cmdClear() {
    std::cout << "\033[2J\033[1;1H";
}

void Commands::cmdSum(const int a, const int b) {
    std :: cout << a << " + " << b << " = " << a + b << "\n";
}