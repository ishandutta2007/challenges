#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
binsearch(int a[], size_t n, int v)
{
	size_t lo, hi, mid;

	lo = 0;
	hi = n - 1;
	if (lo >= n || v <= a[lo])
		return lo;
	if (v > a[hi])
		return hi;
	while (hi - lo != 1) {
		mid = lo + (hi - lo) / 2;
		if (a[mid] < v)
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

size_t
search(int a[], size_t n, int v, bool *f)
{
	size_t l;

	l = binsearch(a, n, v);
	if (f)
		*f = (a[l] == v);
	return l;
}

int
main(void)
{
	int a[] = { 1, 4, 6, 7, 8, 59 };
	printf("%zu\n", search(a, nelem(a), 59, NULL));
	printf("%zu\n", search(a, nelem(a), 4, NULL));
	printf("%zu\n", search(a, nelem(a), 7, NULL));
	printf("%zu\n", search(a, nelem(a), 8, NULL));
	printf("%zu\n", search(a, nelem(a), 6, NULL));
	printf("%zu\n", search(a, nelem(a), 1, NULL));
	printf("%zu\n", search(a, nelem(a), -1, NULL));
	printf("%zu\n", search(a, 0, -1, NULL));

	return 0;
}
