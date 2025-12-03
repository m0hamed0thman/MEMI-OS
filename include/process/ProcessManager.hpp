#ifndef PROCESS_MANAGER_HPP
#define PROCESS_MANAGER_HPP

#include "Process.hpp"
#include <vector>
#include <map>
#include <string>

class ProcessManager {
private:

    std::vector<Process*> processTable;

    int nextPID;

public:

    ProcessManager();

    ~ProcessManager();


    int createProcess(const std::string& name);


    bool killProcess(int pid);


    Process* getProcess(int pid);


    std::string listProcesses() const;

};

#endif