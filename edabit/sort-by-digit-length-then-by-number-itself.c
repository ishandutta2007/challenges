/*

Write a function that sorts an array of integers by their digit length in descending order, then settles ties by sorting numbers with the same digit length in ascending order.

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
diglen(unsigned n)
{
	unsigned c;

	c = 0;
	do {
		c++;
		n /= 10;
	} while (n);

	return c;
}

int
cmp(const void *a, const void *b)
{
	unsigned n, m, x, y;

	x = *(unsigned *)a;
	y = *(unsigned *)b;
	n = diglen(x);
	m = diglen(y);
	if (n > m)
		return -1;
	if (n == m) {
		if (x < y)
			return -1;
		if (x == y)
			return 0;
	}
	return 1;
}

void
print(unsigned *d, size_t n)
{
	size_t i;

	printf("[");
	for (i = 0; i < n; i++) {
		printf("%d", d[i]);
		if (i + 1 < n)
			printf(", ");
	}
	printf("]\n");
}

void
test(unsigned *d, size_t n)
{
	qsort(d, n, sizeof(*d), cmp);
	print(d, n);
}

int
main(void)
{
	unsigned d1[] = { 77, 23, 5, 7, 101 };
	unsigned d2[] = { 1, 5, 9, 2, 789, 563, 444 };
	unsigned d3[] = { 53219, 3772, 564, 32, 1 };
	unsigned d4[] = { 9, 667, 87, 56, 3023, 5555, 111 };

	test(d1, nelem(d1));
	test(d2, nelem(d2));
	test(d3, nelem(d3));
	test(d4, nelem(d4));

	return 0;
}
