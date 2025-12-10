








#ifndef RAM_HPP
#define RAM_HPP
#include <vector>
#include <iostream>
#include "Types.hpp"

class RAM {
private:

    std::vector<Byte> memory;

public:
    explicit RAM(size_t size);

    Byte read(Address addr) const ;

    void write(Address addr, Byte data) ;

    void loadProgram(Address addr, std::vector<Byte> data) ;

    size_t getSize() const;

    void dump(Address addrStart, Address addrEnd) const ;

};

#endif