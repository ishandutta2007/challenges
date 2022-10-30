/*

In mathematics, the Fibonacci numbers, commonly denoted Fn, form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1:

Fibonacci Sequence

and

Fibonacci Sequence 2

for n > 1

The beginning of the sequence is thus:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...

The function fastFib(num) returns the fibonacci number Fn, of the given num as an argument.
Examples

fib_fast(5) ➞ 5

fib_fast(10) ➞ 55

fib_fast(20) ➞ 6765

fib_fast(50) ➞ 12586269025

Notes

    The input number is always positive.
    You have to make it Fast.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef long long vlong;

void
eye(vlong m[2][2])
{
	m[0][0] = m[1][1] = 1;
	m[0][1] = m[1][0] = 0;
}

void
mul(vlong m[2][2], vlong a[2][2], vlong b[2][2])
{
	vlong c[2][2];
	size_t i, j, k;

	memset(c, 0, sizeof(c));
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
	memcpy(m, c, sizeof(c));
}

void
ipow(vlong a[2][2], vlong m[2][2], int p)
{
	vlong x[2][2], y[2][2];

	if (p == 0) {
		eye(a);
		return;
	}

	memcpy(x, m, sizeof(x));
	while ((p & 1) == 0) {
		mul(x, x, x);
		p >>= 1;
	}
	memcpy(y, x, sizeof(x));
	for (p >>= 1; p > 0; p >>= 1) {
		mul(x, x, x);
		if ((p & 1) != 0)
			mul(y, y, x);
	}
	memcpy(a, y, sizeof(y));
}

vlong
fib(vlong n)
{
	vlong m[2][2] = {
	    {1, 1},
	    {1, 0},
	};
	vlong r[2][2];

	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;

	ipow(r, m, n);
	return r[1][0];
}

int
main(void)
{
	assert(fib(0) == 0);
	assert(fib(5) == 5);
	assert(fib(10) == 55);
	assert(fib(20) == 6765);
	assert(fib(30) == 832040ll);
	assert(fib(40) == 102334155ll);
	assert(fib(50) == 12586269025ll);

	return 0;
}
