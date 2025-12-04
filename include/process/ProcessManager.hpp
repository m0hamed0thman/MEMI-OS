#ifndef PROCESS_MANAGER_HPP
#define PROCESS_MANAGER_HPP

#include "Process.hpp"
#include <vector>
#include <map>
#include <string>


#include "../../include/memory/MemoryManager.hpp"

class ProcessManager {
private:

    std::vector<Process*> processTable;
    MemoryManager memoryManager;
    int nextPID;

public:

    ProcessManager();

    ~ProcessManager();


    int createProcess(const std::string& name);


    bool killProcess(int pid);


    Process* getProcess(int pid);


    std::string listProcesses() const;

    std::string getMemoryStatus() const {
        return memoryManager.getStatus();
    }

};

#endif