#include <lib/registers.h>

class Registers {
    public :
        uint16_t get_bc() const {
            return static_cast<uint16_t>(b) << 8 | static_cast<uint16_t>(c);
        }

        uint16_t get_af() const {
            return static_cast<uint16_t>(a) << 8 | static_cast<uint16_t>(f);
        }

        uint16_t get_de() const {
            return static_cast<uint16_t>(d) << 8 | static_cast<uint16_t>(e);
        }
        uint16_t get_hl() const {
            return static_cast<uint16_t>(h) << 8 | static_cast<uint16_t>(l);
        }

        void set_bc(u_int16_t value) {
            b = (static_cast<uint8_t>(value & 0xFF00) >> 8);
            c = (static_cast<uint8_t>(value & 0xFF));
        }

        void set_af(u_int16_t value) {
            a = (static_cast<uint8_t>(value & 0xFF00) >> 8);
            f = (static_cast<uint8_t>(value & 0xFF));
        }

        void set_de(u_int16_t value) {
            d = (static_cast<uint8_t>(value & 0xFF00) >> 8);
            e = (static_cast<uint8_t>(value & 0xFF));
        }

        void set_hl(u_int16_t value) {
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

    private :
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