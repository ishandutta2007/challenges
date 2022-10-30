/*

Pk(n) means the amount of partitions of n into exactly k parts. Given n and k, calculate Pk(n).

Tip: Pk(n) = Pk(n−k) + Pk−1(n−1), with initial values p0(0) = 1 and pk(n) = 0 if n ≤ 0 or k ≤ 0.
https://en.wikipedia.org/wiki/Partition_(number_theory)#Restricted_part_size_or_number_of_parts

Examples
n    k    Ans
1    1    1
2    2    1
4    2    2
6    2    3
10   3    8

Rules
General code-golf rules apply.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int
partition(int n, int k)
{
	int **p, *t;
	int N, K;
	int a, b;
	int i, r;

	if (n < 0 || k < 0)
		return 0;

	r = -1;
	p = calloc(n + 1, sizeof(*p));
	t = calloc((n + 1) * (k + 1), sizeof(*t));
	if (!p || !t)
		goto out;

	for (i = 0; i <= n; i++)
		p[i] = &t[i * (k + 1)];

	p[0][0] = 1;
	for (N = 0; N <= n; N++) {
		for (K = 0; K <= k; K++) {
			a = b = 0;
			if (N - K >= 0)
				a = p[N - K][K];
			if (N - 1 >= 0 && K - 1 >= 0)
				b = p[N - 1][K - 1];
			p[N][K] = a + b;
		}
	}

	r = p[n][k];
out:
	free(t);
	free(p);
	return r;
}

int
main(void)
{
	assert(partition(1, 1) == 1);
	assert(partition(2, 2) == 1);
	assert(partition(4, 2) == 2);
	assert(partition(6, 2) == 3);
	assert(partition(10, 3) == 8);

	return 0;
}
