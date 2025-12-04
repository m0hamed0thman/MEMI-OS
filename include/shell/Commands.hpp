#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include <vector>
#include "../fileSystem/FileSystem.hpp"
#include "../../include/process/ProcessManager.hpp"
class Commands {
public:


    // if return true continue else exit the program
    // static bool execute(const std::string& cmd, const std::vector<std::string>& args);
    static bool execute(const std::string& cmd, const std::vector<std::string>& args, FileSystem& fs, ProcessManager& pm);
private:

    static void cmdHelp();
    static void cmdClear();
    static void cmdSum(const int a, const int b);

};

#endif