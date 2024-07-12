// Copyright 2024 Michael White 
#include "cpu.h"

CPU::CPU() {}

void CPU::execute(Instruction& instruction) {
    InstructionType type = instruction.type_; 
    ArithmeticTarget target = instruction.target;
    switch (type)
    {
    case InstructionType::ADD:
        executeFunc(target, CPU::add);
        break;
    case InstructionType::ADDHL:
        executeFunc(target, CPU::addhl);
        break;
    case InstructionType::ADC:
        executeFunc(target, CPU::adc);
        break;
    case InstructionType::SUB:
        executeFunc(target, CPU::sub);
        break;
    default:
        break;
    }
}

uint8_t CPU::add(uint8_t value) {
    uint8_t new_value = REGISTERS.a + value;
    bool did_overflow = new_value < REGISTERS.a;
    REGISTERS.f.zero = new_value == 0;
    REGISTERS.f.carry = did_overflow;
    REGISTERS.f.subtract = false;
    REGISTERS.f.half_carry = (REGISTERS.a & 0xF) + (value & 0xF) > 0xF;
    return new_value;
}

uint8_t CPU::addhl(uint8_t value) {
    uint8_t new_value = REGISTERS.get_hl() + value;
    bool did_overflow = new_value < REGISTERS.get_hl();
    REGISTERS.f.zero = new_value == 0;
    REGISTERS.f.carry = did_overflow;
    REGISTERS.f.subtract = false;
    REGISTERS.f.half_carry = (REGISTERS.get_hl() & 0xF) + (value & 0xF) > 0xF;
    return new_value; 
}

uint8_t CPU::adc(uint8_t value) {
    uint8_t new_value = REGISTERS.a + value;
    bool did_overflow = new_value < REGISTERS.a;
    REGISTERS.f.zero = new_value == 0;
    REGISTERS.f.carry = did_overflow;
    REGISTERS.f.subtract = false;
    REGISTERS.f.half_carry = (REGISTERS.a & 0xF) + (value & 0xF) > 0xF;
    return new_value + REGISTERS.f.carry;
}

uint8_t CPU::sub(uint8_t value) {
    uint8_t new_value = REGISTERS.a - value;
    bool did_overflow = new_value > value;
    REGISTERS.f.zero = new_value == 0;
    REGISTERS.f.carry = did_overflow;
    REGISTERS.f.subtract = true;
    REGISTERS.f.half_carry = (REGISTERS.a & 0xF) - (value & 0xF) < 0xF; 
    // TO-DO: Finish func def, ensure half_carry math is correct
    return new_value;
}

void CPU::executeFunc(ArithmeticTarget target, uint8_t (CPU::*func)(uint8_t)) {
    size_t index = static_cast<size_t>(target);
    using FuncType = std::function<void()>;
    // Lambda to wrap the execution logic
    auto execute_lambda = [this, func](uint8_t& val) {
        val = (this->*func)(val);
    };
    // Array of handlers for each ArithmeticTarget
    std::array<FuncType, 7> handlers = {
        [this, execute_lambda] {
            auto val = REGISTERS.a;
            execute_lambda(val); 
            REGISTERS.a = val;
            }, // A
        [this, execute_lambda] {
            auto val = REGISTERS.b;
            execute_lambda(val); 
            REGISTERS.a = val;
            }, // B
        [this, execute_lambda] {
            auto val = REGISTERS.c;
            execute_lambda(val); 
            REGISTERS.a = val;
            }, // C
        [this, execute_lambda] {
            auto val = REGISTERS.d;
            execute_lambda(val); 
            REGISTERS.a = val;
            }, // D
        [this, execute_lambda] {
            auto val = REGISTERS.e;
            execute_lambda(val); 
            REGISTERS.a = val;
            }, // E
        [this, execute_lambda] {
            auto val = REGISTERS.h;
            execute_lambda(val); 
            REGISTERS.a = val;
            }, // H
        [this, execute_lambda] {
            auto val = REGISTERS.l;
            execute_lambda(val); 
            REGISTERS.a = val;
            } // L
    };
    // Execute the appropriate handler
    handlers[static_cast<size_t>(target)]();
}
