/*

Create a function that takes an array of integers (positive / negative) and return the sum of the numbers that repeat consecutively (return your result as an array).

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
sumc(int *a, size_t n, size_t *l)
{
	size_t i, j, k;
	int r;

	for (i = j = 0; i < n;) {
		r = a[i++];
		k = 1;
		while (i < n && r == a[i]) {
			k++;
			i++;
		}

		a[j++] = r * k;
	}
	*l = j;
}

void
test(int *a, size_t n)
{
	size_t i, l;

	sumc(a, n, &l);
	for (i = 0; i < l; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int
main(void)
{
	int a[] = {0, 7, 7, 7, 5, 4, 9, 9, 0};
	test(a, nelem(a));

	int b[] = {4, 4, 5, 6, 8, 8, 8};
	test(b, nelem(b));

	int c[] = {-5, -5, 7, 7, 12, 0};
	test(c, nelem(c));

	int d[] = {2, 2, 2, 2, 2, 7};
	test(d, nelem(d));

	int e[] = {2, 2, -4, 4, 5, 5, 6, 6, 6, 6, 6, 1};
	test(e, nelem(e));

	int f[] = {3, 3, 3, 3, 1};
	test(f, nelem(f));

	int g[] = {1, -1, -2, 2, 3, -3, 4, -4};
	test(g, nelem(g));

	return 0;
}
