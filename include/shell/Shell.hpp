#ifndef SHELL_HPP
#define SHELL_HPP

#include "../fileSystem/FileSystem.hpp"

class Shell {
private:
    FileSystem fileSystem;
public:
    void run();
};

#endif