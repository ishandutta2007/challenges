/*

Given a number n >= 2, output all the positive integers less than n where gcd(n, k) == 1 (with k being any one of the output numbers).  Numbers of this sort are coprime to each other.

Example: 10 gives the output [1, 3, 7, 9] (in any form you like, as long as the numbers are unambiguously separated and in some sort of list). The list cannot have duplicate entries and doesn't have to be sorted.

More test cases:

2 -> [1]
3 -> [1, 2]
6 -> [1, 5]
10 -> [1, 3, 7, 9]
20 -> [1, 3, 7, 9, 11, 13, 17, 19]
25 -> [1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14, 16, 17, 18, 19, 21, 22, 23, 24]
30 -> [1, 7, 11, 13, 17, 19, 23, 29]
We are also not counting numbers above n that are coprime to n, solely because I'm fairly certain there's infinite solutions.

Also note: Numbers that are coprime to each other are also said to be relatively prime or mutually prime to each other.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
gcd(int a, int b)
{
	int t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

size_t
coprimes(int n, int *r)
{
	size_t l;
	int i;

	l = 0;
	for (i = 1; i < n; i++) {
		if (gcd(n, i) == 1)
			r[l++] = i;
	}
	return l;
}

void
test(int n, int *r, size_t nr)
{
	int p[128];

	assert(coprimes(n, p) == nr);
	assert(!memcmp(p, r, nr * sizeof(*r)));
}

int
main(void)
{
	int r1[] = {1};
	int r2[] = {1, 2};
	int r3[] = {1, 5};
	int r4[] = {1, 3, 7, 9};
	int r5[] = {1, 3, 7, 9, 11, 13, 17, 19};
	int r6[] = {1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14, 16, 17, 18, 19, 21, 22, 23, 24};
	int r7[] = {1, 7, 11, 13, 17, 19, 23, 29};

	test(2, r1, nelem(r1));
	test(3, r2, nelem(r2));
	test(6, r3, nelem(r3));
	test(10, r4, nelem(r4));
	test(20, r5, nelem(r5));
	test(25, r6, nelem(r6));
	test(30, r7, nelem(r7));

	return 0;
}
