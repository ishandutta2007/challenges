/*

Challenge
In this task you would be given an integer N (less than 106), find the minimum way in which you could sum to N using only Fibonacci numbers - this partition is called Zeckendorf representation.

You could use any Fibonacci number more than once and if there is more than one representation output any.

For example if the input is 67 then one possible output could be using the Fibonacci numbers 1,3,8,55 which is also the minimum number of Fibonacci numbers that could be used to get the sum 67.

The input N is given on a single line, the inputs are terminated by EOF.

Examples

Given in the format input: output

0: 0
47: 34+13
3788: 2584+987+144+55+13+5
1646: 1597+34+13+2
25347: 17711+6765+610+233+21+5+2
677: 610+55+8+3+1
343: 233+89+21
3434: 2584+610+233+5+2
Constraints

The number of inputs would not exceed 106 values.
Your program should not run more than 5 seconds for all inputs.
You can use any language of your choice.
Shortest solution wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long long uvlong;

#define nelem(x) (sizeof(x) / sizeof(x[0]))

uvlong
fib(uvlong n)
{
	uvlong a, b, c;
	uvlong i;

	a = 0;
	b = 1;
	for (i = 0; i < n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return a;
}

size_t
zeckendorf(uvlong n, uvlong *r)
{
	uvlong i, j, v;

	if (n == 0) {
		r[0] = 0;
		return 1;
	}

	for (i = 1; i < n; i++) {
		if (fib(i + 1) > n)
			break;
	}

	for (j = 0; n; i--) {
		v = fib(i);
		if (v <= n) {
			n -= v;
			r[j++] = v;
		}
	}
	return j;
}

void
test(uvlong n, uvlong *r, size_t nr)
{
	uvlong p[128];
	size_t np;

	np = zeckendorf(n, p);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main(void)
{
	uvlong r1[] = {0};
	uvlong r2[] = {34, 13};
	uvlong r3[] = {2584, 987, 144, 55, 13, 5};
	uvlong r4[] = {1597, 34, 13, 2};
	uvlong r5[] = {17711ULL, 6765, 610, 233, 21, 5, 2};
	uvlong r6[] = {610, 55, 8, 3, 1};
	uvlong r7[] = {233, 89, 21};
	uvlong r8[] = {2584, 610, 233, 5, 2};

	test(0, r1, nelem(r1));
	test(47, r2, nelem(r2));
	test(3788, r3, nelem(r3));
	test(1646, r4, nelem(r4));
	test(25347ULL, r5, nelem(r5));
	test(677, r6, nelem(r6));
	test(343, r7, nelem(r7));
	test(3434, r8, nelem(r8));

	return 0;
}
