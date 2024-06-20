// Copyright 2024 Michael White
#include "registers.h"

uint16_t Register::get_bc() const {
    return static_cast<uint16_t>(b) << 8 | static_cast<uint16_t>(c);
}

uint16_t Register::get_af() const {
    return static_cast<uint16_t>(a) << 8 | flagsRegisterToByte(f);
}

uint16_t Register::get_de() const {
    return static_cast<uint16_t>(d) << 8 | static_cast<uint16_t>(e);
}
uint16_t Register::get_hl() const {
    return static_cast<uint16_t>(h) << 8 | static_cast<uint16_t>(l);
}

void Register::set_bc(u_int16_t value) {
    b = (static_cast<uint8_t>(value & 0xFF00) >> 8);
    c = (static_cast<uint8_t>(value & 0xFF));
}

void Register::set_af(u_int16_t value) {
    a = (static_cast<uint8_t>(value & 0xFF00) >> 8);
    f = byteToFlagsRegister((static_cast<uint8_t>(value & 0xFF)));
}

void Register::set_de(u_int16_t value) {
    d = (static_cast<uint8_t>(value & 0xFF00) >> 8);
    e = (static_cast<uint8_t>(value & 0xFF));
}

void Register::set_hl(u_int16_t value) {
    h = (static_cast<uint8_t>(value & 0xFF00) >> 8);
    l = (static_cast<uint8_t>(value & 0xFF));
}

// Convert FlagsRegister to uint8_t
uint8_t flagsRegisterToByte(const FlagsRegister& flag) {
    return (flag.zero ? 1 : 0) << ZERO_FLAG_BYTE_POSITION |
            (flag.subtract ? 1 : 0) << SUBTRACT_FLAG_BYTE_POSITION |
            (flag.half_carry ? 1 : 0) << HALF_CARRY_FLAG_BYTE_POSITION | 
            (flag.carry ? 1 : 0) << CARRY_FLAG_BYTE_POSITION;
}

// Convert uint8_t to FlagsRegister
FlagsRegister byteToFlagsRegister(uint8_t byte) {
    FlagsRegister flag;
    flag.zero = ((byte >> ZERO_FLAG_BYTE_POSITION) & 0b1) != 0;
    flag.subtract = ((byte >> SUBTRACT_FLAG_BYTE_POSITION) & 0b1) != 0;
    flag.half_carry = ((byte >> HALF_CARRY_FLAG_BYTE_POSITION) & 0b1) != 0;
    flag.carry = ((byte >> CARRY_FLAG_BYTE_POSITION) & 0b1) != 0;
    return flag; 
}
