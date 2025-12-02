#ifndef PCB_H
#define PCB_H

#include "/home/mohamed-othman/CLionProjects/MIME_OS/include/Process.hpp"

#include <string>
#include <vector>


using namespace std;

class PCB {

    int PID;
    string processName;
    enum Status { Ready, Running, Stopped, Terminated };
    Status status;
    int priority;
    int programCounter;
    int registers[16];
    int memoryStart;
    int memoryEnd;
    Process* processPtr;
    bool isIOBound;
    int burstTime;
    int remainingTime;
    int arrivalTime;
    int waitingTime;

};