/*

Banknotes in many countries come in denominations of 1,2,5,10,20,50,100,200,500,1000, etc. That is, one of {1,2,5} times a power of 10.
This is OEIS A051109, except we'll extend the sequence to bigger values.

Given a positive integer as the input, the program should output the largest bank note that is less than or equal to the input.
The input will be less than 2^63.

Examples:

1 => 1
2 => 2
3 => 2
5 => 5
9 => 5
42 => 20
49 => 20
50 => 50
99 => 50
100 => 100
729871 => 500000
3789345345234 => 2000000000000
999999999999999999 => 500000000000000000

*/

#include <assert.h>

typedef unsigned long long uvlong;

// https://oeis.org/A051109
uvlong
banknote(uvlong n)
{
	uvlong a, b, c, d, r;

	a = 1;
	b = 2;
	c = 5;
	r = a;
	while (a <= n) {
		d = 10 * a;
		r = a;
		a = b;
		b = c;
		c = d;
	}
	return r;
}

int
main(void)
{
	assert(banknote(1) == 1);
	assert(banknote(2) == 2);
	assert(banknote(3) == 2);
	assert(banknote(5) == 5);
	assert(banknote(9) == 5);
	assert(banknote(42) == 20);
	assert(banknote(49) == 20);
	assert(banknote(50) == 50);
	assert(banknote(99) == 50);
	assert(banknote(100) == 100);
	assert(banknote(729871ull) == 500000ull);
	assert(banknote(3789345345234ull) == 2000000000000ull);
	assert(banknote(999999999999999999ull) == 500000000000000000ull);

	return 0;
}
