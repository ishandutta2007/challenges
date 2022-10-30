/*

You are working at the cash counter at a fun-fair, and you have different types of coins available to you in infinite quantities. The value of each coin is already given. Can you determine the number of ways of making change for a particular number of units using the given types of coins? 

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

long
coins(long *c, size_t n, long m)
{
	long **l, *t, i, j, x, y, w;

	if (m < 0 || n == 0)
		return 0;

	w = 0;
	l = calloc(sizeof(*l), m + 1);
	t = calloc(sizeof(*t), (m + 1) * n);
	if (l == NULL || t == NULL) {
		w = -1;
		goto out;
	}
	for (i = 0; i < m + 1; i++)
		l[i] = &t[i * n];

	for (i = 0; i < n; i++)
		l[0][i] = 1;

	for (i = 1; i < m + 1; i++) {
		for (j = 0; j < n; j++) {
			x = (i >= c[j]) ? l[i - c[j]][j] : 0;
			y = (j >= 1) ? l[i][j - 1] : 0;
			l[i][j] = x + y;
		}
	}
	w = l[m][n - 1];

out:
	free(l);
	free(t);
	return w;
}

int
main(void)
{
	long a[] = {8, 3, 1, 2};
	printf("%ld\n", coins(a, nelem(a), 3));

	long b[] = {1, 2, 3};
	printf("%ld\n", coins(b, nelem(b), 4));

	long c[] = {2, 5, 3, 6};
	printf("%ld\n", coins(c, nelem(c), 10));

	long d[] = {30};
	printf("%ld\n", coins(d, nelem(d), 1));

	long e[] = {1, 2, 3, 4, 5};
	printf("%ld\n", coins(e, nelem(e), 0));

	return 0;
}
