// Copyright 2024 Michael White 
#include <include/cpu.h>

CPU::CPU() {}

void CPU::execute(Instruction& instruction) {
    InstructionType type = instruction.type_; 
    ArithmeticTarget target = instruction.target;
    switch (target) {
    case ArithmeticTarget::A :
        break;
    case ArithmeticTarget::B :
        break;
    case ArithmeticTarget::C :
        auto val = REGISTERS.c; 
        auto new_val = add(val);
        REGISTERS.a = new_val;
        break;
    case ArithmeticTarget::D :
        break;
    case ArithmeticTarget::E :
        break;
    case ArithmeticTarget::H :
        break;
    // Default register is L
    default:
        break;
    }
}

// Instruction to add a uint8_t value
// @param value uint8_t Value to be added
// @return uint8_t
uint8_t CPU::add(uint8_t value) {
    uint8_t new_value = REGISTERS.a + value;
    bool did_overflow = new_value < REGISTERS.a;
    // TODO: set flags
    return new_value;
}
