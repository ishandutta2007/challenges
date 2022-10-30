/*

There's an array A consisting of N non-zero integers A1..N.
A subarray of A is called alternating if any two adjacent elements in it have different signs (i.e. one of them should be negative and the other should be positive).

For each x from 1 to N, compute the length of the longest alternating subarray that starts at x 
- that is, a subarray Ax..y for the maximum possible y ≥ x. The length of such a subarray is y-x+1. 

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
alt(int x, int y)
{
	return ((x < 0 && y > 0) || (x > 0 && y < 0));
}

void
count(int *a, size_t n)
{
	size_t i, j, c;
	for (i = 0; i < n; i++) {
		c = 1;
		for (j = i; j < n - 1; j++, c++) {
			if (!alt(a[j], a[j + 1]))
				break;
		}
		printf("%zu ", c);
	}
	printf("\n");
}

int
main(void)
{
	int a[] = {1, 2, 3, 4};
	count(a, nelem(a));

	int b[] = {1, -5, 1, -5};
	count(b, nelem(b));

	int c[] = {-5, -1, -1, 2, -2, -3};
	count(c, nelem(c));

	int d[] = {1};
	count(d, nelem(d));

	int e[] = {1, -2};
	count(e, nelem(e));

	return 0;
}
