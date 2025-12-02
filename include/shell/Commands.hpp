#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include <vector>

class Commands {
public:


    // if return true continue else exit the program
    static bool execute(const std::string& cmd, const std::vector<std::string>& args);

private:

    static void cmdHelp();
    static void cmdClear();
    static void cmdSum(const int a, const int b);

};

#endif