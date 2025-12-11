








#include "hardware/CPU.hpp"

CPU::CPU(RAM &ramSystem): ramSystem(ramSystem) {
    reset();
}

void CPU::reset() {

    regs = Registers();
    regs.SP = ramSystem.getSize() -1 ;
    regs.PC = 0 ;
}


Byte CPU::fetch() {
    Byte data = ramSystem.read(regs.PC);
    regs.PC++;
    return data;
}


[[nodiscard]] Registers CPU::getRegisters() const {
    return regs;
}


void CPU::decodeAndExecute(Byte opcode) {
    switch (opcode) {
        case 0x00:
            break;

        case 0x01: {
            Byte value = fetch();
            regs.AX = value;
            break;
        }
        case 0xFF:
            break;

        default:
            break;
    }
}


bool CPU::step() {

    Byte opcode = fetch();

    if (opcode == 0xFF) {
        return false;
    }

    decodeAndExecute(opcode);
    return true;
}

void CPU::printRegisters() const {
    std::cout << "--- CPU STATE ---\n"
              << "AX: 0x" << std::hex << regs.AX << "  "
              << "BX: 0x" << std::hex << regs.BX << "\n"
              << "PC: 0x" << std::hex << regs.PC << "  "
              << "SP: 0x" << std::hex << regs.SP << "\n"
              << "-----------------\n" << std::dec;
}


