/*

You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

Example 1:

Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.

Example 2:

Input: k = 2, n = 6
Output: 3

Example 3:

Input: k = 3, n = 14
Output: 4

Constraints:

    1 <= k <= 100
    1 <= n <= 104

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

// https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/
long
supereggdrop(unsigned k, unsigned n)
{
	unsigned **p, *q;
	unsigned i, j, l;
	long r;

	r = -1;
	p = calloc(k + 1, sizeof(*p));
	q = calloc((k + 1) * (n + 1), sizeof(*q));
	if (!p || !q)
		goto out;

	for (i = 0; i <= k; i++)
		p[i] = &q[i * (n + 1)];

	for (i = 1; i <= k; i++)
		p[i][1] = 1;
	for (j = 1; j <= n; j++)
		p[1][j] = j;

	for (i = 2; i <= k; i++) {
		for (j = 2; j <= n; j++) {
			p[i][j] = UINT_MAX;
			for (l = 1; l <= j; l++)
				p[i][j] = min(p[i][j], 1 + max(p[i - 1][l - 1], p[i][j - l]));
		}
	}
	r = p[k][n];

out:
	free(p);
	free(q);
	return r;
}

int
main(void)
{
	assert(supereggdrop(1, 2) == 2);
	assert(supereggdrop(2, 6) == 3);
	assert(supereggdrop(3, 14) == 4);
	assert(supereggdrop(2, 36) == 8);

	return 0;
}
