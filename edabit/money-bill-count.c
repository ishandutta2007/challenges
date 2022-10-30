/*

Create a function billCount that takes two arguments.
The first argument is the amount of money the user has and the second is the array of money bills available.
Return the minimum count of money bills required to equal the user money amount.

billCount(1001, [1, 10, 20])
# User Money = €1000 and Bills Available = [€1, €10, €20]

billCount(1001, [1, 10, 20]) ->51 because 20*50+ 1*1 = 1001
# We require 50  20€ bill and 1 1€ bill to equal €1001.
# Therefore, Minimum Count Money Bills is 50 + 1 = 51.

Examples

billCount(100, [1, 10, 20]) ➞ 5
# Because 20 * 5 = 100

billCount(1050, [1, 10, 20, 100]) ➞ 13
# Because 100 * 10 + 20 * 2 + 10 * 1 = 1050

billCount(3, [1, 10]) ➞ 3
# Because 3 * 1 = 3

billCount(55, [1, 5, 10, 50]) ➞ 2
# Because 50 * 1 + 5 * 1 = 55

Notes

Money amount and bills are all valid.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
billcount(int m, int *b, size_t n)
{
	size_t i;
	int c, r;

	if (n == 0)
		return -1;

	c = 0;
	for (i = 0; i < n && m > 0; i++) {
		if (b[n - i - 1] > m)
			continue;

		r = m / b[n - i - 1];
		c += r;
		m -= b[n - i - 1] * r;
	}

	return (m == 0) ? c : -1;
}

int
main(void)
{
	int a1[] = { 1, 10, 20 };
	int a2[] = { 1, 10, 20, 100 };
	int a3[] = { 1, 10 };
	int a4[] = { 1, 10, 100 };
	int a5[] = { 1, 10, 100 };
	int a6[] = { 1, 10, 20 };
	int a7[] = { 1, 5, 10, 50 };

	assert(billcount(100, a1, nelem(a1)) == 5);
	assert(billcount(1050, a2, nelem(a2)) == 13);
	assert(billcount(3, a3, nelem(a3)) == 3);
	assert(billcount(555, a4, nelem(a4)) == 15);
	assert(billcount(222, a5, nelem(a5)) == 6);
	assert(billcount(60, a6, nelem(a6)) == 3);
	assert(billcount(55, a7, nelem(a7)) == 2);

	return 0;
}
