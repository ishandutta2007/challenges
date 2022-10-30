/*

Notice: I'm willing to give a bounty to any answer that I find interesting.

Your challenge is to design a Turing-complete one instruction set computer (OISC):

An OISC is an abstract machine that uses only one instruction – obviating the need for a machine language opcode.
With a judicious choice for the single instruction and given infinite resources, an OISC is capable of being a universal computer in the same manner as traditional computers that have multiple instructions.

Here are some examples of single commands that make a Turing-complete OISC.

Rules:

You must provide an interpretation or proof thereof
You must provide an interpreter for your language. This interpreter should only be restricted by memory/time (e.g. must have no user-imposed restrictions).
If you do not provide an interpreter for your language (for whatever reason other than laziness) you must prove that it is possible for one to be written. An interpreter must be possible.

You must prove its Turing-completeness
You must include a formal proof that your language is Turing-complete. A simple way to do this is by proving that it can interpret or have the same behavior as another Turing-complete language. The most basic language to interpret would be Brainf**k.

For example, a normal language that has all the same commands as Brainf**k (and the same lack of user-imposed memory restrictions) is Turing-complete because anything that can be implemented in Brainf**k can be implemented in the language.

Here is a list of very simple-to-implement Turing-complete languages.

Additional OISC requirements
This OISC should only have one instruction - it cannot have multiple instructions with one of them making it Turing-complete.

Your OISC may use any syntax you like. You should define in your answer what is instruction, what is data, and what is a no-op (e.g. whitespace). Be creative!

Arguments do not just need to be integers. For example, /// is a beautiful example of a Turing-complete OISC.

How and if input and output are taken and given are left up to you. Most OISCs implement I/O via specific memory locations, but there may be other ways to do so, and you are encouraged to find one.

A valid answer must provide some example code in your OISC, either by including it in the post or linking to a simple challenge solved in the language.

Voting
Voters, please remember not to upvote boring submissions. Examples:

Lenguage-equivalents
An implementation of an existing OISC (answerers, please create your own!)
An "OISC" in which the first argument specifies a command to call (example)
However, you should upvote interesting, creative submissions, such as:

An OISC based off of a mathematical equation
A Turing-complete ZISC based on a neural network
An OISC in which output I/O happens in other ways than certain memory locations

*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct {
	int pc;
	int *mem;
	int nmem;
} OISC;

int
oiscinit(OISC *m, int size)
{
	if (size <= 0)
		return -EINVAL;

	m->mem = calloc(size, sizeof(*m->mem));
	if (!m->mem)
		return -ENOMEM;

	m->nmem = size;
	m->pc = 0;
	return 0;
}

void
oiscfree(OISC *m)
{
	if (!m)
		return;
	free(m->mem);
}

int
oiscstep(OISC *m)
{
	int a, b, c;

	if (m->pc < 0 || m->pc + 3 >= m->nmem)
		return 1;

	a = m->mem[m->pc];
	b = m->mem[m->pc + 1];
	c = m->mem[m->pc + 2];
	if (a < 0 || b < 0)
		return 1;

	m->mem[b] -= m->mem[a];
	if (m->mem[b] > 0)
		m->pc += 3;
	else
		m->pc = c;

	return 0;
}

void
oiscrun(OISC *m)
{
	for (;;) {
		if (!oiscstep(m))
			break;
	}
}

int
main(void)
{
	OISC m[1];

	if (oiscinit(m, 65536) < 0)
		return 1;
	oiscrun(m);
	oiscfree(m);

	return 0;
}
