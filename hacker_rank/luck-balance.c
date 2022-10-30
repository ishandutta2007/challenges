/*

Lena is preparing for an important coding competition that is preceded by a number of sequential preliminary contests. 
She believes in "saving luck", and wants to check her theory. Each contest is described by two integers L[i] and T[i]

L[i] is the amount of luck associated with a contest.
If Lena wins the contest, her luck balance will decrease by L[i] if she loses it, her luck balance will increase by L[i]

T[i] denotes the contest's importance rating. It's equal to 1 if the contest is important, and it's equal to 0 if it's unimportant.

If Lena loses no more than k important contests, what is the maximum amount of luck she can have after competing in all the preliminary contests?
This value may be negative.

For example, k=2 and:

Contest		L[i]	T[i]
1		5	1
2		1	1
3		4	0

If Lena loses all of the contests, her will be 5+1+4=10
Since she is allowed to lose 2 important contests, and there are 
only 2 important contests.
She can lose all three contests to maximize her luck at 10. If k=1,
she has to win at least 1 of the important contests. 
She would choose to win the lowest value important contest worth 1. Her final luck will be 5+4-1=8.

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct Heap Heap;

struct Heap {
	size_t i;
	size_t n;
	int a[];
};

void
swap(int *x, int *y)
{
	int z;

	z = *y;
	*y = *x;
	*x = z;
}

Heap *
hnew(size_t n)
{
	Heap *h;

	h = calloc(1, sizeof(*h) + sizeof(*h->a) * n);
	h->n = n;
	if (h == NULL)
		return NULL;
	return h;
}

size_t
hlen(Heap *h)
{
	return h->i - 1;
}

int
hmin(Heap *h)
{
	return h->a[1];
}

void
hup(Heap *h, size_t i)
{
	size_t j;

	for (;;) {
		j = i / 2;
		if (j == 0)
			break;

		if (h->a[i] < h->a[j])
			swap(&h->a[i], &h->a[j]);
		else
			break;
	}
}

void
hdown(Heap *h, size_t i)
{
	size_t j, l, r;

	for (;;) {
		l = 2 * i;
		r = 2 * i + 1;
		j = l;
		if (r <= h->i && h->a[r] < h->a[l])
			j = r;
		if (j <= h->i)
			swap(&h->a[j], &h->a[i]);
		else
			break;
		i = j;
	}
}

void
heapify(Heap *h, size_t i)
{
	size_t j;

	j = i / 2;
	if (j == 0 || h->a[i] > h->a[j])
		hdown(h, i);
	else
		hup(h, i);
}

Heap *
hinsert(Heap *h, int v)
{
	if (++h->i >= h->n) {
		h = realloc(h, sizeof(*h) + sizeof(*h->a) * h->n * 2);
		if (h == NULL)
			abort();
		h->n *= 2;
	}

	h->a[h->i] = v;
	heapify(h, h->i);

	return h;
}

int
hpop(Heap *h)
{
	int v;

	if (h->i < 1)
		return INT_MIN;

	v = h->a[1];
	h->a[1] = h->a[h->i--];
	heapify(h, 1);
	return v;
}

int
hpopl(Heap *h)
{
	if (h->i < 1)
		return INT_MIN;
	return h->a[h->i--];
}

void
hfree(Heap *h)
{
	free(h);
}

int
luckbalance(int a[][2], size_t n, size_t k)
{
	Heap *h;
	size_t i, j, m;
	int l;

	if (n == 0)
		return 0;
	if (k >= n)
		return INT_MIN;

	h = hnew(k + 1);
	if (h == NULL)
		return INT_MIN;

	l = 0;
	j = 0;
	for (i = 0; i < n; i++) {
		l += a[i][0];
		if (a[i][1] == 1) {
			hinsert(h, a[i][0]);
			j++;
		}
	}

	m = j;
	if (j >= k)
		m -= k;

	for (i = 0; i < m; i++)
		l -= 2 * hpop(h);

	hfree(h);
	return l;
}

int
main(void)
{
	int a[][2] = {
	    {5, 1},
	    {1, 1},
	    {4, 0},
	};
	printf("%d\n", luckbalance(a, nelem(a), 2));

	int b[][2] = {
	    {5, 1},
	    {2, 1},
	    {1, 1},
	    {8, 1},
	    {10, 0},
	    {5, 0},
	};
	printf("%d\n", luckbalance(b, nelem(b), 3));

	int c[][2] = {
	    {5, 1},
	    {4, 0},
	    {6, 1},
	    {2, 1},
	    {8, 0},
	};
	printf("%d\n", luckbalance(c, nelem(c), 2));

	int d[][2] = {
	    {13, 1},
	    {10, 1},
	    {9, 1},
	    {8, 1},
	    {13, 1},
	    {12, 1},
	    {18, 1},
	    {13, 1},
	};
	printf("%d\n", luckbalance(d, nelem(d), 5));

	return 0;
}
