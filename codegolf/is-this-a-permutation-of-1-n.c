/*

Input a non-empty array with n positive integers. Test if the input array contains every integer in 1⋯n.

In case you prefer 0-indexed numbers, you may choose to input an array of non-negative integers, and test if the input array contains every integer in 0⋯(n−1) instead.
All testcases and formula listed below use 1-index. You may need to adjust them if you choose this option.

Input / Output

Input is an array A
with n

positive integers:

A=[A1,…,An]
∀i∈[1,…,n]:Ai>0

Output if input A

satisfies:

∀i∈[1,…,n]:i∈A

Output would be two distinct values, or truthy vs falsy values (swap meaning of truthy / falsy is allowed).

Rules

    This is code-golf, shortest code wins. And since this is code-golf, don't worry about time / memory complexity of your code. You may even timeout on TIO as long as your program works when giving it more time to run.

Testcases

Truthy

1
1,2
2,1
1,3,2
3,1,2
1,2,3,4,5,6,7,8,9,10,11,12
12,11,10,9,8,7,6,5,4,3,2,1
6,3,8,12,1,10,4,2,7,9,5,11
16,37,14,15,23,8,29,35,21,6,5,34,38,9,36,26,24,32,28,7,20,33,39,12,30,27,40,22,11,41,42,1,10,19,2,25,17,13,3,18,31,4

Falsy

2
12
1,1
1,3
2,3
3,3
2,1,3,2
1,4,3,1
4,1,2,4
1,2,2,5,5
1,3,3,3,5
8,7,5,3,4,1,6
5,7,1,4,6,1,8,3
6,3,5,4,7,1,8,1,2
6,5,3,8,2,7,9,4
1,1,1,1,1,1,1,1
1,5,9,13,11,7,3
14,6,12,4,10,8,16,2
34,33,38,17,35,11,36,31,28,14,6,15,18,2,19,40,29,41,9,1,27,23,20,32,26,25,37,8,13,30,39,7,5,3,21,4,11,16,10,22,12,24
38,27,20,23,31,6,2,24,21,31,33,7,26,12,14,17,3,2,28,31,5,23,28,27,37,32,7,39,22,6,35

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	unsigned x, y;

	x = *(unsigned *)a;
	y = *(unsigned *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

bool
permuted(unsigned *a, size_t n)
{
	size_t i;

	qsort(a, n, sizeof(*a), cmp);
	for (i = 0; i < n; i++) {
		if (a[i] != i + 1)
			return false;
	}
	return true;
}

int
main(void)
{
	unsigned a1[] = {1};
	unsigned a2[] = {1, 2};
	unsigned a3[] = {2, 1};
	unsigned a4[] = {1, 3, 2};
	unsigned a5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	unsigned a6[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	unsigned a7[] = {6, 3, 8, 12, 1, 10, 4, 2, 7, 9, 5, 11};
	unsigned a8[] = {16, 37, 14, 15, 23, 8, 29, 35, 21, 6, 5, 34, 38, 9, 36, 26, 24, 32, 28, 7, 20, 33, 39, 12, 30, 27, 40, 22, 11, 41, 42, 1, 10, 19, 2, 25, 17, 13, 3, 18, 31, 4};

	unsigned a9[] = {2};
	unsigned a10[] = {12};
	unsigned a11[] = {1, 1};
	unsigned a12[] = {1, 3};
	unsigned a13[] = {2, 3};
	unsigned a14[] = {3, 3};
	unsigned a15[] = {2, 1, 3, 2};
	unsigned a16[] = {1, 4, 3, 1};
	unsigned a17[] = {4, 1, 2, 4};
	unsigned a18[] = {1, 2, 2, 5, 5};
	unsigned a19[] = {1, 3, 3, 3, 5};
	unsigned a20[] = {8, 7, 5, 3, 4, 1, 6};
	unsigned a21[] = {5, 7, 1, 4, 6, 1, 8, 3};
	unsigned a22[] = {6, 3, 5, 4, 7, 1, 8, 1, 2};
	unsigned a23[] = {6, 5, 3, 8, 2, 7, 9, 4};
	unsigned a24[] = {1, 1, 1, 1, 1, 1, 1, 1};
	unsigned a25[] = {1, 5, 9, 13, 11, 7, 3};
	unsigned a26[] = {14, 6, 12, 4, 10, 8, 16, 2};
	unsigned a27[] = {34, 33, 38, 17, 35, 11, 36, 31, 28, 14, 6, 15, 18, 2, 19, 40, 29, 41, 9, 1, 27, 23, 20, 32, 26, 25, 37, 8, 13, 30, 39, 7, 5, 3, 21, 4, 11, 16, 10, 22, 12, 24};
	unsigned a28[] = {38, 27, 20, 23, 31, 6, 2, 24, 21, 31, 33, 7, 26, 12, 14, 17, 3, 2, 28, 31, 5, 23, 28, 27, 37, 32, 7, 39, 22, 6, 35, 42, 19, 3, 35, 17, 35, 40, 22, 13, 27, 7};

	assert(permuted(a1, nelem(a1)) == true);
	assert(permuted(a2, nelem(a2)) == true);
	assert(permuted(a3, nelem(a3)) == true);
	assert(permuted(a4, nelem(a4)) == true);
	assert(permuted(a5, nelem(a5)) == true);
	assert(permuted(a6, nelem(a6)) == true);
	assert(permuted(a7, nelem(a7)) == true);
	assert(permuted(a8, nelem(a8)) == true);

	assert(permuted(a9, nelem(a9)) == false);
	assert(permuted(a10, nelem(a10)) == false);
	assert(permuted(a11, nelem(a11)) == false);
	assert(permuted(a12, nelem(a12)) == false);
	assert(permuted(a13, nelem(a13)) == false);
	assert(permuted(a14, nelem(a14)) == false);
	assert(permuted(a15, nelem(a15)) == false);
	assert(permuted(a16, nelem(a16)) == false);
	assert(permuted(a17, nelem(a17)) == false);
	assert(permuted(a18, nelem(a18)) == false);
	assert(permuted(a19, nelem(a19)) == false);
	assert(permuted(a20, nelem(a20)) == false);
	assert(permuted(a21, nelem(a21)) == false);
	assert(permuted(a22, nelem(a22)) == false);
	assert(permuted(a23, nelem(a23)) == false);
	assert(permuted(a24, nelem(a24)) == false);
	assert(permuted(a25, nelem(a25)) == false);
	assert(permuted(a26, nelem(a26)) == false);
	assert(permuted(a27, nelem(a27)) == false);
	assert(permuted(a28, nelem(a28)) == false);

	return 0;
}
