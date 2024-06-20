// Copyright 2024 Michael White
#ifndef _GMEBOY_INCLUDE_CPU_H_
#define _GMEBOY_INCLUDE_CPU_H_

#include <instructions.h>
#include <registers.h>
#include <functional>
#include <array>
#include <iostream>

class CPU {
 public:
    CPU();
    // Executes a specific instruction on a register. 
    // Instructions are defined in the Instruction file.
    // @param Instruction Object Reference
    // @return void
    void execute(Instruction& instruction);

    // Instruction to add a uint8_t value in register
    // @param value uint8_t Value to be added
    // @return uint8_t
    uint8_t add(uint8_t value);

    // Instruction to add a uint8_t value to HL register
    // @param value uint8_t Value to be added
    // @return uint8_t
    uint8_t addhl(uint8_t value);

    // Instruction to add with carry a uint8_t value
    // @param value uint8_t Value to be added
    // @return uint8_t
    uint8_t adc(uint8_t value);

    // Instruction to subtract a uint8_t value in register
    // @param value uint8_t Value to be subtracted
    // @return uint8_t
    uint8_t sub(uint8_t value);
   
    // Instruction to subtract a uint8_t value in register with carry
    // @param value uint8_t Value to be subtracted
    // @return uint8_t
    uint8_t sbc(uint8_t value);

    // Instruction to do a bitwise and on the value 
    // in a specific register and the value in the A register
    // @param value uint8_t Value to be and'd
    // @return uint8_t
    uint8_t land(uint8_t value); 

    // Instruction to do a bitwise or on the value
    // in a specific register and the value in the A register
    // @param value uint*-t Value to be and'd
    // @return uint8_t
    uint8_t lor(uint8_t value);

    // Instruction to do a bitwise xor on the value
    // in a specific register and the value in the A register
    // @param value uint8_t Value to be xor'd
    // @return uint8_t
    uint8_t lxor(uint8_t value);

    // Instruction to do a subtraction but 
    // not put result into A
    // @param value uint8_t Value to be compared
    // @return uint8_t
    uint8_t cp(uint8_t value);

    // Instruction to increment a register's value
    // @param value uint8_t Value to be incremented
    // @return uint8_t
    uint8_t inc(uint8_t value);

    // Instruction to decrement a register's value
    // @param value uint8_t Value to be decremented
    // @return uint8_t
    uint8_t dec(uint8_t value);

    // Instruction to toggle the value of the carry flag
    // @param value bool Value to be toggled
    // @return bool
    bool ccf(bool value);

    // Instruction to set the carry flag to true
    // @param value bool Value of carry flag
    // @return bool
    bool scf(bool value);

    
 private:
    Register REGISTERS;
    // Function helper for add instruction
    // @param target ArithmeticTarget target Register
    // @return void
    void executeAdd(ArithmeticTarget target);

    // Function helper for addhl instruction
    // @param target ArithmeticTarget target Register
    // @return void
    void executeAddHL(ArithmeticTarget target);

    // Function helper for adc instruction
    // @param target ArithmeticTarget target Register
    // @return void
    void executeAddWithCarry(ArithmeticTarget target);

    // Function helper for sub instruction
    // @param target ArithmeticTarget target Register
    // @return void
    void executeSub(ArithmeticTarget target);
};
#endif  // _GMEBOY_INCLUDE_CPU_H_
