

#include "../../../include/process/Scheduler.hpp"

Scheduler::Scheduler() {
    currentProcess = nullptr;
    tickCounter = 0 ;
    timeQuantum = 3 ;
}

Scheduler::~Scheduler() {

}

void Scheduler::addProcess(Process* process) {

    process->setState(ProcessState::READY);
    processQueue.push(process);

}

bool Scheduler::hasProcesses() const {

    return currentProcess != nullptr || !processQueue.empty();
}

Process *Scheduler::getCurrentProcess() const {

    return currentProcess;

}

void Scheduler::schedule() {

    if (currentProcess == nullptr) {
        if (processQueue.empty()) {
            return;
        }
        currentProcess = processQueue.front();
        processQueue.pop();
        currentProcess->setState(ProcessState::RUNNING);
        tickCounter=0;
    }

    if (currentProcess != nullptr) {
        bool stillRunning = currentProcess->executeOneStep();
        tickCounter++;

        if (!stillRunning) {
            // we handeld this in the excute function
            // currentProcess->setState(ProcessState::TERMINATED);

            tickCounter=0;
            currentProcess = nullptr;
        }else {
            if (tickCounter >= timeQuantum) {

                currentProcess->setState(ProcessState::READY);
                processQueue.push(currentProcess);
                currentProcess = nullptr;
                tickCounter = 0;
            }
        }
    }
}



