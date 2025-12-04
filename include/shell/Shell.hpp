#ifndef SHELL_HPP
#define SHELL_HPP

#include "../fileSystem/FileSystem.hpp"
#include "../process/ProcessManager.hpp"
#include "../process/Scheduler.hpp"
class Shell {
private:
    FileSystem fileSystem;
    ProcessManager pm;
    Scheduler scheduler;
public:
    void run();
};

#endif