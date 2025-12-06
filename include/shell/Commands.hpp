








#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include <string>
#include <vector>
#include "../fileSystem/FileSystem.hpp"
#include "../../include/process/ProcessManager.hpp"

class Scheduler;
class Commands {
public:
    // if return true continue else exit the program
    // static bool execute(const std::string& cmd, const std::vector<std::string>& args);
    static bool execute(const std::string& cmd, const std::vector<std::string>& args, FileSystem& fs, ProcessManager& pm,Scheduler& scheduler );
private:
    // === System Commands ===
    static void cmdHelp();
    static void cmdClear();
    static void cmdExit();

    // === File System Commands ===
    static void cmdLs(FileSystem& fs);
    static void cmdPwd(FileSystem& fs);
    static void cmdMkdir(const std::vector<std::string>& args, FileSystem& fs);
    static void cmdTouch(const std::vector<std::string>& args, FileSystem& fs);
    static void cmdCd(const std::vector<std::string>& args, FileSystem& fs);
    static void cmdCat(const std::vector<std::string>& args, FileSystem& fs);
    static void cmdWrite(const std::vector<std::string>& args, FileSystem& fs);
    static void cmdReWrite(const std::vector<std::string>& args, FileSystem& fs);
    static void cmdClean(const std::vector<std::string>& args, FileSystem& fs);
    static void cmdRun(const std::vector<std::string> &args, FileSystem &fs, ProcessManager &pm, Scheduler &sch);

    // === Process Commands ===
    static void cmdPs(ProcessManager& pm);
    static void cmdExec(const std::vector<std::string>& args, ProcessManager& pm, Scheduler& sch);
    static void cmdKill(const std::vector<std::string>& args, ProcessManager& pm);

    // === Memory Commands ===
    static void cmdFree(ProcessManager& pm);
};
#endif

