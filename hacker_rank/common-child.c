/*

A string is said to be a child of a another string if it can be formed by deleting 0 or more characters from the other string.
Given two strings of equal length, what's the longest string that can be constructed such that it is a child of both?

For example, ABCD and ABDC have two children with maximum length 3, ABC and ABD.
They can be formed by eliminating either the D or C from both strings.
Note that we will not consider ABCD as a common child because we can't rearrange characters and ABCD ABDC.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int
lcs(const char *a, const char *b)
{
	size_t i, j, n, m;
	int **l, *t, c;

	n = strlen(a) + 1;
	m = strlen(b) + 1;

	c = 0;
	l = calloc(sizeof(*l), n);
	t = calloc(sizeof(*t), n * m);
	if (l == NULL || t == NULL) {
		c = -1;
		goto out;
	}

	for (i = 0; i < n; i++)
		l[i] = &t[i * m];

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < m - 1; j++) {
			if (a[i] == b[j])
				l[i + 1][j + 1] = l[i][j] + 1;
			else
				l[i + 1][j + 1] = max(l[i + 1][j], l[i][j + 1]);
		}
	}
	c = l[n - 1][m - 1];

out:
	free(l);
	free(t);
	return c;
}

int
main(void)
{
	printf("%d\n", lcs("HARRY", "SALLY"));
	printf("%d\n", lcs("AA", "BB"));
	printf("%d\n", lcs("SHINCHAN", "NOHARAAA"));
	printf("%d\n", lcs("ABCDEF", "FBDAMN"));
	printf("%d\n", lcs("abcefd", "abcdef"));
	printf("%d\n", lcs("", ""));
	return 0;
}
