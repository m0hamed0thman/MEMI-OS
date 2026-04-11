#ifndef BLOCK_HPP
#define BLOCK_HPP

struct Block {
    int startAddress;
    int size;
    bool isFree;
    int processID;

    Block(int start, int sz, bool free = true, int pid = -1)
        : startAddress(start), size(sz), isFree(free), processID(pid) {}
};

#endif