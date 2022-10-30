/*

Sergey has made N measurements. Now, he wants to know the average value of the measurements made.

In order to make the average value a better representative of the measurements, before calculating the average,
he wants first to remove the highest K and the lowest K measurements. After that, he will calculate the average value among the remaining N - 2K measurements.

Could you help Sergey to find the average value he will get after these manipulations?

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

double
average(int *a, size_t n, size_t k)
{
	size_t i;
	double s;

	if (2 * k >= n)
		return 0;

	qsort(a, n, sizeof(*a), cmp);
	s = 0;
	for (i = k; i < n - k; i++)
		s += a[i];
	return s / (n - 2 * k);
}

int
main(void)
{
	int a[] = {2, 9, -10, 25, 1};
	printf("%lf\n", average(a, nelem(a), 1));

	int b[] = {2, 9, -10, 25, 1};
	printf("%lf\n", average(b, nelem(b), 0));

	int c[] = {1, 1, 1};
	printf("%lf\n", average(c, nelem(c), 1));

	return 0;
}
