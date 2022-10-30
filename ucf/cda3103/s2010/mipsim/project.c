// Implement the datapath of a single cycle MIPS machine

#include "spimcore.h"

/* ALU */
void
ALU(unsigned A, unsigned B, char ALUControl, unsigned *ALUresult, char *Zero)
{
	switch (ALUControl) {
	case 0: /* Z = A + B */
		*ALUresult = (signed)((signed)A + (signed)B);
		break;

	case 1: /* Z = A - B */
		*ALUresult = (signed)((signed)A - (signed)B);
		break;

	case 2: /* if A < B, Z = 1; otherwise, Z = 0 */
		*ALUresult = ((signed)A < (signed)B);
		break;

	case 3: /* A < B, Z = 1; otherwise, Z = 0 (A and B are unsigned int) */
		*ALUresult = (A < B);
		break;

	case 4: /* Z = A AND B */
		*ALUresult = A & B;
		break;

	case 5: /* Z = A OR B */
		*ALUresult = A | B;
		break;

	case 6: /* Shift left B by 16 bits */
		*ALUresult = B << 16;
		break;

	case 7: /* Z = A NOR B */
		*ALUresult = ~(A | B);
		break;
	}

	*Zero = !(*ALUresult);
}

/* instruction fetch */
int
instruction_fetch(unsigned PC, unsigned *Mem, unsigned *instruction)
{
	const unsigned memsize = (65536 >> 2);

	/* check to see if it is not aligned to word */
	if (PC % 4)
		return 1;

	/* check to see if it is in bounds */
	if ((PC >> 2) >= memsize)
		return 1;

	/* since each Mem location is in 32 bit already, have to shift by 2 */
	*instruction = Mem[PC >> 2];

	return 0;
}

/* instruction partition */
void
instruction_partition(unsigned instruction, unsigned *op, unsigned *r1, unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{
	*op = (instruction >> 26) & 0x3F;
	*r1 = (instruction >> 21) & 0x1F;
	*r2 = (instruction >> 16) & 0x1F;
	*r3 = (instruction >> 11) & 0x1F;
	*funct = (instruction)&0x3F;
	*offset = (instruction)&0xFFFF;
	*jsec = (instruction)&0x3FFFFFF;
}

/* instruction decode */
int
instruction_decode(unsigned op, struct_controls *controls)
{
	/* only implement opcodes specified in project.pdf */
	switch (op) {
	case 0x00:                         /* R-Type instruction */
		controls->ALUOp = 0x07;    /* from table in project.pdf, specify R-Type */
		controls->MemRead = 0x00;  /* disable */
		controls->MemWrite = 0x00; /* disable */
		controls->RegWrite = 0x01; /* enable */
		controls->RegDst = 0x01;   /* reg selector */
		controls->Jump = 0x00;     /* disable */
		controls->Branch = 0x00;   /* disable */
		controls->MemtoReg = 0x00; /* memory or ALU to reg selector */
		controls->ALUSrc = 0x00;   /* R-type */
		break;

	case 0x02:                         /* j jump */
		controls->ALUOp = 0x00;    /* from table in project.pdf, specify don't care */
		controls->MemRead = 0x00;  /* disable */
		controls->MemWrite = 0x00; /* disable */
		controls->RegWrite = 0x00; /* disable */
		controls->RegDst = 0x02;   /* reg selector */
		controls->Jump = 0x01;     /* enable  */
		controls->Branch = 0x00;   /* disable */
		controls->MemtoReg = 0x02; /* memory or ALU to reg selector */
		controls->ALUSrc = 0x00;   /* J instruction */
		break;

	case 0x04:                         /* beq branch on equal */
		controls->ALUOp = 0x01;    /* from table in project.pdf, specify subtraction */
		controls->MemRead = 0x00;  /* disable */
		controls->MemWrite = 0x00; /* disable */
		controls->RegWrite = 0x00; /* disable */
		controls->RegDst = 0x02;   /* reg selector */
		controls->Jump = 0x00;     /* disable  */
		controls->Branch = 0x01;   /* enable */
		controls->MemtoReg = 0x02; /* memory or ALU to reg selector */
		controls->ALUSrc = 0x00;   /* J instruction */
		break;

	case 0x08:                         /* addi with overflow */
		controls->ALUOp = 0x00;    /* from table in project.pdf, specify addition */
		controls->MemRead = 0x00;  /* disable */
		controls->MemWrite = 0x00; /* disable */
		controls->RegWrite = 0x01; /* enable */
		controls->RegDst = 0x00;   /* reg selector */
		controls->Jump = 0x00;     /* disable */
		controls->Branch = 0x00;   /* disable */
		controls->MemtoReg = 0x00; /* memory or ALU to reg selector */
		controls->ALUSrc = 0x01;   /* I-type */
		break;

	case 0x0A:                         /* slti set on less than immediate */
		controls->ALUOp = 0x02;    /* from table in project.pdf, specify set on less than */
		controls->MemRead = 0x00;  /* disable */
		controls->MemWrite = 0x00; /* disable */
		controls->RegWrite = 0x01; /* enable */
		controls->RegDst = 0x00;   /* reg selector */
		controls->Jump = 0x00;     /* disable */
		controls->Branch = 0x00;   /* disable */
		controls->MemtoReg = 0x00; /* memory or ALU to reg selector */
		controls->ALUSrc = 0x01;   /* I-type */
		break;

	case 0x0B:                         /* sltiu set on less than (unsigned) immediate */
		controls->ALUOp = 0x03;    /* from table in project.pdf, specify set on less than unsigned */
		controls->MemRead = 0x00;  /* disable */
		controls->MemWrite = 0x00; /* disable */
		controls->RegWrite = 0x01; /* enable */
		controls->RegDst = 0x00;   /* reg selector */
		controls->Jump = 0x00;     /* disable */
		controls->Branch = 0x00;   /* disable */
		controls->MemtoReg = 0x00; /* memory or ALU to reg selector */
		controls->ALUSrc = 0x01;   /* I-type */
		break;

	case 0x0F:                         /* lui load upper immediate */
		controls->ALUOp = 0x06;    /* from table in project.pdf, specify shift to get the data to upper immediate location */
		controls->MemRead = 0x00;  /* disable */
		controls->MemWrite = 0x00; /* disable */
		controls->RegWrite = 0x01; /* enable */
		controls->RegDst = 0x00;   /* reg selector */
		controls->Jump = 0x00;     /* disable */
		controls->Branch = 0x00;   /* disable */
		controls->MemtoReg = 0x00; /* memory or ALU to reg selector */
		controls->ALUSrc = 0x01;   /* I-type */
		break;

	case 0x23:                         /* lw load word */
		controls->ALUOp = 0x00;    /* from table in project.pdf, add to get the offset */
		controls->MemRead = 0x01;  /* enable */
		controls->MemWrite = 0x00; /* disable */
		controls->RegWrite = 0x01; /* enable */
		controls->RegDst = 0x00;   /* reg selector */
		controls->Jump = 0x00;     /* disable */
		controls->Branch = 0x00;   /* disable */
		controls->MemtoReg = 0x01; /* memory or ALU to reg selector */
		controls->ALUSrc = 0x01;   /* I-type */
		break;

	case 0x2B:                         /* sw store word */
		controls->ALUOp = 0x00;    /* from table in project.pdf, add to get the offset */
		controls->MemRead = 0x00;  /* disable */
		controls->MemWrite = 0x01; /* enable */
		controls->RegWrite = 0x00; /* disable */
		controls->RegDst = 0x02;   /* reg selector don't care */
		controls->Jump = 0x00;     /* disable */
		controls->Branch = 0x00;   /* disable */
		controls->MemtoReg = 0x00; /* memory or ALU to reg selector */
		controls->ALUSrc = 0x01;   /* I-type */
		break;

	default: /* unimplemented opcodes */
		/* printf("UNIMPLEMENTED OPCODE: %X\n", op); */
		return 1;
		break;
	}
	/* printf("OPCODE: %X\n", op); */
	return 0;
}

/* Read Register */
void
read_register(unsigned r1, unsigned r2, unsigned *Reg, unsigned *data1, unsigned *data2)
{
	*data1 = Reg[r1];
	*data2 = Reg[r2];
}

/* Sign Extend */
void
sign_extend(unsigned offset, unsigned *extended_value)
{
	/* offset is 16 bits, and assuming extended_value is 32 bits, we
	 * sign extend it */

	*extended_value = offset;

	if (offset & 0x8000) /* check sign bit, if it is on, sign extend it */
		*extended_value |= 0xFFFF0000;
}

/* ALU operations */
int
ALU_operations(unsigned data1, unsigned data2, unsigned extended_value, unsigned funct, char ALUOp, char ALUSrc, unsigned *ALUresult, char *Zero)
{
	/* R-Type instruction, but since this spimcore implement a small
	 * fraction of the opcode, namely the first 3 bits of it, only
	 * send the first 3 bits of the ALUop/funct */

	unsigned d1, d2, op;

	if (ALUOp > 7) /* invalid operation, halt */
		return 1;

	/* set the data path, if ALUsrc is 1, then
	 * it is an I-Type/branch instruction and second input
	 * goes from extended value */
	d1 = data1;
	d2 = data2;
	if (ALUSrc == 1)
		d2 = extended_value;

	/* this is for figuring out wheter or not it is an
	 * R-Type instruction or I-type */
	op = ALUOp;
	if (ALUOp == 7) /* This tells it that it is an R-Type instruction */
	{
		switch (funct) {
		case 0x20: /* addition */
			op = 0x00;
			break;

		case 0x22: /* subtraction */
			op = 0x01;
			break;

		case 0x24: /* AND */
			op = 0x04;
			break;

		case 0x25: /* OR */
			op = 0x05;
			break;

		case 0x27: /* NOR */
			op = 0x07;
			break;

		case 0x2A: /* set on less than */
			op = 0x02;
			break;

		case 0x2B: /* set on less than unsigned */
			op = 0x03;
			break;

		default:
			/* printf("FUNCT: %X\n", funct); */
			return 1;
			break;
		}
	}

	ALU(d1, d2, op, ALUresult, Zero);

	return 0;
}

/* Read / Write Memory */

/* play it safe, treat don't care as disable for all of the mem writes/reads */

int
rw_memory(unsigned ALUresult, unsigned data2, char MemWrite, char MemRead, unsigned *memdata, unsigned *Mem)
{
	/* have to do this because the assignment doesn't allow us to modify
	 * the other files (would've put the size macros inside the header file)
	 *  for checking halt conditions */
	const unsigned memsize = (65536 >> 2);
	unsigned index;

	if (MemWrite == 1 || MemRead == 1) /* enabled */
	{
		/* check for alignment */
		if (ALUresult % 4)
			return 1;

		/* have to shift by 2 since assume ALUresult is in increments of 4 */
		index = ALUresult >> 2;

		if (index >= memsize) /* out of bounds */
			return 1;

		if (MemWrite == 1) /* enabled  */
			Mem[index] = data2;

		if (MemRead == 1) /* enabled */
			*memdata = Mem[index];
	}

	return 0;
}

/* Write Register */
void
write_register(unsigned r2, unsigned r3, unsigned memdata, unsigned ALUresult, char RegWrite, char RegDst, char MemtoReg, unsigned *Reg)
{
	unsigned r, d;

	if (RegWrite == 1) /* enabled */
	{
		d = (MemtoReg == 1) ? memdata : ALUresult;
		r = (RegDst == 0) ? r2 : r3;
		Reg[r] = d;
	}
}

/* PC update */
void
PC_update(unsigned jsec, unsigned extended_value, char Branch, char Jump, char Zero, unsigned *PC)
{
	/* update PC counter */
	*PC += 4;

	/* for branching */
	if (Branch == 1 && Zero)
		*PC += (((signed)(extended_value)) << 2);

	/* for jumping */
	if (Jump == 1)
		*PC = (*PC & 0xF0000000) | jsec << 2;
}
