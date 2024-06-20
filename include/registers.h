// Copyright 2024 Michael White
#ifndef _GMEBOY_INCLUDE_REGISTERS_H_
#define _GMEBOY_INCLUDE_REGISTERS_H_

#include <cstdint>

struct FlagsRegister {
        bool zero;
        bool subtract;
        bool half_carry;
        bool carry;
};

class Register {
 public:
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    FlagsRegister f;
    uint8_t h;
    uint8_t l;

    uint16_t get_bc() const;

    uint16_t get_af() const;

    uint16_t get_de() const;

    uint16_t get_hl() const;

    void set_bc(u_int16_t value);

    void set_af(u_int16_t value);

    void set_de(u_int16_t value);

    void set_hl(u_int16_t value);
};

const uint8_t ZERO_FLAG_BYTE_POSITION = 7;
const uint8_t SUBTRACT_FLAG_BYTE_POSITION = 6;
const uint8_t HALF_CARRY_FLAG_BYTE_POSITION = 5;
const uint8_t CARRY_FLAG_BYTE_POSITION = 4;

uint8_t flagsRegisterToByte(const FlagsRegister& flag);

FlagsRegister byteToFlagsRegister(uint8_t byte);

#endif  // _GMEBOY_INCLUDE_REGISTERS_H_
