/*

Find determinant of the following matrix -

|3 0 0 -2 4|
|0 2 0 0 0|
|0 -1 0 5 -3|
|-4 0 1 0 6|
|0 -1 0 3 2|

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int index;
	int value;
	int dir;
} elem_t;

typedef struct {
	size_t size;
	elem_t elem[5];
	int sign;
} perm_t;

void
initperm(perm_t *p)
{
	size_t i;
	elem_t *e;

	p->sign = 1;
	p->size = nelem(p->elem);
	for (i = 0; i < p->size; i++) {
		e = &p->elem[i];
		e->index = i;
		e->value = i;
		e->dir = 0;
	}
}

void
largest(perm_t *p, ssize_t *x, ssize_t *y, int *v)
{
	size_t i, n;
	elem_t *e;

	*x = *y = *v = -1;

	e = p->elem;
	n = p->size;
	for (i = 0; i < n; i++) {
		if (i > 0 && !e[i].dir && e[i].index > e[i - 1].index && e[i].index > *v) {
			*x = i;
			*y = i - 1;
			*v = e[i].index;
		} else if (i < n - 1 && e[i].dir && e[i].index > e[i + 1].index && e[i].index > *v) {
			*x = i;
			*y = i + 1;
			*v = e[i].index;
		}
	}
}

void
reverse(perm_t *p, int v)
{
	size_t i;
	elem_t *e;

	for (i = 0; i < p->size; i++) {
		e = &p->elem[i];
		if (e->index > v)
			e->dir = !e->dir;
	}
}

int
nextperm(perm_t *p)
{
	elem_t *e, t;
	ssize_t x, y;
	int v;

	largest(p, &x, &y, &v);
	if (x == -1)
		return 0;

	e = p->elem;
	t = e[x];
	e[x] = e[y];
	e[y] = t;
	reverse(p, v);
	p->sign *= -1;
	return 1;
}

int
det(int m[5][5])
{
	perm_t p;
	elem_t *e;
	int d, s;
	size_t i;

	initperm(&p);

	d = 0;
	for (;;) {
		s = 1;
		for (i = 0; i < p.size; i++) {
			e = &p.elem[i];
			s *= m[i][e->value];
		}

		d += p.sign * s;
		if (!nextperm(&p))
			break;
	}
	return d;
}

int
main(void)
{
	int a[5][5] = {
	    {3, 0, 0, -2, 4},
	    {0, 2, 0, 0, 0},
	    {0, -1, 0, 5, -3},
	    {-4, 0, 1, 0, 6},
	    {0, -1, 0, 3, 2},
	};
	printf("%d\n", det(a));

	return 0;
}
