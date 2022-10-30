/*

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int
min3(int a, int b, int c)
{
	if (c < b)
		swap(&b, &c);
	if (b < a)
		swap(&a, &b);
	return a;
}

size_t
edit(const char *s, const char *t)
{
	size_t **d, *a, i, j, m, n, c;

	m = strlen(s);
	n = strlen(t);

	a = calloc((m + 1) * (n + 1), sizeof(*a));
	d = calloc(m + 1, sizeof(*d));
	if (!a || !d)
		goto error;
	for (i = 0; i <= m; i++)
		d[i] = &a[i * (n + 1)];

	for (i = 1; i <= m; i++)
		d[i][0] = i;
	for (j = 1; j <= n; j++)
		d[0][j] = j;

	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (s[i - 1] == t[j - 1])
				d[i][j] = d[i - 1][j - 1];
			else
				d[i][j] = min3(d[i][j - 1] + 1, d[i - 1][j] + 1, d[i - 1][j - 1] + 1);
		}
	}

	c = d[m][n];
	if (0) {
	error:
		c = SIZE_MAX;
	}
	free(a);
	free(d);

	return c;
}

int
main(void)
{
	printf("%zu\n", edit("horse", "ros"));
	printf("%zu\n", edit("intention", "execution"));
	printf("%zu\n", edit("word", "wood"));
	printf("%zu\n", edit("word", "woord"));
	printf("%zu\n", edit("d", "word"));
	printf("%zu\n", edit("", "word"));
	printf("%zu\n", edit("abcd", "word"));
	printf("%zu\n", edit("ffff", "word"));
	printf("%zu\n", edit("kitten", "sitting"));
	printf("%zu\n", edit("Saturday", "Sunday"));
	return 0;
}
