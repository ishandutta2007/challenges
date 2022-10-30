/*

Mirko has N items (labeled with numbers from 1 to N) and L drawers (labeled with numbers from 1 to L).
All items are currently scattered throughout his room, so he decided to clean them up.
Each drawer can contain one item, and in order to make it easier for Mirko to find them later, he has determined in advance exactly two drawers (Ai and Bi) for each item i.

Mirko stores the items in order from 1 to N using the first rule he can apply:

If the drawer Ai is empty, he stores the item i in that drawer.

If the drawer Bi is empty, he stores the item i

in that drawer.

Try to move the item from Ai to its other drawer; if that one’s filled too, try moving that item to its other drawer, and so on until you either succeed or get back to a previously seen drawer.
In case of success, store the item i in the drawer Ai.
In case of failure, continue to next rule.

Try moving the item from Bi to its other drawer; if that one’s filled too, try moving that item to its other drawer, and so on until you either succeed or get back to a previously seen drawer.
In case of success, store the item i in the drawer Bi.
In case of failure, continue to next rule.

Give up and throw away the item i.
For given pairs of drawers for each item, determine which items will be stored and which will be thrown away.

Input

The first line of input consists of two integers, N and L (1≤N,L≤300000), the number of items and the number of drawers.

Each of the following N lines contains two integers: Ai and Bi (1≤Ai,Bi≤L), the pair of drawers corresponding to item i. The numbers Ai and Bi will be different.

Output

For each item, respectively, output where it ends up. In case the item is stored successfully, output “LADICA” (without quotes, Croatian word for drawer).
In case the item is thrown away, output “SMECE” (without quotes, Croatian word for trash).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef struct {
	int *rank;
	int *used;
} uf_t;

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void
uffree(uf_t *u)
{
	free(u->rank);
	free(u->used);
}

int
ufalloc(uf_t *u, size_t l)
{
	size_t i;

	u->rank = calloc(l, sizeof(*u->rank));
	u->used = calloc(l, sizeof(*u->used));
	if (!u->rank || !u->used) {
		uffree(u);
		return -errno;
	}

	for (i = 0; i < l; i++)
		u->rank[i] = -1;
	return 0;
}

int
ufroot(uf_t *u, int x)
{
	int *p;

	p = u->rank;
	while (p[x] >= 0) {
		if (p[p[x]] >= 0)
			p[x] = p[p[x]];
		x = p[x];
	}
	return x;
}

int
ufunion(uf_t *u, int a, int b)
{
	int ra, rb;

	ra = ufroot(u, a);
	rb = ufroot(u, b);
	if (ra - rb != 0) {
		if (u->rank[ra] > u->rank[rb])
			swap(&ra, &rb);

		u->rank[ra] += u->rank[rb];
		u->rank[rb] = ra;
		u->used[ra] += u->used[rb];
	}

	if (u->used[ra] < -u->rank[ra]) {
		u->used[ra]++;
		return 1;
	}

	return 0;
}

int
inventorize(size_t n, size_t l, int p[][2], const char **s)
{
	uf_t u;
	size_t i;
	int r;

	r = ufalloc(&u, l);
	if (r < 0)
		return r;

	for (i = 0; i < n; i++) {
		if (ufunion(&u, p[i][0] - 1, p[i][1] - 1))
			s[i] = "LADICA";
		else
			s[i] = "SMECE";
	}

	uffree(&u);
	return 0;
}

void
test(size_t n, size_t l, int p[][2], const char **r)
{
	const char *s[128];
	size_t i;

	assert(inventorize(n, l, p, s) >= 0);
	for (i = 0; i < n; i++)
		assert(!strcmp(s[i], r[i]));
}

int
main(void)
{
	int p1[][2] = {
	    {1, 2},
	    {1, 3},
	    {1, 2},
	    {1, 3},
	    {1, 2},
	};
	const char *r1[] = {
	    "LADICA",
	    "LADICA",
	    "LADICA",
	    "SMECE",
	    "SMECE",
	};

	int p2[][2] = {
	    {1, 2},
	    {3, 4},
	    {5, 6},
	    {7, 8},
	    {9, 10},
	    {2, 3},
	    {1, 5},
	    {8, 2},
	    {7, 9},
	};
	const char *r2[] = {
	    "LADICA",
	    "LADICA",
	    "LADICA",
	    "LADICA",
	    "LADICA",
	    "LADICA",
	    "LADICA",
	    "LADICA",
	    "LADICA",
	};

	test(5, 3, p1, r1);
	test(9, 10, p2, r2);

	return 0;
}
