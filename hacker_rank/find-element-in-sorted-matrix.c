// find an element in a sorted nxn matrix and return the index to it
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

int **
make(size_t n, ...)
{
	int **m, *p;
	size_t i, j;
	va_list ap;

	m = calloc(n, sizeof(*m));
	p = calloc(n * n, sizeof(*p));
	if (m == NULL || p == NULL) {
		free(m);
		return NULL;
	}

	for (i = 0; i < n; i++)
		m[i] = &p[i * n];

	va_start(ap, n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			m[i][j] = va_arg(ap, int);
	}
	va_end(ap);

	return m;
}

void
destroy(int **m)
{
	if (m == NULL)
		return;
	free(m[0]);
	free(m);
}

size_t
findrow(int **m, size_t n, int v)
{
	size_t lo, hi, mid;

	if (n == 0)
		return SIZE_MAX;

	lo = 0;
	hi = n - 1;
	if (m[lo][0] <= v && v <= m[lo][n - 1])
		return lo;
	if (m[hi][0] <= v && v <= m[hi][n - 1])
		return hi;
	while (hi - lo != 1) {
		mid = lo + (hi - lo) / 2;
		if (m[mid][0] <= v && v <= m[mid][n - 1])
			return mid;

		if (m[mid][n - 1] < v)
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

size_t
findcol(int **m, size_t n, size_t r, int v)
{
	size_t lo, hi, mid;

	if (n == 0)
		return SIZE_MAX;

	lo = 0;
	hi = n - 1;
	if (v <= m[r][lo])
		return lo;
	if (v > m[r][hi])
		return hi;
	while (hi - lo != 1) {
		mid = lo + (hi - lo) / 2;
		if (m[r][mid] < v)
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

int
find(int **m, size_t n, int v, size_t *r, size_t *c)
{
	*r = findrow(m, n, v);
	if (*r == SIZE_MAX)
		return 0;

	*c = findcol(m, n, *r, v);
	if (*c == SIZE_MAX)
		return 0;

	return m[*r][*c] == v;
}

int
main(void)
{
	int **m, f;
	size_t i, j, r, c;

	m = make(4,
	         1, 2, 3, 4,
	         50, 61, 72, 80,
	         86, 87, 89, 99,
	         113, 140, 150, 270);
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			f = find(m, 4, m[i][j], &r, &c);
			printf("%d %zu %zu\n", f, r, c);
		}
	}
	f = find(m, 4, 2452, &r, &c);
	printf("%d %zu %zu\n", f, r, c);
	destroy(m);

	m = make(1, -23);
	f = find(m, 1, -23, &r, &c);
	printf("%d %zu %zu\n", f, r, c);
	destroy(m);

	return 0;
}
