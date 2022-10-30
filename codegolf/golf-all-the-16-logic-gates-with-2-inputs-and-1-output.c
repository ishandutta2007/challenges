/*

For example, the gate A and B is a logic gate with 2 inputs and 1 output.

There are exactly 16 of them, because:

    each logic gate takes two inputs, which can be truthy or falsey, giving us 4 possible inputs
    of the 4 possible inputs, each can have an output of truthy and falsey
    therefore, there are 2^4 possible logic gates, which is 16.

Your task is to write 16 programs/functions which implement all of them separately.

Your functions/programs must be independent.

They are valid as long as they output truthy/falsey values, meaning that you can implement A or B in Python as lambda a,b:a+b, even if 2 is produced for A=True and B=True.

Score is total bytes used for each function/program.
List of logic gates

    0,0,0,0 (false)
    0,0,0,1 (and)
    0,0,1,0 (A and not B)
    0,0,1,1 (A)
    0,1,0,0 (not A and B)
    0,1,0,1 (B)
    0,1,1,0 (xor)
    0,1,1,1 (or)
    1,0,0,0 (nor)
    1,0,0,1 (xnor)
    1,0,1,0 (not B)
    1,0,1,1 (B implies A)
    1,1,0,0 (not A)
    1,1,0,1 (A implies B)
    1,1,1,0 (nand)
    1,1,1,1 (true)

Where the first number is the output for A=false, B=false, the second number is the output for A=false, B=true, the third number is the output for A=true, B=false, the fourth number is the output for A=true, B=true.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
bfalse(int a, int b)
{
	(void)a;
	(void)b;
	return 0;
}

int
band(int a, int b)
{
	return a && b;
}

int
banb(int a, int b)
{
	return a && !b;
}

int
ba(int a, int b)
{
	(void)b;
	return a;
}

int
bnab(int a, int b)
{
	return !a && b;
}

int
bb(int a, int b)
{
	(void)a;
	return b;
}

int
bxor(int a, int b)
{
	return !!(a ^ b);
}

int
bor(int a, int b)
{
	return a || b;
}

int
bnor(int a, int b)
{
	return !(a || b);
}

int
bxnor(int a, int b)
{
	return !(a ^ b);
}

int
bnb(int a, int b)
{
	(void)a;
	return !b;
}

int
bbia(int a, int b)
{
	return !b || a;
}

int
bna(int a, int b)
{
	(void)b;
	return !a;
}

int
baib(int a, int b)
{
	return !a || b;
}

int
bnand(int a, int b)
{
	return !(a && b);
}

int
btrue(int a, int b)
{
	(void)a;
	(void)b;
	return 1;
}

void
gen(void)
{
	static int (*funcs[])(int, int) = {
	    bfalse,
	    band,
	    banb,
	    ba,
	    bnab,
	    bb,
	    bxor,
	    bor,
	    bnor,
	    bxnor,
	    bnb,
	    bbia,
	    bna,
	    baib,
	    bnand,
	    btrue,
	};

	int (*f)(int, int);
	size_t i;

	for (i = 0; i < nelem(funcs); i++) {
		f = funcs[i];
		printf("%zu | %d %d %d %d\n", i, f(0, 0), f(0, 1), f(1, 0), f(1, 1));
	}
}

int
main(void)
{
	gen();
	return 0;
}
