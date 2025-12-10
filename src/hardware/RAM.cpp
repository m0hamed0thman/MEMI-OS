








#include "../../include/hardware/RAM.hpp"
#include "../../include/kernel/logging/Logger.hpp"
#include <cstring>
#include <iomanip>


RAM::RAM(size_t size) {
    Logger::log(LogLevel::INFO,"[Hardware] RAM initialized.");
    memory.resize(size);
}


Byte RAM::read(Address addr) const {
    if (addr >= memory.size()) {
        Logger::log(LogLevel::ERROR,"[Hardware Error] Segmentation Fault: Read at address.");
        return 0;
    }
    return memory[addr];
}


void RAM::write(Address addr, Byte val) {
    if (addr >= memory.size()) {
        Logger::log(LogLevel::ERROR,"[Hardware Error] Segmentation Fault: Write at address.");
        return;
    }
    memory[addr] = val;
}


void RAM::loadProgram(Address addr, std::vector<Byte> data) {
    if (addr + data.size() > memory.size()) {
        Logger::log(LogLevel::ERROR,"Not enough memory to Load Program");
        return;
    }
    for (size_t i = 0; i < data.size(); ++i) {
        memory[addr + i] = data[i];
    }
}


void RAM::dump(Address addrStart, Address addrEnd) const {

    std::cout << "\n--- RAM DUMP [" << addrStart << " to " << addrEnd << "] ---\n";

    if (addrEnd >= memory.size()) addrEnd = memory.size() - 1;
    if (addrStart > addrEnd) return;

    for (Address i = addrStart; i <= addrEnd; ++i) {
        if ((i - addrStart) % 16 == 0) {
            if (i != addrStart) std::cout << "\n";
            std::cout << "0x" << std::setw(4) << std::setfill('0') << std::hex << i << ": ";
        }
        std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)memory[i] << " ";
    }
    std::cout << std::dec << "\n----------------------------------\n" << std::endl;
}


size_t RAM::getSize() const {
    return memory.size();
}