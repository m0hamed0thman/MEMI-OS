#include "../../../include/process/ProcessManager.hpp"



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

    Process* newProcess = new Process(nextPID, name);

    nextPID++;

    processTable.push_back(newProcess);

    return newProcess->getPID();
}

bool ProcessManager::killProcess(int pid) {

    for (auto it = processTable.begin(); it != processTable.end(); it++) {
        if ((*it)->getPID() == pid) {

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




