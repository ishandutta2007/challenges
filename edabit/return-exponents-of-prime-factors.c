/*

You are given an array of prime factors arr and a target. When each number in the array is raised to an appropriate power their product will be equal to the target.

Your role is to return the exponents. All these arrays will have a length of three.
Basically, it is three numbers whose product is equal to challenge.
The only difference is what you are expected to return.

Examples

productEqualTarget([2, 3, 5], 600) ➞ [3, 1, 2]
// Because 2^3*3^1*5^2 = 600

productEqualTarget([2, 3, 5], 720) ➞ [4, 2, 1]
// Because 2^4*3^2*5^1 = 720

Notes

    The exponents you will return are expected to replace the base in the array.
    Your returned values must be in the same order as the bases.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
expofact(unsigned a[3], unsigned p, unsigned r[3])
{
	size_t i;

	r[0] = r[1] = r[2] = 0;
	for (i = 0; i < 3; i++) {
		if (a[i] < 2)
			continue;

		for (; (p % a[i]) == 0; p /= a[i])
			r[i]++;
	}
}

void
test(unsigned a[3], unsigned p, unsigned r[3])
{
	unsigned v[3];

	expofact(a, p, v);
	printf("%u %u %u\n", v[0], v[1], v[2]);
	assert(!memcmp(r, v, sizeof(v)));
}

int
main(void)
{
	unsigned a1[] = {2, 3, 5};
	unsigned r1[] = {4, 2, 1};

	unsigned a2[] = {2, 3, 19};
	unsigned r2[] = {1, 3, 1};

	unsigned a3[] = {2, 3, 5};
	unsigned r3[] = {3, 1, 2};

	unsigned a4[] = {2, 37, 149};
	unsigned r4[] = {1, 1, 1};

	unsigned a5[] = {2, 3, 5};
	unsigned r5[] = {2, 2, 1};

	unsigned a6[] = {2, 5, 2711};
	unsigned r6[] = {2, 1, 1};

	test(a1, 720, r1);
	test(a2, 1026, r2);
	test(a3, 600, r3);
	test(a4, 11026, r4);
	test(a5, 180, r5);
	test(a6, 54220u, r6);

	return 0;
}
