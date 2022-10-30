// find the average of N integers, show result up to 3 decimal places
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
average(int *a, size_t n)
{
	size_t i;
	double v;

	if (n == 0)
		return 0;

	v = 0;
	for (i = 0; i < n; i++)
		v += a[i];
	v /= n;

	return v;
}

int
main(void)
{
	int a[] = {1, 2, 9, 8};
	printf("%.3lf\n", average(a, nelem(a)));
	return 0;
}
