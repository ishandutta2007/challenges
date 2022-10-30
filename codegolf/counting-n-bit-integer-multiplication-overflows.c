/*

Given a positive integer N, output the number of pairs of integers 0 <= a <= b < 2**N such that a*b >= 2**N.

Rules
You may assume that N is less than or equal to the maximum bit width for integers in your language (e.g. for C, N will not exceed 32 or 64, depending on the architecture of the machine).
If your language is capable of handling arbitrary-width integers, then there is no upper bound on N.

Test Cases
1 0
2 3
3 19
4 96
5 437
6 1876
7 7804
8 31904
9 129170
10 520135
11 2088143
12 8369175
13 33512744
14 134128704
15 536681553
16 2147082274

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

/*

@Anders Kaseorg

O(2^(n/2)) rather than O(2^n)

A better algorithm can run in O(2^(n/3))
https://arxiv.org/pdf/1206.3369.pdf

*/

vlong
overflows(vlong n)
{
	vlong a, s;
	vlong x, y;

	if (n < 1)
		return 0;

	a = 1LL << n;
	s = ((a - 1) * a) / 2;
	x = 0;
	y = 0;
	while (y < 1) {
		s += y;
		x -= 1;
		y = floor((a * 1.0) / x) - x;
	}
	return s;
}

int
main(void)
{
	vlong tab[] = {0, 3, 19, 96, 437, 1876, 7804, 31904, 129170, 520135, 2088143, 8369175, 33512744, 134128704, 536681553, 2147082274, 8589086503LL, 34357951447LL};
	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(overflows(i + 1) == tab[i]);

	return 0;
}
