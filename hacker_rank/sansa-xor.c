/*

Sansa has an array. She wants to find the value obtained by XOR-ing the contiguous subarrays, followed by XOR-ing the values thus obtained. Determine this value.

For example, if arr=[3, 4, 5]

Subarray	Operation	Result
3		None		3
4		None		4
5		None		5
3,4		3 XOR 4		7
4,5		4 XOR 5		1
3,4,5		3 XOR 4 XOR 5	2

Now we take the resultant values and XOR them together:
3 ^ 4 ^ 5 ^ 7 ^ 1 ^ 2 = 0

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) /sizeof(x[0]))

// x ^ x = 0
// x ^ 0 = x
// since we are calculating subarrays, each element will be xored with itself based on how the length of the array
// if an element appears an even number of time, it will be (x^x^x...^x) = 0
// otherwise, if it is odd, it will be x

// for odd indexed elements, the subarray will be even, so it will be 0
// for even indexed elements, it will appear odd number of times, so we only need to xor the even indices
// since the odd indices will cancel out

int
sansaxor(int *a, size_t n)
{
	size_t i;
	int r;

	if ((n & 1) == 0)
		return 0;

	r = 0;
	for (i = 0; i < n; i += 2)
		r ^= a[i];
	return r;
}

int
main(void)
{
	int a[] = {1, 2, 3};
	printf("%d\n", sansaxor(a, nelem(a)));

	int b[] = {4, 5, 7, 5};
	printf("%d\n", sansaxor(b, nelem(b)));

	int c[] = {98, 74, 12};
	printf("%d\n", sansaxor(c, nelem(c)));

	int d[] = {50, 13, 2};
	printf("%d\n", sansaxor(d, nelem(d)));

	int e[] = {3, 4, 5};
	printf("%d\n", sansaxor(e, nelem(e)));

	return 0;
}
