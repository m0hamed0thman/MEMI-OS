#include "../../include/hardware/RAM.hpp"
#include "../../include/hardware/CPU.hpp"
#include <iostream>
#include <cassert>
#include <vector>

void assert_test(bool condition, const std::string& testName) {
    if (condition) std::cout << "[PASS] " << testName << std::endl;
    else { std::cout << "[FAIL] " << testName << std::endl; exit(1); }
}

int main() {
    std::cout << "=== Running CPU Unit Tests ===\n";

    RAM ram(1024);
    CPU cpu(ram);

    // 2. Load a simple program into RAM
    // Program: 
    // 0x01, 0x05  -> MOV AX, 5
    // 0x01, 0x02  -> MOV AX, 2 (Overwrites previous)
    // 0xFF        -> HALT
    std::vector<Byte> program = { 0x01, 0x05, 0x01, 0x02, 0xFF };
    ram.loadProgram(0, program);

    std::cout << "DEBUG: Checking RAM content..." << std::endl;
    ram.dump(0, 5);

    // 3. Execute
    // Step 1: MOV AX, 5
    cpu.step(); 
    assert_test(cpu.getRegisters().AX == 5, "Execute: MOV AX, 5");
    assert_test(cpu.getRegisters().PC == 2, "PC Increment (Opcode + Operand)");

    // Step 2: MOV AX, 2
    cpu.step();
    assert_test(cpu.getRegisters().AX == 2, "Execute: MOV AX, 2");

    // Step 3: HALT
    bool running = cpu.step();
    assert_test(!running, "Execute: HALT instruction");

    std::cout << "\nAll CPU Tests Passed!\n";
    return 0;
}