/*

Create a function that takes any nonnegative number as an argument and return it with it's digits in descending order. Descending order is when you sort from highest to lowest.
Examples

SortDescending(123) ➞ 321

SortDescending(2619805) ➞ 9865210

SortDescending(73065) ➞ 76530

Notes

You can expect non-negative numbers for all test cases.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

uintmax_t
sortdesc(uintmax_t x)
{
	int d[10], i, j;
	uintmax_t r;

	memset(d, 0, sizeof(d));
	do {
		d[x % 10]++;
		x /= 10;
	} while (x);

	r = 0;
	for (i = 9; i >= 0; i--) {
		for (j = 0; j < d[i]; j++)
			r = (r * 10) + i;
	}
	return r;
}

int
main(void)
{
	assert(sortdesc(UINTMAX_C(123)) == UINTMAX_C(321));
	assert(sortdesc(UINTMAX_C(670276097)) == UINTMAX_C(977766200));
	assert(sortdesc(UINTMAX_C(2619805)) == UINTMAX_C(9865210));
	assert(sortdesc(UINTMAX_C(81294)) == UINTMAX_C(98421));
	assert(sortdesc(UINTMAX_C(0)) == UINTMAX_C(0));
	assert(sortdesc(UINTMAX_C(321)) == UINTMAX_C(321));
	assert(sortdesc(UINTMAX_C(628904)) == UINTMAX_C(986420));
	assert(sortdesc(UINTMAX_C(289327560)) == UINTMAX_C(987653220));
	assert(sortdesc(UINTMAX_C(6456)) == UINTMAX_C(6654));

	return 0;
}
