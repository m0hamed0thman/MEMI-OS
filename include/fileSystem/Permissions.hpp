








#ifndef PERMISSIONS_HPP
#define PERMISSIONS_HPP
#include <string>

struct Permissions {
    bool read;
    bool write;
    bool execute;
    std::string owner;


    Permissions(bool r = true, bool w = true, bool x = false, std::string o = "root")
        : read(r), write(w), execute(x), owner(o) {}


    std::string toString() const {
        std::string res = "";
        res += (read ? "r" : "-");
        res += (write ? "w" : "-");
        res += (execute ? "x" : "-");
        return res;
    }
};

#endif

