/*

The ternary expansion of a number is that number written in base 3.
A number can have more than one ternary expansion.
A ternary expansion is indicated with a subscript 3.
For example, 1=13=0.222…3, and 0.875=0.212121…3.

The Cantor set is defined as the real numbers between 0 and 1 inclusive that have a ternary expansion that does not contain a 1.
If a number has more than one ternary expansion, it is enough for a single one to not contain a 1.

For example, 0=0.000…3 and 1=0.222…3, so they are in the Cantor set.
But 0.875=0.212121…3 and this is its only ternary expansion, so it is not in the Cantor set.

Your task is to determine whether a given number is in the Cantor set.

Input

The input consists of several test cases, at most 10.

Each test case consists of a single line containing a number x written in decimal notation, with 0≤x≤1, and having at most 6 digits after the decimal point.

The last line of input is END. This is not a test case.

Output

For each test case, output MEMBER if x is in the Cantor set, and NON-MEMBER if x is not in the Cantor set.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
cantor(double x)
{
	static const int N = 16;

	double a, b;
	double u, v;
	double l;
	int i;

	a = 0;
	b = 1;
	for (i = 0; i < N; i++) {
		l = (b - a) / 3;
		u = a + l;
		v = a + 2 * l;
		if (x <= u)
			b = u;
		else if (x >= v)
			a = v;
		else
			return "NON-MEMBER";
	}
	return "MEMBER";
}

void
test(double x, const char *r)
{
	const char *p;

	p = cantor(x);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test(0, "MEMBER");
	test(1, "MEMBER");
	test(0.875, "NON-MEMBER");

	return 0;
}
