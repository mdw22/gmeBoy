#ifndef REGISTER_H
#define REGISTER_H

#include <cstdint>

class Register {
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

        uint16_t get_bc() const;

        uint16_t get_af() const;

        uint16_t get_de() const;

        uint16_t get_hl() const;

        void set_bc(u_int16_t value);

        void set_af(u_int16_t value);

        void set_de(u_int16_t value);

        void set_hl(u_int16_t value);

        uint8_t flagsRegisterToByte(FlagsRegister& flag);

        FlagsRegister byteToFlagsRegister(uint8_t byte);
        
        uint8_t a;
        uint8_t b;
        uint8_t c;
        uint8_t d;
        uint8_t e;
        uint8_t f;
        uint8_t g;
        uint8_t h;
        uint8_t i;
        uint8_t j;
        uint8_t k;
        uint8_t l;
};

#endif // REGISTER_H