#include "../../../include/memory/MemoryManager.hpp"



MemoryManager::MemoryManager(int size) {
    Block GigBlock = Block(0, size);
    memoryMap.push_back(GigBlock);
}

int MemoryManager::allocate(int size, int pid) {

    for (auto it = memoryMap.begin(); it != memoryMap.end(); ++it) {


        if (it->isFree && it->size >= size) {

            if (it->size == size) {

                it->isFree = false;
                it->processID = pid;
                return it->startAddress;
            }

            else if (it->size > size) {

                int originalAddress = it->startAddress;


                int newStart = originalAddress + size;
                int newSize = it->size - size;


                it->size = size;
                it->isFree = false;
                it->processID = pid;


                Block newFreeBlock(newStart, newSize, true, -1);


                memoryMap.insert(it + 1, newFreeBlock);

                return originalAddress;
            }
        }
    }
    return -1;
}

void MemoryManager::deallocate(int pid) {



    for (auto& block : memoryMap) {
        if (block.processID == pid) {
            block.isFree = true;
            block.processID = -1;
        }
    }


    for (auto it = memoryMap.begin(); it != memoryMap.end() - 1; ) {

        auto next = it + 1;


        if (it->isFree && next->isFree) {

            it->size += next->size;

            memoryMap.erase(next);

        } else {
            ++it;
        }
    }


}

std::string MemoryManager::getStatus() const {
    int freeMem = 0;
    int usedMem = 0;
    for (const auto& block : memoryMap) {
        if (block.isFree) freeMem += block.size;
        else usedMem += block.size;
    }
    return "Total: " + std::to_string(totalMemory) +
           " | Used: " + std::to_string(usedMem) +
           " | Free: " + std::to_string(freeMem);
}