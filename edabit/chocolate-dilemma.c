/*

Two sisters are eating chocolate, whose pieces are represented as subarrays of [l x w].

Write a function that returns true if the total area of chocolate is the same for each sister.

To illustrate:

testFairness([[4, 3], [2, 4], [1, 2]],
[[6, 2], [4, 2], [1, 1], [1, 1]])
➞ true

// Agatha's pieces: [4, 3], [2, 4], [1, 2]
// Bertha's pieces: [6, 2], [4, 2], [1, 1], [1, 1]

// Total area of Agatha's chocolate
// 4x3 + 2x4 + 1x2 = 12 + 8 + 2 = 22

// Total area of Bertha's chocolate is:
// 6x2 + 4x2 + 1x1 + 1x1 = 12 + 8 + 1 + 1 = 22

Examples

testFairness([[1, 2], [2, 1]], [[2, 2]]) ➞ true

testFairness([[1, 2], [2, 1]], [[2, 2], [4, 4]]) ➞ false

testFairness([[2, 2], [2, 2], [2, 2], [2, 2]], [[4, 4]]) ➞ true

testFairness([[1, 5], [6, 3], [1, 1]], [[7, 1], [2, 2], [1, 1]]) ➞ false

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
isfair(unsigned (*a)[2], size_t na, unsigned (*b)[2], size_t nb)
{
	unsigned x, y;
	size_t i;

	x = y = 0;
	for (i = 0; i < na; i++)
		x += a[i][0] * a[i][1];
	for (i = 0; i < nb; i++)
		y += b[i][0] * b[i][1];
	return x == y;
}

int
main(void)
{
	unsigned a1[][2] = { { 4, 3 }, { 2, 4 }, { 1, 2 } };
	unsigned b1[][2] = { { 6, 2 }, { 4, 2 }, { 1, 1 }, { 1, 1 } };

	unsigned a2[][2] = { { 1, 5 }, { 6, 3 }, { 1, 1 } };
	unsigned b2[][2] = { { 7, 1 }, { 2, 2 }, { 1, 1 } };

	unsigned a3[][2] = { { 2, 2 }, { 2, 2 }, { 2, 2 }, { 2, 2 } };
	unsigned b3[][2] = { { 4, 4 } };

	unsigned a4[][2] = { { 1, 2 }, { 2, 1 } };
	unsigned b4[][2] = { { 2, 2 } };

	unsigned a5[][2] = { { 1, 2 }, { 2, 1 } };
	unsigned b5[][2] = { { 2, 2 }, { 4, 4 } };

	unsigned a6[][2] = { { 2, 4 }, { 1, 1 }, { 11, 1 } };
	unsigned b6[][2] = { { 2, 2 }, { 4, 4 } };

	assert(isfair(a1, nelem(a1), b1, nelem(b1)) == 1);
	assert(isfair(a2, nelem(a2), b2, nelem(b2)) == 0);
	assert(isfair(a3, nelem(a3), b3, nelem(b3)) == 1);
	assert(isfair(a4, nelem(a4), b4, nelem(b4)) == 1);
	assert(isfair(a5, nelem(a5), b5, nelem(b5)) == 0);
	assert(isfair(a6, nelem(a6), b6, nelem(b6)) == 1);

	return 0;
}