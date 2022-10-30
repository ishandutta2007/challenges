/*

Given a square grid of characters in the range ascii[a-z], rearrange elements of each row alphabetically, ascending.
Determine if the columns are also in ascending alphabetical order, top to bottom. Return YES if they are or NO if they are not.

For example, given:

a b c
a d e
e f g

The rows are already in alphabetical order.
The columns a a e, b d f and c e g are also in alphabetical order, so the answer would be YES.
Only elements within the same row can be rearranged. They cannot be moved to a different row.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

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

const char *
sorted(int **m, size_t n)
{
	size_t i, j;

	for (i = 0; i < n; i++)
		qsort(m[i], n, sizeof(m[i][0]), cmp);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (m[i][j] > m[i][j + 1])
				return "NO";
			if (m[j][i] > m[j + 1][i])
				return "NO";
		}
	}

	return "YES";
}

int
main(void)
{
	int **m;

	m = make(3,
	         'a', 'b', 'c',
	         'a', 'd', 'e',
	         'e', 'f', 'g');
	printf("%s\n", sorted(m, 3));
	destroy(m);

	m = make(5,
	         'e', 'b', 'a', 'c', 'd',
	         'f', 'g', 'h', 'i', 'j',
	         'o', 'l', 'm', 'k', 'n',
	         't', 'r', 'p', 'q', 's',
	         'x', 'y', 'w', 'u', 'v');
	printf("%s\n", sorted(m, 5));
	destroy(m);

	m = make(5,
	         'e', 'a', 'b', 'c', 'd',
	         'f', 'g', 'h', 'i', 'j',
	         'o', 'l', 'm', 'k', 'n',
	         't', 'r', 'p', 'q', 's',
	         'x', 'y', 'w', 'u', 'v');
	printf("%s\n", sorted(m, 5));
	destroy(m);

	m = make(3,
	         'a', 'b', 'c',
	         'l', 'm', 'p',
	         'q', 'r', 't');
	printf("%s\n", sorted(m, 3));
	destroy(m);

	m = make(3,
	         'm', 'p', 'x',
	         'a', 'b', 'c',
	         'w', 'l', 'm');
	printf("%s\n", sorted(m, 3));
	destroy(m);

	m = make(3,
	         'a', 'b', 'c',
	         'h', 'j', 'k',
	         'm', 'p', 'q');
	printf("%s\n", sorted(m, 3));
	destroy(m);

	return 0;
}
