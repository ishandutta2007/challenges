/*

Mubashir and his friend Matt found some gold piles. They decided to follow simple rules to distribute the gold among them.

    Gold will be divided into n piles.
    Each person will choose bigger gold pile either from far left or far right.
    If the weight of both piles is equal then the person will choose left pile.

Help them by creating a function that takes an array of gold piles gold and returns a two-element array with [Mubashir's Gold, Matt's Gold].

Examples

goldDistribution([4, 2, 9, 5, 2, 7]) ➞ [14, 15]
// Mubashir will choose 7, Remaining piles = [4, 2, 9, 5, 2]
// Matt will choose 4, Remaining piles = [2, 9, 5, 2]
// Mubashir will choose 2, Remaining piles = [9, 5, 2]
// Matt will choose 9, Remaining piles = [5, 2]
// Mubashir will choose 5, Remaining piles = [2]
// Matt will choose 2
// Mubashir = 7+2+5 = 14, Matt = 4+9+2 = 15

goldDistribution([10, 1000, 2, 1]) ➞ [12, 1001]

goldDistribution([10, 9, 1, 2, 8, 4]) ➞ [16, 18]

Notes

Mubashir gets to pick his gold first!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
distribution(unsigned *a, size_t n, unsigned r[2])
{
	size_t i, j, k;

	r[0] = r[1] = 0;

	j = 0;
	k = n;
	for (i = 0; j < k; i = !i)
		r[i] += (a[j] >= a[k - 1]) ? a[j++] : a[--k];
}

void
test(unsigned *a, size_t n, unsigned r[2])
{
	unsigned p[2];

	distribution(a, n, p);
	printf("%u %u\n", p[0], p[1]);
	assert(!memcmp(r, p, sizeof(p)));
}

int
main(void)
{
	unsigned a1[] = {4, 2, 9, 5, 2, 7};
	unsigned r1[] = {14, 15};

	unsigned a2[] = {4, 7, 2, 9, 5, 2};
	unsigned r2[] = {11, 18};

	unsigned a3[] = {10, 1000, 2, 1};
	unsigned r3[] = {12, 1001};

	unsigned a4[] = {10, 9, 1, 2, 8, 4};
	unsigned r4[] = {16, 18};

	unsigned a5[] = {9, 32, 12, 43, 1, 55};
	unsigned r5[] = {130, 22};

	unsigned a6[] = {19, 22, 1, 5, 7, 31};
	unsigned r6[] = {58, 27};

	unsigned a7[] = {2, 2, 2, 2, 2, 2};
	unsigned r7[] = {6, 6};

	unsigned a8[] = {40};
	unsigned r8[] = {40, 0};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);
	test(a5, nelem(a5), r5);
	test(a6, nelem(a6), r6);
	test(a7, nelem(a7), r7);
	test(a8, nelem(a8), r8);

	return 0;
}
