#include <iostream>
#include "cpu.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello world!" << std::endl;
    Instruction instruction = Instruction(ADD, A);
    CPU cpu;
    cpu.execute(instruction);
}
