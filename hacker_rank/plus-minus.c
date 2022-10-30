/*
Given an array of integers, calculate the fractions of its elements that are positive, negative, and are zeros.
Print the decimal value of each fraction on a new line.

Note: This challenge introduces precision problems. The test cases are scaled to six decimal places,
though answers with absolute error of up to 10^-4 are acceptable.

For example, given the array  there are  elements, two positive, two negative and one zero. Their ratios would be 2/5, 2/5 and 1/5.
It should be printed as

0.400000
0.400000
0.200000
*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
plusminus(int *a, size_t n)
{
	size_t f[3] = {0};
	size_t i;

	for (i = 0; i < n; i++) {
		if (a[i] < 0)
			f[1]++;
		else if (a[i] == 0)
			f[2]++;
		else
			f[0]++;
	}

	for (i = 0; i < 3; i++)
		printf("%.6f\n", f[i] * 1.0 / n);
	printf("\n");
}

int
main(void)
{
	int a[] = {1, 1, 0, -1, -1};
	plusminus(a, nelem(a));

	int b[] = {-4, 3, -9, 0, 4, 1};
	plusminus(b, nelem(b));

	return 0;
}
