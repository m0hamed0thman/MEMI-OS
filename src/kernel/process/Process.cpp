#include "/home/mohamed-othman/CLionProjects/MIME_OS/include/Process.hpp"
#include <stdexcept>

int Process::globalCounter = 0;

bool Process::check_name(const string& name) {
    if (name == "null" || name.size() <4) {
        return false;
    }
    return true;
}

string Process::statusToString() const {
    switch(status) {
        case Ready: return "Ready";
        case Running: return "Running";
        case Stopped: return "Stopped";
        case Terminated: return "Terminated";
    }
    return "Unknown";
}

Process::Process(string name): PID(globalCounter++) {
    if (check_name(name)) {
        this->name = name;
        this->status = Ready;
    } else {
        throw runtime_error("Error while creating process");
    }
}

bool Process::start() {
    if (this->status == Terminated) {
        return false;
    }
    this->status = Running;
    return true;
}

bool Process::stop() {
    if (this->status == Terminated) {
        return false;
    }
    this->status = Stopped;
    return true;
}

void Process::terminate() {
    status = Terminated;
}

int Process::getPID() const {
    return this->PID;
}

string Process::getName() const {
    return this->name;
}

string Process::getStatus() const {
    return statusToString();
}

void Process::display() const {
    cout << "PID: " << this->PID << endl;
    cout << "Name: " << this->name << endl;
    cout << "Status: " << statusToString() << endl;
}
