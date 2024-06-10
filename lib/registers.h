#ifndef REGISTER_H
#define REGISTER_H

#include <cstdint>

const uint8_t ZERO_FLAG_BYTE_POSITION = 7;
const uint8_t SUBTRACT_FLAG_BYTE_POSITION = 6;
const uint8_t HALF_CARRY_FLAG_BYTE_POSITION = 5;
const uint8_t CARRY_FLAG_BYTE_POSITION = 4;

struct FlagsRegister {
    bool zero;
    bool subtract;
    bool half_carry;
    bool carry;
};

uint16_t get_bc();

uint16_t get_af();

uint16_t get_de();

uint16_t get_hl();

void set_bc(u_int16_t value);

void set_af(u_int16_t value);

void set_de(u_int16_t value);

void set_hl(u_int16_t value);

uint8_t flagsRegisterToByte(const FlagsRegister& flag);

FlagsRegister byteToFlagsRegister(uint8_t byte);

#endif // REGISTER_H