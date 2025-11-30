#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <string>
using namespace std;

class Process {
    static int globalCounter;
    int const PID ;
    string name;
    enum Status { Ready, Running, Stopped, Terminated };
    Status status;

    bool check_name(const string& name);
    string statusToString() const;

public:
    Process(string name);
    bool start();
    bool stop();
    void terminate();
    int getPID() const;
    string getName() const;
    string getStatus() const;
    void display() const;
};

#endif
