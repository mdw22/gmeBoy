#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <variant>

enum InstructionType {
    ADD,
};

enum ArithmeticTarget {
    A, B, C, D, E, H, L
};

struct Instruction {
    InstructionType type;
    std::variant<ArithmeticTarget> target;
}

#endif // INSTRUCTIONS_H