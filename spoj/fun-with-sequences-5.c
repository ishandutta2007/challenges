/*

You are given S - a sequence of n integers S = s1, s2, ..., sn.
Please, compute if it is possible to split S into two parts: s1, s2, ..., si and si+1, si+2, ..., sn (1 <= i < n) in such a way that the first part is strictly decreasing while the second is strictly increasing one.

Input data specification
In the first line you are given an integer 2<=n<=100 and in the following line n integers
-100 <= si <= 100.

Output data specification
One word Yes or No.

Example 1
Input:
5
-1 2 -1 1 -1

Output:
No

Example 2
Input:
6
3 1 -2 -2 -1 3

Output:
Yes

Example 3
Input:
6
2 2 1 0 1 2

Output:
No

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
flow(int *a, size_t n, size_t *i)
{
	int f;

	for (f = 0; *i < n; *i += 1) {
		if (f == 0)
			f = (a[*i] <= a[*i - 1]) ? 1 : 2;
		if (a[*i] <= a[*i - 1] && f != 1)
			break;
		if (a[*i] >= a[*i - 1] && f != 2)
			break;
	}
	*i += 1;

	return f;
}

bool
possible(int *a, size_t n)
{
	size_t i;
	int f, g;

	i = 1;
	f = flow(a, n, &i);
	g = flow(a, n, &i);

	return i >= n && f == 1 && g == 2;
}

int
main(void)
{
	int a1[] = {-1, 2, -1, 1, -1};
	int a2[] = {3, 1, -2, -2, -1, 3};
	int a3[] = {2, 2, 1, 0, 1, 2};
	int a4[] = {4, 3, 2, 1, 2, 3, 4};
	int a5[] = {4, 3, 3, 4, 4};
	int a6[] = {4, 3, 3, 4, 4, 3};
	int a7[] = {1, 2};
	int a8[] = {99};
	int a9[] = {99, 98};

	assert(possible(a1, nelem(a1)) == false);
	assert(possible(a2, nelem(a2)) == true);
	assert(possible(a3, nelem(a3)) == false);
	assert(possible(a4, nelem(a4)) == true);
	assert(possible(a5, nelem(a5)) == true);
	assert(possible(a6, nelem(a6)) == false);
	assert(possible(a7, nelem(a7)) == false);
	assert(possible(a8, nelem(a8)) == false);
	assert(possible(a9, nelem(a9)) == false);

	return 0;
}
