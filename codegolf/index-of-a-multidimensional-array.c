/*

Lower level languages, such as C and C++ actually have no concept of multidimensional arrays. (Other than vectors and dynamic arrays) When you create a multidimensional array with

int foo[5][10];
This is actually just syntactic sugar. What C really does is create a single contiguous array of 5 * 10 elements. This

foo[4][2]
is also syntactic sugar. This really refers to the element at

4 * 10 + 2
or, the 42nd element. In general, the index of element [a][b] in array foo[x][y] is at

a * y + b
The same concept applies to 3d arrays. If we have foo[x][y][z] and we access element [a][b][c] we are really accessing element:

a * y * z + b * z + c
This concept applies to n-dimensional arrays. If we have an array with dimensions D1, D2, D3 ... Dn and we access element S1, S2, S3 ... Sn the formula is

(S1 * D2 * D3 ... * Dn) + (S2 * D3 * D4 ... * Dn) + (S3 * D4 ... * Dn) ... + (Sn-1 * Dn) + Sn
The challenge
You must write a program or function that calculates the index of a multidimensional array according to the formula above.
Input will be two arrays. The first array is the dimensions, and the second array is the indices. The length of these two arrays will always be equal and at least 1.

You can safely assume that every number in the arrays will be an non-negative integer. You can also assume that you will not get a 0 in the dimension array, although a 0 might be in the indices. You can also assume that indices will not be larger than the dimensions.

Test IO
Dimensions: [5, 10]
Indices: [4, 2]
Output: 42

Dimensions: [10, 10, 4, 62, 7]
Indices: [1, 2, 3, 4, 5]
Output: 22167

Dimensions: [5, 1, 10]
Indices: [3, 0, 7]
Output: 37

Dimensions: [6, 6, 6, 6, 6, 6, 6, 6, 6, 6]
Indices: [3, 1, 5, 5, 3, 0, 5, 2, 5, 4]
Output: 33570178

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
index(uvlong *d, uvlong *s, size_t n)
{
	uvlong i, j, r, v;

	r = 0;
	for (i = 0; i < n; i++) {
		v = s[i];
		for (j = i + 1; j < n; j++)
			v *= d[j];
		r += v;
	}
	return r;
}

int
main(void)
{
	uvlong d1[] = {5, 10};
	uvlong s1[] = {4, 2};

	uvlong d2[] = {10, 10, 4, 62, 7};
	uvlong s2[] = {1, 2, 3, 4, 5};

	uvlong d3[] = {5, 1, 10};
	uvlong s3[] = {3, 0, 7};

	uvlong d4[] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
	uvlong s4[] = {3, 1, 5, 5, 3, 0, 5, 2, 5, 4};

	assert(index(d1, s1, nelem(d1)) == 42ULL);
	assert(index(d2, s2, nelem(d2)) == 22167ULL);
	assert(index(d3, s3, nelem(d3)) == 37ULL);
	assert(index(d4, s4, nelem(d4)) == 33570178ULL);

	return 0;
}
