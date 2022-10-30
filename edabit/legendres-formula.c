/*

Legendre's formula finds the exponent of the largest power of some prime p that divides (is a factor of) the factorial of some number n.

Legendre's formula example (p = 2 and n = 27):

Legendre's Formula

So 2^23 is the largest power of 2 that divides 27!.

The formula returns the sum of many fractions (rounded down) with n as the numerator and a steadily increasing power of p as the denominator, stopping when it exceeds the numerator.

To illustrate:

p = 5
n = 100

int(100/5) + int(100/25)
// No 100/125 because 125 > 100.

p = 2
n = 128

int(128/2) + int(128/4) + int(128/8) + ... + int(128/128)

Given p and n, return the result of Legendre's formula (see Resources).
Examples

legendre(5, 100) ➞ 24

legendre(2, 128) ➞ 127

legendre(3, 50) ➞ 22

Notes

    p and n will be positive integers.
    When p exceeds n, the result should be 0.

*/

#include <assert.h>
#include <stdio.h>

unsigned
legendre(unsigned p, unsigned n)
{
	unsigned m, r;

	if (p == 0)
		return 0;

	r = 0;
	for (m = p; m <= n; m *= p)
		r += n / m;
	return r;
}

int
main(void)
{
	assert(legendre(2, 27) == 23);
	assert(legendre(5, 100) == 24);
	assert(legendre(2, 128) == 127);
	assert(legendre(3, 50) == 22);
	assert(legendre(7, 98) == 16);
	assert(legendre(11, 500) == 49);
	assert(legendre(3, 600) == 297);
	assert(legendre(7, 6) == 0);
	assert(legendre(3, 1385) == 688);
	assert(legendre(5, 4324) == 1077);
	assert(legendre(2, 8663) == 8655);

	return 0;
}
