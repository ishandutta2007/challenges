/*

Roman has no idea, why this problem is called Stone. He also has no idea on how to solve the followong problem: given array of N integers A and a number K.
During a turn the maximal value over all Ai is chosen, let's call it MAX. Then Ai = MAX - Ai is done for every 1 <= i <= N.
Help Roman to find out how will the array look like after K turns.

Input

The numbers N and K are given in the first line of an input. Then N integers are given in the second line which denote the array A.

Output

Output N numbers on a single line. It should be the array A after K turns.

Constraints
1 <= N <= 10^5
0 <= K <= 10^9
Ai does not exceed 2 * 109 by it's absolute value.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

void
dump(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
iterate(int *a, size_t n, size_t k)
{
	size_t i, j;
	int m;

	if (k == 0)
		return;

	k = 2 - (k & 1);
	for (i = 0; i < k; i++) {
		m = INT_MIN;
		for (j = 0; j < n; j++)
			m = max(m, a[j]);

		for (j = 0; j < n; j++)
			a[j] = m - a[j];
	}
}

void
test(int *a, size_t n, size_t k, int *r)
{
	iterate(a, n, k);
	dump(a, n);
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main(void)
{
	int a1[] = {5, -1, 7, 0};
	int r1[] = {2, 8, 0, 7};

	test(a1, nelem(a1), 1, r1);

	return 0;
}
