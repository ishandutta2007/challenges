/*

Description
A Sumac sequence starts with two non-zero integers t1 and t2.

The next term, t[3]=t[1]-t[2]

More generally, t[n]=t[n-2]-t[n-1]

The sequence ends when t[n]≤0. All values in the sequence must be positive.

Challenge
Given two integers t1 and t2, compute the Sumac sequence, and output its length.

If there is a negative number in the input, remove everything after it, and compute the length.

You may take the input in any way (Array, two numbers, etc.)

Test Cases
(Sequence is included for clarification)

[t1,t2]   Sequence          n
------------------------------
[120,71]  [120,71,49,22,27] 5
[101,42]  [101,42,59]       3
[500,499] [500,499,1,498]   4
[387,1]   [387,1,386]       3
[3,-128]  [3]               1
[-2,3]    []                0
[3,2]     [3,2,1,1]         4

Scoring
This is code-golf. Shortest answer in each language wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
sumac(int a, int b, int *r)
{
	size_t i;

	i = 0;
	if (a <= 0)
		return i;
	r[i++] = a;

	if (b <= 0)
		return i;
	r[i++] = b;

	for (;;) {
		r[i] = a - b;
		if (r[i] <= 0)
			break;

		a = b;
		b = r[i];
		i = i + 1;
	}

	return i;
}

void
test(int a, int b, int *r, size_t nr)
{
	int p[128];
	size_t np;

	np = sumac(a, b, p);
	assert(np == nr);
	if (nr)
		assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main(void)
{
	int r1[] = {120, 71, 49, 22, 27};
	int r2[] = {101, 42, 59};
	int r3[] = {500, 499, 1, 498};
	int r4[] = {387, 1, 386};
	int r5[] = {3};
	int r6[] = {3, 2, 1, 1};

	test(120, 71, r1, nelem(r1));
	test(101, 42, r2, nelem(r2));
	test(500, 499, r3, nelem(r3));
	test(387, 1, r4, nelem(r4));
	test(3, -128, r5, nelem(r5));
	test(-2, 3, NULL, 0);
	test(3, 2, r6, nelem(r6));

	return 0;
}
