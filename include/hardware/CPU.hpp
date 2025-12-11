








#pragma once
#include "Types.hpp"
#include "RAM.hpp"

struct Registers {
    Word AX = 0; // Accumulator
    Word BX = 0; // Base
    Word CX = 0; // Counter
    Word DX = 0; // Data

    Address PC = 0; // Program Counter (Instruction Pointer)
    Address SP = 0; // Stack Pointer
    Address BP = 0; // Base Pointer

    Word FLAGS = 0;
};

class CPU {
private:
    Registers regs;
    RAM& ramSystem;

public:
    explicit CPU(RAM& ramSystem);

    void reset();

    bool step();

    [[nodiscard]] Registers getRegisters() const;

    void printRegisters() const;

private:
    Byte fetch();

    void decodeAndExecute(Byte code);
};
