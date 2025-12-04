#include "../../../include/process/ProcessManager.hpp"

#include <iostream>

ProcessManager::ProcessManager() {

    nextPID = 100;

}
ProcessManager::~ProcessManager() {
    for (auto it = processTable.begin(); it != processTable.end(); it++) {
        delete (*it);
    }
    processTable.clear();
}


int ProcessManager::createProcess(const std::string &name) {


    int processSize = 64;
    int address = memoryManager.allocate(processSize,nextPID);

    if (address==-1) {
        std::cerr << "Error: Not enough memory to create process '" << name << "'\n";
        return -1;
    }

    Process* newProcess = new Process(nextPID, name,10);

    nextPID++;

    processTable.push_back(newProcess);

    return newProcess->getPID();
}

bool ProcessManager::killProcess(int pid) {

    for (auto it = processTable.begin(); it != processTable.end(); it++) {
        if ((*it)->getPID() == pid) {

            memoryManager.deallocate(pid);
            delete (*it);

            processTable.erase(it);

            return true;
        }
    }
    return false;
}

Process *ProcessManager::getProcess(int pid) {

    for (auto it = processTable.begin(); it != processTable.end(); it++) {
        if ((*it)->getPID() == pid) {
            return *it;
        }
    }
    return NULL;
}

std::string ProcessManager::listProcesses() const {
    if (processTable.empty()) {
        return "No active processes.\n";
    }

    std::string list = "PID\tState\t\tName\n";
    list += "------------------------------------\n";

    for (const auto& p : processTable) {

        list += std::to_string(p->getPID()) + "\t" +
                p->stateToString() + "\t" +
                p->getName() + "\n";
    }
    return list;
}




