/*

Given a positive integer N, construct an array A containing N distinct elements such that the sum of any two elements in the array (not necessarily different) is not present in the array.

That is, there have to be no such i,j,k such that

1≤i,j,k≤N
Ai+Aj=Ak.
The elements of the array A should be in the range [1,105]. It is guaranteed that such an array always exists under given constraints.

Input Format

First line of the input contains T, the number of test cases. Then the test cases follow.
Each test case contains a single positive integer N, the size of the array A.

Output Format

For each test case, print N space-separated integers in a single line, describing the contents of the array A.

Constraints
1≤T≤50
1≤N≤1000

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *
gen(size_t n)
{
	size_t i;
	int *a;

	a = calloc(n, sizeof(*a));
	if (!a)
		return NULL;

	for (i = 0; i < n; i++)
		a[i] = 2 * (i + 1) - 1;

	return a;
}

int
verify(int *a, size_t n)
{
	size_t i, j, k;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				if (a[i] + a[j] == a[k])
					return 0;
			}
		}
	}
	return 1;
}

void
test(size_t n)
{
	int *p;

	p = gen(n);
	assert(p != NULL);
	assert(verify(p, n) != 0);
	free(p);
}

int
main(void)
{
	test(1);
	test(2);
	test(3);
	test(1000);

	return 0;
}
