#ifndef PROCESS_H
#define PROCESS_H


#include <string>
enum class ProcessState {
    READY,
    RUNNING,
    BLOCKED,
    TERMINATED
};

class Process {

private:
    int pid;
    std::string name;
    ProcessState state;

    int programCounter;
    int totalInstructions;

public:

    Process(int id, std::string n, int instructionsCount = 10);


    int getPID() const;
    std::string getName() const;
    ProcessState getState() const;
    int getPC() const;
    int getTotalInstructions() const;


    void setState(ProcessState s);



    bool executeOneStep();


    std::string stateToString() const;
};

#endif
