/*

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

#include <stdio.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// boyer-moore majority voting algorithm
int
majority(int *a, size_t n)
{
	size_t i, m, c;

	if (n == 0)
		return -1;

	m = 0;
	c = 1;
	for (i = 1; i < n; i++) {
		(a[m] == a[i]) ? c++ : c--;
		if (c == 0) {
			m = i;
			c = 1;
		}
	}
	return a[m];
}

int
main(void)
{
	int a[] = {3, 2, 3};
	printf("%d\n", majority(a, nelem(a)));

	int b[] = {2, 2, 1, 1, 1, 2, 2};
	printf("%d\n", majority(b, nelem(b)));

	return 0;
}
