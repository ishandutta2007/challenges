/*

Input: list of elements and a block size k or some other variable of your choice

Output: return the list of elements with every block of k elements reversed, starting from the beginning of the list.

For instance, given the list 12, 24, 32, 44, 55, 66 and the block size 2, the result is 24, 12, 44, 32, 66, 55.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

void
swapi(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

void
rev(int *a, size_t i, size_t j)
{
	while (i < j)
		swapi(&a[i++], &a[--j]);
}

void
revblk(int *a, size_t n, size_t k)
{
	size_t i, j;

	k = min(n, k);
	for (i = 0; i < n; i = j) {
		j = i + min(n - i, k);
		rev(a, i, j);
	}
}

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
test(int *a, size_t n, size_t k, int *r)
{
	revblk(a, n, k);
	print(a, n);
	assert(!memcmp(a, r, n * sizeof(*r)));
}

int
main(void)
{
	int a1[] = {12, 24, 32, 44, 55, 66};
	int r1[] = {24, 12, 44, 32, 66, 55};

	int a2[] = {50, 30};
	int r2[] = {50, 30};

	test(a1, nelem(a1), 2, r1);
	test(a2, nelem(a2), 1, r2);

	return 0;
}
