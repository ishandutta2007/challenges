/*

Given a nonempty list of positive decimal integers, output the largest number from the set of numbers with the fewest digits.

The input list will not be in any particular order and may contain repeated values.

Examples:

[1] -> 1
[9] -> 9
[1729] -> 1729
[1, 1] -> 1
[34, 3] -> 3
[38, 39] -> 39
[409, 12, 13] -> 13
[11, 11, 11, 1] -> 1
[11, 11, 11, 11] -> 11
[78, 99, 620, 1] -> 1
[78, 99, 620, 10] -> 99
[78, 99, 620, 100] -> 99
[1, 5, 9, 12, 63, 102] -> 9
[3451, 29820, 2983, 1223, 1337] -> 3451
[738, 2383, 281, 938, 212, 1010] -> 938

The shortest code in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
count(int n)
{
	int r;

	for (r = 1; n; n /= 10)
		r++;
	return r;
}

int
largest(int *a, size_t n)
{
	int c, d, v;
	size_t i;

	d = 0;
	v = INT_MIN;
	for (i = 0; i < n; i++) {
		c = count(a[i]);
		if (d == 0 || c < d || (c == d && a[i] > v)) {
			d = c;
			v = a[i];
		}
	}
	return v;
}

int
main(void)
{
	int a1[] = {1};
	int a2[] = {9};
	int a3[] = {1729};
	int a4[] = {1, 1};
	int a5[] = {34, 3};
	int a6[] = {38, 39};
	int a7[] = {409, 12, 13};
	int a8[] = {11, 11, 11, 1};
	int a9[] = {11, 11, 11, 11};
	int a10[] = {78, 99, 620, 1};
	int a11[] = {78, 99, 620, 10};
	int a12[] = {78, 99, 620, 100};
	int a13[] = {1, 5, 9, 12, 63, 102};
	int a14[] = {3451, 29820, 2983, 1223, 1337};
	int a15[] = {738, 2383, 281, 938, 212, 1010};

	assert(largest(a1, nelem(a1)) == 1);
	assert(largest(a2, nelem(a2)) == 9);
	assert(largest(a3, nelem(a3)) == 1729);
	assert(largest(a4, nelem(a4)) == 1);
	assert(largest(a5, nelem(a5)) == 3);
	assert(largest(a6, nelem(a6)) == 39);
	assert(largest(a7, nelem(a7)) == 13);
	assert(largest(a8, nelem(a8)) == 1);
	assert(largest(a9, nelem(a9)) == 11);
	assert(largest(a10, nelem(a10)) == 1);
	assert(largest(a11, nelem(a11)) == 99);
	assert(largest(a12, nelem(a12)) == 99);
	assert(largest(a13, nelem(a13)) == 9);
	assert(largest(a14, nelem(a14)) == 3451);
	assert(largest(a15, nelem(a15)) == 938);

	return 0;
}
