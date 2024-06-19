// Copyright 2024 Michael White
#ifndef _GMEBOY_INCLUDE_CPU_H_
#define _GMEBOY_INCLUDE_CPU_H_

#include <instructions.h>
#include <registers.h>

class CPU {
 public:
    CPU();

    // Executes a specific instruction on a register. 
    // Instructions are defined in the Instruction file.
    // @param Instruction Object Reference
    // @return void
    void execute(Instruction& instruction);
    uint8_t add(uint8_t value);
 private:
    Register REGISTERS;
};
#endif  // _GMEBOY_INCLUDE_CPU_H_
