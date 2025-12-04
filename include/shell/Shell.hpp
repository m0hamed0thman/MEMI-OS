#ifndef SHELL_HPP
#define SHELL_HPP

#include "../fileSystem/FileSystem.hpp"
#include "../process/ProcessManager.hpp"
class Shell {
private:
    FileSystem fileSystem;
    ProcessManager pm;
public:
    void run();
};

#endif