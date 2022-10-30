// Calculate and print the sum of the elements in an array, keeping in mind that some of those integers may be quite large.

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

long long
sum(long *a, size_t n)
{
	long long s;
	size_t i;

	s = 0;
	for (i = 0; i < n; i++)
		s += a[i];
	return s;
}

int
main(void)
{
	long a[] = {1000000001L, 1000000002L, 1000000003L, 1000000004L, 1000000005L};
	printf("%lld\n", sum(a, nelem(a)));

	return 0;
}
