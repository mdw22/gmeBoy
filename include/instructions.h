// Copyright 2024 Michael White
#ifndef _GMEBOY_INCLUDE_INSTRUCTIONS_H_
#define _GMEBOY_INCLUDE_INSTRUCTIONS_H_

#include <variant>

enum InstructionType {
    ADD, ADDHL, ADC, SUB, SBC, AND, OR, XOR, CP, INC, DEC, CCF, SCF, RRA, RLA, RRCA, RRLA,
    CPL, BIT, RESET, SET, SRL, RR, RL, RRC, RLC, SRA, SLA, SWAP
};

enum ArithmeticTarget {
    A, B, C, D, E, H, L
};

struct Instruction {
    InstructionType type_;
    ArithmeticTarget target;

    explicit Instruction(InstructionType type) : type_(type) {}

    Instruction(InstructionType type, ArithmeticTarget tar) : type_(type), target(tar) {}
};

#endif  // _GMEBOY_INCLUDE_INSTRUCTIONS_H_
