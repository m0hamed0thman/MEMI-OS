#ifndef MEMORY_MANAGER_HPP
#define MEMORY_MANAGER_HPP

#include "Block.hpp"
#include <vector>
#include <string>

class MemoryManager {
private:
    std::vector<Block> memoryMap;
    int totalMemory;

public:
    MemoryManager(int size = 1024);


    int allocate(int size, int pid);

    void deallocate(int pid);


    std::string getStatus() const;
};

#endif