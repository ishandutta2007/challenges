/*

Take a positive integer N as input, and output a matrix with the numbers 1 .. N2 that follows the pattern below:

Fill in the first row with 1 .. N then fill the last row (row number N) with (N+1) .. 2N, then fill the second row with (2N+1) .. 3N and continue until you have filled all rows.

The output format is flexible, so list of lists etc. are accepted.

N = 1
1

N = 2
1  2
3  4

N = 3
1  2  3
7  8  9
4  5  6

N = 4
 1  2  3  4
 9 10 11 12
13 14 15 16
 5  6  7  8

N = 5
 1  2  3  4  5
11 12 13 14 15
21 22 23 24 25
16 17 18 19 20
 6  7  8  9 10

Standard rules apply. Shortest answer in bytes in each language wins. Explanations are encouraged as always.

*/

#include <stdio.h>

void
fill(size_t n, unsigned m[n][n])
{
	size_t c, i, j, k, l;
	unsigned v;

	if (n == 0)
		return;

	v = 1;
	i = 0;
	k = n - 1;
	for (c = 0; i <= k; c++) {
		if (!(c & 1)) {
			l = i;
			i++;
		} else {
			l = k;
			k--;
		}

		for (j = 0; j < n; j++)
			m[l][j] = v++;
	}
}

void
dump(size_t n, unsigned m[n][n])
{
	size_t i, j;

	printf("N = %zu\n", n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%-2d ", m[i][j]);
		printf("\n");
	}
	printf("\n");
}

void
test(size_t n)
{
	unsigned m[n][n];

	fill(n, m);
	dump(n, m);
}

int
main(void)
{
	int i;

	for (i = 1; i <= 5; i++)
		test(i);
	return 0;
}
