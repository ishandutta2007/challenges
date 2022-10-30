/*

Introduction
One of the first things I learned in chemistry, was giving the formula for the combustion of alkanes.
The most basic example was: 2CH4 + 4O2 -> 4H2O + 2CO2. Note that the equation could have been simplified by dividing every coefficient by 2, we would get CH4 + 2O2 -> 2H2O + CO2.
To make things easier, we are going to ignore this to not complicate things.

You can see that with the combustion of any alkane, oxygen is used. After the reaction, only CO2 and H2O are made.

The task
The input will always be in the form C(n)H(2n+2), with n>0. These are some example inputs:

CH4
C2H6
C3H8
C4H10
C5H12
C6H14
Useful tip:
Every alkane has a standard pattern in the combustion reaction:

2C(n)H(2n+2) + (3n+1)O2 -> (2n+2)H2O + (2n)CO2
e.g.

C4H10 gives the following equation: 2C(4)H(2*4+2) + (3*4+1)O2 -> (2*4+2)H2O + (2*4)CO2. After calculating everything, we get this final equation 2C4H10 + 13O2 -> 10H2O + 8CO2

Testcases
CH4
2CH4 + 4O2 -> 4H2O + 2CO2

C3H8
2C3H8 + 10O2 -> 8H2O + 6CO2

C4H10
2C4H10 + 13O2 -> 10H2O + 8CO2

C12H26
2C12H26 + 37O2 -> 26H2O + 24CO2

Rules
Note that I used spaces for the examples to increase readability, these are not necessary. 2CH4 + 4O2 -> 4H2O + 2CO2 and 2CH4+4O2->4H2O+2CO2 are both valid outputs. However, if you consistently use spaces for the output, you get a -10% bonus
This is code-golf, so the program with the least amount of bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
parse(const char *s)
{
	int n, m;

	if (sscanf(s, "CH%d", &m) == 1)
		n = 1;
	else if (sscanf(s, "C%dH%d", &n, &m) != 2)
		return -1;

	if (n <= 0 || m <= 0)
		return -1;
	if ((m % 2) || n != ((m - 2) / 2))
		return -1;
	return n;
}

char *
reaction(const char *s, char *b)
{
	int l;
	int n;

	n = parse(s);
	if (n < 0)
		return NULL;

	l = 0;
	l += sprintf(b + l, "2C");
	if (n != 1)
		l += sprintf(b + l, "%d", n);
	l += sprintf(b + l, "H%d + %dO2 -> %dH2O + %dCO2",
	             (2 * n) + 2,
	             (3 * n) + 1,
	             (2 * n) + 2,
	             (2 * n));

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	assert(reaction(s, b) != NULL);
	printf("%s\n", b);
	printf("%s\n", r);
	printf("\n");
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("CH4", "2CH4 + 4O2 -> 4H2O + 2CO2");
	test("C3H8", "2C3H8 + 10O2 -> 8H2O + 6CO2");
	test("C4H10", "2C4H10 + 13O2 -> 10H2O + 8CO2");
	test("C12H26", "2C12H26 + 37O2 -> 26H2O + 24CO2");

	return 0;
}
