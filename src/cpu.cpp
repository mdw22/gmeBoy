#include <lib/cpu.h>

CPU::CPU() { 
}

void CPU::execute(Instruction& instruction) {
    InstructionType type = instruction.type; 
    ArithmeticTarget target = instruction.target;
    switch (target)
    {
    case ArithmeticTarget::A :
        break;
    case ArithmeticTarget::B :
        break;
    case ArithmeticTarget::C :
        break;
    case ArithmeticTarget::D :
        break;
    case ArithmeticTarget::E :
        break;
    case ArithmeticTarget::H :
        break;
    // Default register is L
    default:
        break;
    }
}