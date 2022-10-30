// Our binary search makes two tests inside the loop, when one would suffice (at
// the price of more tests outside). Write a version with only one test inside the
// loop and measure the difference in run-time.

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
binsearch(int x, int v[], int n)
{
	int l, h, m;

	l = 0;
	h = n - 1;
	m = (l + h) / 2;
	while (l <= h && x != v[m]) {
		if (x < v[m])
			h = m - 1;
		else
			l = m + 1;
		m = (l + h) / 2;
	}

	if (x == v[m])
		return m;

	return -1;
}

int
main(void)
{
	int a[] = {1, 2, 3, 4, 5, 6};
	for (size_t i = 0; i < nelem(a); i++)
		printf("%d\n", binsearch(a[i], a, nelem(a)));
	printf("%d\n", binsearch(1000, a, nelem(a)));
	printf("%d\n", binsearch(-1, a, nelem(a)));
	return 0;
}
