/*

Given an array of distinct integers, create a function that checks if the array is sorted and rotated clockwise. If so, return "YES"; otherwise return "NO".

Examples

check([3, 4, 5, 1, 2]) ➞ "YES"
// The above array is sorted and rotated.
// Sorted array: [1, 2, 3, 4, 5].
// Rotating this sorted array clockwise
// by 3 positions, we get: [3, 4, 5, 1, 2].

check([1, 2, 3]) ➞ "NO"
// The above array is sorted but not rotated.

check([7, 9, 11, 12, 5]) ➞ "YES"
// The above array is sorted and rotated.
// Sorted array: [5, 7, 9, 11, 12].
// Rotating this sorted array clockwise
// by 4 positions, we get: [7, 9, 11, 12, 5].

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
check(int *a, size_t n)
{
	size_t i, j;
	int v;

	if (n == 0)
		return "YES";

	v = a[0];
	j = 0;
	for (i = 1; i < n; i++) {
		if (v > a[i]) {
			v = a[i];
			j = i;
		}
	}
	if (j == 0)
		return "NO";

	for (i = 0; i < n - 1; i++) {
		if (a[(j + i) % n] > a[(j + i + 1) % n])
			return "NO";
	}

	return "YES";
}

void
test(int *a, size_t n, const char *r)
{
	const char *p;

	p = check(a, n);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	int a1[] = {3, 4, 5, 1, 2};
	int a2[] = {1, 2, 3};
	int a3[] = {7, 9, 11, 12, 5};
	int a4[] = {13, 22, 34, 1, 11};
	int a5[] = {5, 3, 4, 1};
	int a6[] = {100, 120, 130, 50, 120, 111};

	test(a1, nelem(a1), "YES");
	test(a2, nelem(a2), "NO");
	test(a3, nelem(a3), "YES");
	test(a4, nelem(a4), "YES");
	test(a5, nelem(a5), "NO");
	test(a6, nelem(a6), "NO");

	return 0;
}
