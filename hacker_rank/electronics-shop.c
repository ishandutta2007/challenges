/*

Monica wants to buy a keyboard and a USB drive from her favorite electronics store.
The store has several models of each.
Monica wants to spend as much as possible for the 2 items, given her budget.

Given the price lists for the store's keyboards and USB drives, and Monica's budget,
find and print the amount of money Monica will spend.
If she doesn't have enough money to both a keyboard and a USB drive, print -1 instead.
She will buy only the two required items.

For example, suppose she has b=60 to spend. Three types of keyboards cost [40 50 60].
Two USB drives cost [5 8 12].
She could purchase a 40+12, or a 50+8.
She chooses the latter. She can't buy more than 2 items so she can't spend exactly 60.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
spent1(int b, int *kb, size_t nkb, int *drv, size_t ndrv)
{
	size_t i, j;
	int t;

	t = -1;
	for (i = 0; i < nkb; i++) {
		for (j = 0; j < ndrv; j++) {
			if (kb[i] + drv[j] <= b && t < kb[i] + drv[j])
				t = kb[i] + drv[j];
		}
	}

	return t;
}

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

size_t
binsearch(int a[], size_t n, int v)
{
	size_t lo, hi, mid;

	lo = 0;
	hi = n - 1;
	if (v <= a[lo])
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

int
spent2(int b, int *kb, size_t nkb, int *drv, size_t ndrv)
{
	size_t i, j, k;
	int t, v;

	t = -1;
	if (nkb < 1 || ndrv < 1)
		return t;

	qsort(kb, nkb, sizeof(*kb), cmp);
	qsort(drv, ndrv, sizeof(*drv), cmp);

	nkb = binsearch(kb, nkb, b) + 1;
	ndrv = binsearch(drv, ndrv, b) + 1;

	for (i = nkb - 1;; i--) {
		v = b - kb[i];
		j = binsearch(drv, ndrv, v);
		for (k = 0; k < j; k++) {
			if (drv[j - k] <= v) {
				if (t < kb[i] + drv[j - k])
					t = kb[i] + drv[j - k];
				break;
			}
		}

		if (i == 0)
			break;
	}

	return t;
}

int *
randr(size_t n, size_t m)
{
	int *p;
	size_t i;

	p = calloc(n, sizeof(*p));
	if (p == NULL)
		abort();

	for (i = 0; i < n; i++)
		p[i] = (rand() >> 10) % (rand() % m + 1);
	return p;
}

void
bench(int b, int *kb, size_t nkb, int *drv, size_t ndrv)
{
	clock_t begin, end;
	double ticks;
	int v[2], i;

	for (i = 0; i < 2; i++) {
		begin = clock();
		if (i == 0)
			v[i] = spent1(b, kb, nkb, drv, ndrv);
		else if (i == 1)
			v[i] = spent2(b, kb, nkb, drv, ndrv);
		end = clock();
		ticks = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("spent%d(budget=%d, nkb=%zu, ndrv=%zu) -> %d took %lf\n", i + 1, b, nkb, ndrv, v[i], ticks);
	}

	if (v[0] != v[1])
		printf("ERROR: mismatch calculation!\n");

	printf("\n");
}

int
main(void)
{
	int kb1[] = {3, 1};
	int drv1[] = {5, 2, 8};
	bench(10, kb1, nelem(kb1), drv1, nelem(drv1));

	int kb2[] = {4};
	int drv2[] = {5};
	bench(5, kb2, nelem(kb2), drv2, nelem(drv2));

	int kb3[] = {40, 50, 60};
	int drv3[] = {5, 8, 12};
	bench(60, kb3, nelem(kb3), drv3, nelem(drv3));

	srand(time(NULL));
	int m = 1000;
	for (size_t i = 0; i < 1000; i++) {
		for (size_t j = 0; j < 1000; j++) {
			size_t nk = rand() % 50000 + 1;
			size_t nd = rand() % 50000 + 1;
			int *k = randr(nk, m);
			int *d = randr(nd, m);
			int b = rand() % 100000;

			bench(b, k, nk, d, nd);

			free(k);
			free(d);
		}
		m += 10000;
	}

	return 0;
}
