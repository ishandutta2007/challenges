#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SPIMCORE

typedef struct
{
	char RegDst;
	char Jump;
	char Branch;
	char MemRead;
	char MemtoReg;
	char ALUOp;
	char MemWrite;
	char ALUSrc;
	char RegWrite;
} struct_controls;

/* ALU */
void ALU(unsigned A, unsigned B, char ALUControl, unsigned *ALUresult, char *Zero);

/* fetch instruction from memory */
int instruction_fetch(unsigned PC, unsigned *Mem, unsigned *instruction);

/* instruction partition */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1, unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec);

/* instruction decode */
int instruction_decode(unsigned op, struct_controls *controls);

/* read_register */
void read_register(unsigned r1, unsigned r2, unsigned *Reg, unsigned *data1, unsigned *data2);

/* sign_extend */
void sign_extend(unsigned offset, unsigned *extended_value);

/* ALU */
int ALU_operations(unsigned data1, unsigned data2, unsigned extended_value, unsigned funct, char ALUOp, char ALUSrc, unsigned *ALUresult, char *Zero);

/* read/write memory */
int rw_memory(unsigned ALUresult, unsigned data2, char MemWrite, char MemRead, unsigned *memdata, unsigned *Mem);

/* write to register */
void write_register(unsigned r2, unsigned r3, unsigned memdata, unsigned ALUresult, char RegWrite, char RegDst, char MemtoReg, unsigned *Reg);

/* PC update */
void PC_update(unsigned jsec, unsigned extended_value, char Branch, char Jump, char Zero, unsigned *PC);

#define SPIMCORE
#endif
