








#include "../../include/hardware/RAM.hpp"
#include <iostream>
#include <cassert>


void assert_test(bool condition, const std::string& testName) {
    if (condition) {
        std::cout << "[PASS] " << testName << std::endl;
    } else {
        std::cout << "[FAIL] " << testName << std::endl;
        exit(1);
    }
}

int main() {
    std::cout << "=== Running RAM Unit Tests ===\n";
    size_t ramSize = 1024; // 1 KB for testing
    RAM ram(ramSize);


    ram.write(10, 0xAB);
    Byte val = ram.read(10);
    assert_test(val == 0xAB, "Basic Read/Write");


    ram.write(2000, 0xFF); 
    Byte outVal = ram.read(2000);
    assert_test(outVal == 0, "Out of Bounds Handling");


    std::vector<Byte> program = {0x01, 0x02, 0x03, 0x04};
    ram.loadProgram(100, program);
    
    bool loadSuccess = (ram.read(100) == 0x01) && (ram.read(103) == 0x04);
    assert_test(loadSuccess, "Load Program Bulk Copy");


    assert_test(ram.getSize() == 1024, "RAM Size Check");

    std::cout << "\nAll RAM Tests Passed Successfully! \n";
    return 0;
}