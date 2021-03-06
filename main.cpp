#include <iostream>
#include <stdio.h>
#include "decoder.hpp"
using namespace Cristiano;
using uint= unsigned int;
std::string orders[37]={"add", "sub", "sll"," slt", "sltu"," Xor", "srl"," sra", "Or", "And",//R
                        "lui", "auipc",//U
                        "jal", "beq", "bne","blt", "bge", "bltu"," bgeu",//B
                        "lb", "lh", "lw", "lbu", "lhu", "addi"," slti", "sltiu", "xori", "ori", "andi", "slli"," srli", "srai",//I
                        "jalr",//J
                        "sb", "sh", "sw"//S
};
uint reg[32];
uint mem[500005];
code ins[5];


void showReg(){
   //std::cout<<orders[ins[0].command]<<" has just completed "<<std::endl;

   for(int i=0;i<32;i++){std::cout<<"reg["<<i<<']'<<" = "<<reg[i]<<"   ";if(i%8==7)std::cout<<std::endl;}
   std::cout<<decToHex(PC)<<std::endl;
}

int main() {
   //freopen("az.ans","w",stdout);
    read();PC=0;
    while(true){
        if(ins[0].fetchCode()!=0)break;
        ins[0].decode();
        ins[0].execute();
        ins[0].writeMemory();
        ins[0].writeRegister();
        reg[0]=0;
        //showReg();
    }
    std::cout<<(((unsigned int)reg[10])&255u)<<std::endl;
    return 0;
}


