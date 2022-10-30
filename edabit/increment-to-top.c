/*

Create a function that returns the total number of steps it takes to transform each element to the maximal element in the array. Each step consists of incrementing a digit by one.
Examples

incrementToTop([3, 4, 5]) ➞ 3
// 3 increments: 3 -> 4, 4 -> 5; 4 -> 5

incrementToTop([4, 3, 4]) ➞ 1

incrementToTop([3, 3, 3]) ➞ 0

incrementToTop([3, 10, 3]) ➞ 14

Notes

    If the array contains only the same digits, return 0 (see example #2).
    Bonus: Can you write a solution that achieves this by only traversing the array once? (i.e. without finding the max before hand)

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
inc2top(int *a, size_t n)
{
	int m, s;
	size_t i;

	m = INT_MIN;
	s = 0;
	for (i = 0; i < n; i++) {
		m = max(m, a[i]);
		s += a[i];
	}

	return m * n - s;
}

int
main(void)
{
	int a1[] = { 3, 4, 5 };
	int a2[] = { 4, 3, 4 };
	int a3[] = { 3, 3, 3 };
	int a4[] = { 3, 10, 3 };
	int a5[] = { 1, 2, 3, 4, 5 };

	assert(inc2top(a1, nelem(a1)) == 3);
	assert(inc2top(a2, nelem(a2)) == 1);
	assert(inc2top(a3, nelem(a3)) == 0);
	assert(inc2top(a4, nelem(a4)) == 14);
	assert(inc2top(a5, nelem(a5)) == 10);
	assert(inc2top(a5, 0) == 0);

	return 0;
}
