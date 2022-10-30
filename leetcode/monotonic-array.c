/*

An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
monotonic(int *a, size_t n)
{
	size_t i;
	int f;

	if (n == 0)
		return 1;

	f = 0x3;
	for (i = 0; i < n - 1 && f; i++) {
		if (a[i] < a[i + 1])
			f &= ~0x1;
		if (a[i] > a[i + 1])
			f &= ~0x2;
	}
	return f != 0;
}

int
main(void)
{
	int a[] = {1, 2, 2, 3};
	printf("%d\n", monotonic(a, nelem(a)));

	int b[] = {6, 5, 4, 4};
	printf("%d\n", monotonic(b, nelem(b)));

	int c[] = {1, 3, 2};
	printf("%d\n", monotonic(c, nelem(c)));

	int d[] = {1, 2, 4, 5};
	printf("%d\n", monotonic(d, nelem(d)));

	int e[] = {1, 1, 1};
	printf("%d\n", monotonic(e, nelem(e)));

	return 0;
}
