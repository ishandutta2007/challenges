/*

The geometric mean of numbers a and b is the square root of their product (i.e. √(ab)). For example, the geometric mean of 2 and 8 is √(2*8)=4.

Two integers (a and b) are randomly (and independently) chosen between 1 and n (inclusive) where n is an integer greater than one.
Create a function that takes a number n as an argument and returns the probability that the geometric mean of a and b is an integer.

Examples

f(2) ➞ 0.5
// There are four possible pairs: (1, 1), (2, 1), (1, 2) and (2, 2).
// The pairs (1, 1) and (2, 2) are wanted (√(1*1)=1 and √(2*2)=2)
// but the pairs (2, 1) and (1, 2) are not (√(2*1)=√2 and √(1*2)=√2).
// Thus, the probability is 2/4 = 0.5.

f(10) ➞ 0.18

f(100) ➞ 0.031

Notes

Do not round your answer.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

// https://oeis.org/A132188
double
count(unsigned n)
{
	unsigned a, b, c, r;

	c = 0;
	for (a = 1; a <= n; a++) {
		for (b = 1; b <= n; b++) {
			r = sqrt(a * b);
			if (r * r == a * b)
				c++;
		}
	}
	return c * 1.0 / (n * n);
}

void
test(unsigned n, double r)
{
	assert(fabs(count(n) - r) < 1e-8);
}

int
main(void)
{
	test(2, 0.5);
	test(10, 0.18);
	test(100, 0.031);
	return 0;
}
