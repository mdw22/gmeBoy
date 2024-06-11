#ifndef CPU_H
#define CPU_H

#include <instructions.h>
#include <registers.h>

class CPU {
    public :
        CPU();
        void execute(Instruction& instruction) {}
    private :
        Register regist; 
};
#endif // CPU_H