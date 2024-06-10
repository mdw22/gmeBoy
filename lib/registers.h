#ifndef REGISTER_H
#define REGISTER_H

#include <cstdint>

class Registers {
    public : 
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
};

#endif // REGISTER_H