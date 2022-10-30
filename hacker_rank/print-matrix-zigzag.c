#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
fill(size_t n, int m[][n])
{
	size_t i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			m[i][j] = i * n + j;
	}
}

void
zigzag(size_t n, int m[][n])
{
	size_t i, j, k, r, c;
	int x, y;

	r = c = 0;
	x = -1, y = 1;
	for (i = 1; i < 2 * n; i++) {
		j = (i > n) ? 2 * n - i : i;
		for (k = 0; k < j; k++) {
			printf("(%zu %zu) %d\n", r, c, m[r][c]);
			if (k + 1 < j) {
				r += x;
				c += y;
			}
		}

		if (i & 1)
			(i < n) ? c++ : r++;
		else
			(i < n) ? r++ : c++;

		x = -x;
		y = -y;
	}
	printf("\n");
}

int
main(void)
{
	int a[4][4];
	fill(nelem(a), a);
	zigzag(nelem(a), a);

	int b[1][1];
	fill(nelem(b), b);
	zigzag(nelem(b), b);

	int c[5][5];
	fill(nelem(c), c);
	zigzag(nelem(c), c);

	return 0;
}
