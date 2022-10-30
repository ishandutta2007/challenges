/*

To train for an upcoming marathon, Johnny goes on one long-distance run each Saturday. He wants to track how often the number of miles he runs this Saturday exceeds the number of miles run the previous Saturday. This is called a progress day.

Create a function that takes in an array of miles run every Saturday and returns Johnny's total number of progress days.
Examples

progressDays([3, 4, 1, 2]) ➞ 2
// There are two progress days, (3->4) and (1->2)

progressDays([10, 11, 12, 9, 10]) ➞ 3

progressDays([6, 5, 4, 3, 2, 9]) ➞ 1

progressDays([9, 9])  ➞ 0

Notes

Running the same number of miles as last week does not count as a progress day.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
progressdays(unsigned *a, size_t n)
{
	size_t i, p;

	if (n == 0)
		return 0;

	for (i = p = 0; i < n - 1; i++) {
		if (a[i] < a[i + 1])
			p++;
	}
	return p;
}

int
main(void)
{
	unsigned a1[] = { 3, 4, 1, 2 };
	unsigned a2[] = { 10, 11, 12, 9, 10 };
	unsigned a3[] = { 6, 5, 4, 3, 2, 9 };
	unsigned a4[] = { 9, 9 };
	unsigned a5[] = { 12, 11, 10, 12, 11, 13 };

	assert(progressdays(a1, nelem(a1)) == 2);
	assert(progressdays(a2, nelem(a2)) == 3);
	assert(progressdays(a3, nelem(a3)) == 1);
	assert(progressdays(a4, nelem(a4)) == 0);
	assert(progressdays(a5, nelem(a5)) == 2);

	return 0;
}
