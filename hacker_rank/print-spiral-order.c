#define _GNU_SOURCE
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
spiral(size_t n, int m[n][n])
{
	ssize_t x0, x1, y0, y1;
	ssize_t x, y;

	if (n == 0)
		return;

	x0 = y0 = 0;
	x1 = y1 = n - 1;
	for (;;) {
		if (x0 == x1 && y0 == y1)
			printf("%c", m[y0][x0]);

		if (x0 >= x1 || y0 >= y1)
			break;

		for (x = x0, y = y0; x <= x1; x++)
			printf("%c", m[y][x]);

		for (x = x1, y = y0 + 1; y <= y1; y++)
			printf("%c", m[y][x]);

		for (x = x1 - 1, y = y1; x >= x0; x--)
			printf("%c", m[y][x]);

		for (x = x0, y = y1 - 1; y > y0; y--)
			printf("%c", m[y][x]);

		x0++, y0++;
		x1--, y1--;
	}
	printf("\n");
}

int
main(void)
{
	int a[5][5] = {
	    {'i', 'l', 'o', 'v', 'e'},
	    {'d', 'i', 'n', 't', 'e'},
	    {'n', 'e', 'w', 'e', 'p'},
	    {'a', 'i', 'v', 'r', 'i'},
	    {'m', 'a', 'x', 'e', 'c'},
	};
	spiral(nelem(a), a);

	int b[1][1] = {
	    {'Z'},
	};
	spiral(nelem(b), b);

	int c[2][2] = {
	    {'A', 'B'},
	    {'C', 'D'},
	};
	spiral(nelem(c), c);

	int d[4][4] = {
	    {'1', '2', '3', '4'},
	    {'5', '6', '7', '8'},
	    {'9', '0', 'A', 'B'},
	    {'C', 'D', 'E', 'F'},
	};
	spiral(nelem(d), d);

	return 0;
}
