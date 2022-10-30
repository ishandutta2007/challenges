/*

Return the coordinates ([row, col]) of the element that differs from the rest.

Notes

Rows and columns are 1-indexed (not zero-indexed).

*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
findwaldo(size_t r, size_t c, char m[r][c], size_t *x, size_t *y)
{
	size_t h[256][3], i, j, k;
	int f;

	memset(h, 0, sizeof(h));
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			k = m[i][j] & 0xff;
			h[k][0]++;
			h[k][1] = i;
			h[k][2] = j;
		}
	}

	*x = SIZE_MAX;
	*y = SIZE_MAX;
	f = 0;
	for (i = 0; i < nelem(h); i++) {
		if (h[i][0] == 1) {
			*x = h[i][1] + 1;
			*y = h[i][2] + 1;
			if (++f > 1)
				return -1;
		}
	}
	return f;
}

void
test(size_t r, size_t c, char m[r][c])
{
	size_t x, y;

	findwaldo(r, c, m, &x, &y);
	printf("%zu %zu\n", x, y);
}

int
main(void)
{
	char w1[3][3] = {
	    {'A', 'A', 'A'},
	    {'A', 'A', 'A'},
	    {'A', 'B', 'A'},
	};
	char w2[2][4] = {
	    {'c', 'c', 'c', 'c'},
	    {'c', 'c', 'c', 'd'},
	};
	char w3[6][4] = {
	    {'O', 'O', 'O', 'O'},
	    {'O', 'O', 'O', 'O'},
	    {'O', 'O', 'O', 'O'},
	    {'O', 'O', 'O', 'O'},
	    {'P', 'O', 'O', 'O'},
	    {'O', 'O', 'O', 'O'},
	};
	char w4[3][4] = {
	    {'X', 'X', 'Y', 'X'},
	    {'X', 'X', 'X', 'X'},
	    {'X', 'X', 'X', 'X'},
	};
	test(3, 3, w1);
	test(2, 4, w2);
	test(6, 4, w3);
	test(3, 4, w4);

	return 0;
}
