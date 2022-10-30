/*

Watson gives an array A of N integers A1, A2, ..., AN to Sherlock. He wants Sherlock to reorganize the array in a way such that no two adjacent numbers differ by more than 1.

Formally, if reorganized array is B1, B2, ..., BN, then the condition that | Bi - Bi + 1 | ≤ 1, for all 1 ≤ i < N(where |x| denotes the absolute value of x) should be met.

Sherlock is not sure that a solution exists, so he asks you.

Input

First line contains T, number of test cases. Each test case consists of N in one line followed by N integers in next line denoting A1, A2, ..., AN.

Output

For each test case, output in one line YES or NO denoting if array A can be reorganized in required way or not.

Constraints
1 ≤ T ≤ 100
1 ≤ N ≤ 10^5
1 ≤ Ai ≤ 10^9
Sum of N over all test cases ≤ 2*10^5

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

bool
exists(int *a, size_t n)
{
	size_t i;

	qsort(a, n, sizeof(*a), cmp);
	for (i = 1; i < n; i++) {
		if (abs(a[i] - a[i - 1]) > 1)
			return false;
	}
	return true;
}

int
main(void)
{
	int a1[] = {3, 2, 2, 3};
	int a2[] = {1, 5};

	assert(exists(a1, nelem(a1)) == true);
	assert(exists(a2, nelem(a2)) == false);

	return 0;
}
