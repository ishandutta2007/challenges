/*

Given a sequence of n integers, p(1), p(2), ..., p(n) where each element is distinct and satisfies 
1 <= p(n) <= n

For each x where 1 <= x <= n, find any integer y such that p(p(y)) = x and print
the value of y on a new line

For example, assume the sequence p=[5 2 1 3 4]. Each value of x is between 1 and 5,
the length of the sequence is analyzed as follows:

1. x=1 -> p[3], p[4] = 3, so p[p[4]] = 1
2. x=2 -> p[2], p[2] = 2, so p[p[2]] = 2
3. x=3 -> p[4], p[5] = 4, so p[p[1]] = 3
4. x=4 -> p[5], p[1] = 5, so p[p[2]] = 4
5. x=5 -> p[1], p[3] = 1, so p[p[2]] = 5

The values for y are [4 2 5 1 3]

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
find(int *a, size_t n, size_t v)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (a[i] == v)
			return i;
	}
	return SIZE_MAX;
}

void
permeq1(int *a, size_t n)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		j = find(a, n, i + 1);
		if (j == SIZE_MAX)
			continue;

		j = find(a, n, j + 1);
		if (j != SIZE_MAX)
			printf("%zu ", j + 1);
	}
	printf("\n");
}

int
permeq2(int *a, size_t n)
{
	size_t i;
	int *p, *q, ret;

	ret = 0;
	p = calloc(n, sizeof(*p));
	q = calloc(n, sizeof(*q));
	if (p == NULL || q == NULL)
		goto error;

	// apply the permutation inversion operator twice
	// the index becomes the previous array values
	for (i = 0; i < n; i++) {
		if (!(1 <= a[i] && a[i] <= n))
			goto error;
		p[a[i] - 1] = i + 1;
	}
	for (i = 0; i < n; i++)
		q[a[i] - 1] = p[i];
	for (i = 0; i < n; i++)
		printf("%d ", q[i]);
	printf("\n");

out:
	free(p);
	free(q);
	return ret;

error:
	ret = -1;
	goto out;
}

void
shuffle(int *a, size_t n)
{
	size_t i, j;
	int t;

	if (n == 0)
		return;

	for (i = n - 1; i >= 1; i--) {
		j = rand() % i;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
}

int
main(void)
{
	int a[] = {5, 2, 1, 3, 4};
	permeq1(a, nelem(a));
	permeq2(a, nelem(a));

	int b[] = {2, 3, 1};
	permeq1(b, nelem(b));
	permeq2(b, nelem(b));

	int c[] = {4, 3, 5, 1, 2};
	permeq1(c, nelem(c));
	permeq2(c, nelem(c));

	int d[] = {1, 2, 3, 4, 5};
	permeq1(d, nelem(d));
	permeq2(d, nelem(d));

	srand(time(NULL));
	int f[32];
	size_t i;
	for (i = 0; i < nelem(f); i++)
		f[i] = i + 1;
	for (i = 0; i < 1000; i++) {
		shuffle(f, nelem(f));
		permeq1(f, nelem(f));
		permeq2(f, nelem(f));
	}
	return 0;
}
