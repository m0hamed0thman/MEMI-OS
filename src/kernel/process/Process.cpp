#include "/home/mohamed-othman/CLionProjects/MIME_OS/include/process/Process.hpp"


Process::Process(int id, std::string n, int instructionsCount)
    : pid(id), name(n), totalInstructions(instructionsCount)
{
    state = ProcessState::READY;
    programCounter = 0;
}



int Process::getPID() const { return pid; }
std::string Process::getName() const { return name; }
ProcessState Process::getState() const { return state; }
int Process::getPC() const { return programCounter; }
int Process::getTotalInstructions() const { return totalInstructions; }



void Process::setState(ProcessState s) {
    state = s;
}



bool Process::executeOneStep() {

    if (state == ProcessState::TERMINATED) return false;


    programCounter++;


    if (programCounter >= totalInstructions) {
        state = ProcessState::TERMINATED;
        return false;
    }

    return true;
}

std::string Process::stateToString() const {
    switch (state) {
        case ProcessState::READY:      return "READY";
        case ProcessState::RUNNING:    return "RUNNING";
        case ProcessState::BLOCKED:    return "BLOCKED";
        case ProcessState::TERMINATED: return "TERMINATED";
        default:                       return "UNKNOWN";
    }
}

