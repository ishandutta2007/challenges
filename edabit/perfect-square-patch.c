/*

Create a function that takes an integer and outputs an n x n square solely consisting of the integer n.

Notes

    n >= 0.
    If n = 0, return an empty array of empty arrays, or [[]].

*/

#include <stdio.h>
#include <stdlib.h>

unsigned *
squarepatch(unsigned n)
{
	unsigned *p, i, j;

	if (n <= 0)
		return NULL;

	p = calloc(n * n, sizeof(n));
	if (!p)
		return NULL;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			p[i * n + j] = n;
	}
	return p;
}

void
print(unsigned *p, unsigned n)
{
	unsigned i, j;

	if (p == NULL) {
		printf("[]\n\n");
		return;
	}

	for (i = 0; i < n; i++) {
		printf("[");
		for (j = 0; j < n; j++) {
			printf("%u", p[i * n + j]);
			if (j + 1 < n)
				printf(" ");
		}
		printf("]\n");
	}
	printf("\n");
}

void
test(unsigned n)
{
	unsigned *p;

	p = squarepatch(n);
	print(p, n);
	free(p);
}

int
main(void)
{
	int i;

	for (i = 0; i <= 8; i++)
		test(i);
	return 0;
}
