/*

Introduction

Logic gates! Everyone knows them, everyone loves them (unless you're starting to learn them).
Take two booleans, compare them, get a single boolean in return. AND, NAND, OR, NOR, XOR, XNOR. Fun!
But, what if you only had the inputs and output, but not the operator?

Logic Gates

Challenge

Given a three digit number, xyz, where x and y are inputs to the unknown gate(s) and z is the output, list all the possible gates.
The output order doesn't matter but it must be all caps and separated by a space.
This is code-golf, so the shortest answer wins!

Example Inputs and Outputs

Inputs:

001

101

111

Outputs:

NAND NOR XNOR

NAND OR XOR

AND OR XNOR

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
operator(int x, int y, int z, char *b)
{
	struct {
		char gate[8];
		int value;
	} op[] = {
	    {"AND", x & y},
	    {"NAND", !(x & y)},
	    {"OR", x | y},
	    {"NOR", !(x | y)},
	    {"XOR", x ^ y},
	    {"XNOR", !(x ^ y)},
	};

	size_t i, l;

	l = 0;
	for (i = 0; i < nelem(op); i++) {
		if (op[i].value == z)
			l += sprintf(b + l, "%s ", op[i].gate);
	}

	if (l)
		b[l - 1] = '\0';
	else
		b[l] = '\0';

	return b;
}

void
test(int x, int y, int z, const char *r)
{
	char b[128];

	operator(x, y, z, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(0, 0, 1, "NAND NOR XNOR");
	test(1, 0, 1, "NAND OR XOR");
	test(1, 1, 1, "AND OR XNOR");

	return 0;
}
