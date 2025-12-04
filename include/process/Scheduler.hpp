


#include <queue>

#include "Process.hpp"

class Scheduler {
private:

    std::queue<Process*> processQueue;
    Process* currentProcess;
    int timeQuantum;
    int tickCounter;

    public:

    Scheduler();
    ~Scheduler();


    void addProcess(Process* process);
    void schedule();
    Process* getCurrentProcess() const ;
    bool hasProcesses() const;

};