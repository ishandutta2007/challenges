/*
You are given an array of n integers, arr[0..n], and a positive integer, k.
Find and print the number of (i,j) pairs where i<j and a[i]+a[j] is divisible by k.

For example, a=[1 2 3 4 5 6] and k=5.
Our three pairs meeting the criteria are [1 4] [2 3] and [4 6].
*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
divsumpair(int *a, size_t n, int k)
{
	size_t i, j, c;

	c = 0;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if ((a[i] + a[j]) % k == 0)
				c++;
		}
	}
	printf("%zu\n", c);
	return c;
}

int
main(void)
{
	int a[] = {1, 2, 3, 4, 5, 6};
	divsumpair(a, nelem(a), 5);

	int b[] = {1, 3, 2, 6, 1, 2};
	divsumpair(b, nelem(b), 3);
	return 0;
}
