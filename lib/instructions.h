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
    ArithmeticTarget target;

    Instruction(InstructionType t) : type(t) {}

    Instruction(InstructionType t, ArithmeticTarget tar) : type(t), target(tar) {}
};

#endif // INSTRUCTIONS_H