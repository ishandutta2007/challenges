/*

The Halting Problem, in computational theory, is the challenge of determining if a given program and data, when started, will actually finish.
In more simple terms: it is essentially impossible to determine if an arbitrary program will ever complete because of how quickly a program's complexity can grow.
One could attempt to partially solve the program by attempting to find logical errors, such as infinite loops or bad iteration conditions, but this cannot verify if complex structures ever halt.
Another partial solution is to just simulate the code and see if it halts, though this fails for any program that becomes reasonably large.
For this challenge, you will be doing this last approach:

Your goal is to simulate a given program, written in a subset of common assembly instructions listed below, and measure how many instructions were executed before the program halts, or assume the program never halts after executing 100,000 instructions.
The fictional computer architecture that runs these instructions does so one instruction at a time, starting with the first and only stopping when the "HALT" instruction is executed or when there is no next instruction.
The memory model is simple: it has 32 1-bit registers, indexed like an array. Memory can be treated conceptually like a C-style array named M: M[0], M[1], ..., M[31] are all valid locations.
All memory should be initialized to 0. Certain instructions have arguments, which will always be integers between 0 to 31 (inclusive).

The instruction set only has 10 instructions, as follows:

Instruction	Description
AND a b	M[a] = M[a] bit-wise and M[b]
OR a b	M[a] = M[a] bit-wise or M[b]
XOR a b	M[a] = M[a] bit-wise xor M[b]
NOT a	M[a] = bit-wise not M[a]
MOV a b	M[a] = bit-wise M[b]
SET a c	M[a] = c
RANDOM a	M[a] = random value (0 or 1; equal probability distribution)
JMP x	Start executing instructions at index x
JZ x a	Start executing instructions at index x if M[a] == 0
HALT	Halts the program
Note that memory and code reside in different places! Basically you can modify memory, but cannot modify code.

Special thanks to the ACM collegiate programming challenges group for giving me the initial idea here. Please note that one cannot actually solve the Halting problem, and that this is strictly a mini-simulation challenge.

Formal Inputs & Outputs

Input Description
You will first be given an integer N, which represents the number of instructions, one per line, that follows.
Each of these lines will start with an instruction from the table above, with correctly formed arguments: the given program will be guaranteed to never crash, but are not guaranteed to ever halt (that's what we are testing!).

Output Description
Simply run the program within your own simulation; if it halts (runs the HALT instruction) or ends (goes past the final instruction), write "Program halts!" and then the number of instructions executed.
If the program does not halt or end within 100,000 instruction executions, stop the simulation and write "Unable to determine if application halts".

Sample Inputs & Outputs

Sample Input
5
SET 0 1
JZ 4 0
RANDOM 0
JMP 1
HALT

Sample Output
"Program halts! 5 instructions executed."

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

#define MAXREG 32
#define MAXMEM (1ULL << 20)

typedef unsigned long ulong;

typedef struct {
	ulong reg[MAXREG];
	ulong pc;
	ulong *mem;
	size_t memsz;
	int halted;
} Mach;

typedef struct {
	int op;
	char name[16];
	int args;
	int mode;
} Inst;

enum {
	AND,
	OR,
	XOR,
	NOT,
	MOV,
	SET,
	RANDOM,
	JMP,
	JZ,
	HALT
};

const Inst insts[] = {
    {AND, "AND", 2, 'r'},
    {OR, "OR", 2, 'r'},
    {XOR, "XOR", 2, 'r'},
    {NOT, "NOT", 1, 'r'},
    {MOV, "MOV", 2, 'r'},
    {SET, "SET", 2, 'c'},
    {RANDOM, "RANDOM", 1, 'r'},
    {JMP, "JMP", 1, 'a'},
    {JZ, "JZ", 2, 'a'},
    {HALT, "HALT", 0, 0},
    {0, "", 0, 0},
};

void
destroy(Mach *m)
{
	if (!m)
		return;
	free(m->mem);
}

int
compile(Mach *m, const char **s, size_t n)
{
	const Inst *in;
	char name[8];
	ulong arg[2];
	int nf;
	size_t i;

	if (n >= MAXMEM)
		return -ENOMEM;

	m->memsz = n;
	m->mem = calloc(m->memsz, sizeof(*m->mem));
	if (!m->mem)
		return -ENOMEM;

	for (i = 0; i < n; i++) {
		memset(arg, 0, sizeof(arg));
		nf = sscanf(s[i], "%7s %lu %lu", name, arg, arg + 1);
		if (nf < 1)
			return -EINVAL;

		for (in = insts; in->name[0]; in++) {
			if (!strcmp(name, in->name))
				break;
		}

		if (!in->name[0] || nf != in->args + 1)
			return -EINVAL;

		m->mem[i] = in->op;
		switch (in->mode) {
		case 'r':
			if (arg[0] >= MAXREG || arg[1] >= MAXREG)
				return -EINVAL;

			m->mem[i] |= (arg[0] << 8) | (arg[1] << 16);
			break;

		case 'c':
			if (arg[0] >= MAXREG || arg[1] > 1)
				return -EINVAL;

			m->mem[i] |= (arg[0] << 8) | (arg[1] << 16);
			break;

		case 'a':
			if (arg[0] >= MAXMEM)
				return -EINVAL;

			m->mem[i] |= (arg[0] << 4) | (arg[1] << 27);
			break;
		}
	}
	return 0;
}

void
reset(Mach *m)
{
	memset(m->reg, 0, sizeof(m->reg));
	m->pc = 0;
	m->halted = 0;
}

void
decode(ulong enc, ulong *op, ulong *r1, ulong *r2, ulong *ro, ulong *off)
{
	*op = enc & 0xf;
	*r1 = (enc >> 8) & 0x1f;
	*r2 = (enc >> 16) & 0x1f;
	*ro = (enc >> 27) & 0x1f;
	*off = (enc >> 4) & (MAXMEM - 1);
}

void
disasm(Mach *m, char *b)
{
	ulong enc, op, r1, r2, ro, off;
	const Inst *in;
	int i, l;

	l = sprintf(b, "%08lx", m->pc);
	if (m->pc >= m->memsz)
		return;

	l += sprintf(b + l, " | R");
	for (i = 0; i < MAXREG; i++)
		l += sprintf(b + l, "%d", !!m->reg[i]);

	enc = m->mem[m->pc];
	l += sprintf(b + l, " | %08lx ", enc);

	decode(enc, &op, &r1, &r2, &ro, &off);
	if (op >= nelem(insts)) {
		l += sprintf(b + l, "UNK");
		return;
	}

	in = insts + op;
	l += sprintf(b + l, "%s", in->name);
	switch (in->mode) {
	case 'r':
		if (in->args >= 1)
			l += sprintf(b + l, " %lu", r1);
		if (in->args >= 2)
			l += sprintf(b + l, " %lu", r2);
		break;

	case 'a':
		if (in->args >= 1)
			l += sprintf(b + l, " %lu", off);
		if (in->args >= 2)
			l += sprintf(b + l, " %lu", ro);
		break;

	case 'c':
		l += sprintf(b + l, " %lu %lu", r1, r2);
		break;
	}
}

void
step(Mach *m)
{
	ulong op, r1, r2, ro, off;

	if (m->pc >= m->memsz) {
		m->halted = 1;
		return;
	}

	decode(m->mem[m->pc++], &op, &r1, &r2, &ro, &off);
	switch (op) {
	case AND:
		m->reg[r1] &= m->reg[r2];
		break;
	case OR:
		m->reg[r1] |= m->reg[r2];
		break;
	case XOR:
		m->reg[r1] ^= m->reg[r2];
		break;
	case NOT:
		m->reg[r1] = !m->reg[r1];
		break;
	case MOV:
		m->reg[r1] = m->reg[r2];
		break;
	case SET:
		m->reg[r1] = r2;
		break;
	case RANDOM:
		m->reg[r1] = rand() & 1;
		break;
	case JMP:
		if (off >= m->memsz)
			m->halted = 1;
		else
			m->pc = off;
		break;
	case JZ:
		if (off >= m->memsz)
			m->halted = 1;
		else if (m->reg[ro] == 0)
			m->pc = off;
		break;
	case HALT:
	default:
		m->halted = 1;
		break;
	}
}

void
halting(Mach *m)
{
	static const ulong steps = 100000ULL;
	char b[128];
	ulong n;

	reset(m);
	for (n = 0; n < steps; n++) {
		disasm(m, b);
		printf("%s\n", b);
		step(m);
		if (m->halted)
			break;
	}

	if (n < steps)
		printf("Program halts! %lu instructions executed.\n", n);
	else
		printf("Program did not halt!\n");
}

void
test(const char **s, size_t n)
{
	Mach m[1];

	assert(compile(m, s, n) >= 0);
	halting(m);
	destroy(m);
}

int
main(void)
{
	static const char *s1[] = {
	    "SET 0 1",
	    "JZ 4 0",
	    "RANDOM 0",
	    "JMP 1",
	    "HALT",
	};

	srand(time(NULL));

	test(s1, nelem(s1));

	return 0;
}
