// Copyright 2024 Michael White 
#include "cpu.h"

CPU::CPU() {}

void CPU::execute(Instruction& instruction) {
    InstructionType type = instruction.type_; 
    ArithmeticTarget target = instruction.target;
    switch (type)
    {
    case InstructionType::ADD:
        executeAdd(target);
        break;
    case InstructionType::ADDHL:
        executeAddHL(target);
        break;
    case InstructionType::ADC:
        executeAddWithCarry(target);
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
}

void CPU::executeAdd(ArithmeticTarget target) {
    using FuncType = std::function<void()>;
    std::array<FuncType, 7> handlers = {
        [this] {
            auto val = REGISTERS.a;
            auto new_val = add(val);
            REGISTERS.a = new_val;
        },
        [this] {
            auto val = REGISTERS.b;
            auto new_val = add(val);
            REGISTERS.a = new_val;
        },
        [this] {
            auto val = REGISTERS.c;
            auto new_val = add(val);
            REGISTERS.a = new_val;
        },
        [this] {
            auto val = REGISTERS.d;
            auto new_val = add(val);
            REGISTERS.a = new_val;
        },
        [this] {
            auto val = REGISTERS.e;
            auto new_val = add(val);
            REGISTERS.a = new_val;
        },
        [this] {
            auto val = REGISTERS.h;
            auto new_val = add(val);
            REGISTERS.a = new_val;
        },
        [this] {
            auto val = REGISTERS.l;
            auto new_val = add(val);
            REGISTERS.a = new_val;
        },
    };
    size_t index = static_cast<size_t>(target);
    if (index < handlers.size()) {
        handlers[index]();
    } else {
        std::cout << "Error: Out of range target Register." << std::endl;
    }
}

void CPU::executeAddHL(ArithmeticTarget target) {
    using FuncType = std::function<void()>;
    std::array<FuncType, 7> handlers = {
        [this] {
            auto val = REGISTERS.a;
            auto new_val = addhl(val);
            REGISTERS.set_hl(new_val);
        },
        [this] {
            auto val = REGISTERS.b;
            auto new_val = addhl(val);
            REGISTERS.set_hl(new_val);
        },
        [this] {
            auto val = REGISTERS.c;
            auto new_val = addhl(val);
            REGISTERS.set_hl(new_val);
        },
        [this] {
            auto val = REGISTERS.d;
            auto new_val = addhl(val);
            REGISTERS.set_hl(new_val);
        },
        [this] {
            auto val = REGISTERS.e;
            auto new_val = addhl(val);
            REGISTERS.set_hl(new_val);
        },
        [this] {
            auto val = REGISTERS.h;
            auto new_val = addhl(val);
            REGISTERS.set_hl(new_val);
        },
        [this] {
            auto val = REGISTERS.l;
            auto new_val = addhl(val);
            REGISTERS.set_hl(new_val);
        }
    };
    size_t index = static_cast<size_t>(target);
    if (index < handlers.size()) {
        handlers[index]();
    } else {
        std::cout << "Error: Out of range target Register." << std::endl;
    }
}

void CPU::executeAddWithCarry(ArithmeticTarget target) {
    using FuncType = std::function<void()>;
    std::array<FuncType, 7> handlers = {
        [this] {
            auto val = REGISTERS.a;
            auto new_val = adc(val);
            REGISTERS.a = new_val;
        },
        [this] {
            auto val = REGISTERS.b;
            auto new_val = adc(val);
            REGISTERS.a = new_val;
        },
        [this] {
            auto val = REGISTERS.c;
            auto new_val = adc(val);
            REGISTERS.a = new_val;
        },
        [this] {
            auto val = REGISTERS.d;
            auto new_val = adc(val);
            REGISTERS.a = new_val;
        },
        [this] {
            auto val = REGISTERS.e;
            auto new_val = adc(val);
            REGISTERS.a = new_val;
        },
        [this] {
            auto val = REGISTERS.h;
            auto new_val = adc(val);
            REGISTERS.a = new_val;
        },
        [this] {
            auto val = REGISTERS.l;
            auto new_val = adc(val);
            REGISTERS.a = new_val;
        },
    };
    size_t index = static_cast<size_t>(target);
    if (index < handlers.size()) {
        handlers[index]();
    } else {
        std::cout << "Error: Out of range target Register." << std::endl;
    }
}

// TO-DO : Implement executeSub() func
