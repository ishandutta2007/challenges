/*

You are given a square map as a matrix of integer strings. Each cell of the map has a value denoting its depth.
We will call a cell of the map a cavity if and only if this cell is not on the border of the map and each cell
adjacent to it has strictly smaller depth. Two cells are adjacent if they have a common side, or edge.

Find all the cavities on the map and replace their depths with the uppercase character X.

For example, given a matrix:

989
191
111

You should return:

989
1X1
111

The center cell was deeper than those on its edges: [8,1,1,1]. The deep cells in the top two corners don't share an edge with the center cell.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
cavity(size_t n, char g[n][n])
{
	size_t i, j;

	if (n == 0)
		return;

	for (i = 1; i < n - 1; i++) {
		for (j = 1; j < n - 1; j++) {
			if (g[i - 1][j] >= g[i][j])
				continue;
			if (g[i][j - 1] >= g[i][j])
				continue;
			if (g[i + 1][j] >= g[i][j])
				continue;
			if (g[i][j + 1] >= g[i][j])
				continue;
			g[i][j] = 'X';
		}
	}
}

void
print(size_t n, char g[n][n])
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%c", g[i][j]);
		printf("\n");
	}
	printf("\n");
}

void
test(size_t n, char g[n][n])
{
	cavity(n, g);
	print(n, g);
}

int
main(void)
{
	char g1[3][3] = {
	    {'9', '8', '9'},
	    {'1', '9', '1'},
	    {'1', '1', '1'},
	};
	test(nelem(g1), g1);

	char g2[4][4] = {
	    {'1', '1', '1', '2'},
	    {'1', '9', '1', '2'},
	    {'1', '8', '9', '2'},
	    {'1', '2', '3', '4'},
	};
	test(nelem(g2), g2);

	char g3[2][2] = {
	    {'1', '2'},
	    {'1', '2'},
	};
	test(nelem(g3), g3);

	return 0;
}
