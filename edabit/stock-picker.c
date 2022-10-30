/*

Create a function that takes an array of integers that represent the amount in dollars that a single stock is worth,
and return the maximum profit that could have been made by buying stock on day x and selling stock on day y where y>x.

If given the following array:

[44, 30, 24, 32, 35, 30, 40, 38, 15]

... your program should return 16 because at index 2 the stock was worth $24 and at the index 6 the stock was then worth $40,
so if you bought the stock at 24 and sold it on 40, you would have made a profit of $16, which is the maximum profit that could have been made with this list of stock prices.

If there is no profit that could have been made with the stock prices, then your program should return -1 (e.g. [[10, 9, 8, 2]] should return -1).
Examples

stockPicker([10, 12, 4, 5, 9]) ➞ 5

stockPicker([14, 20, 4, 12, 5, 11]) ➞ 8

stockPicker([80, 60, 10, 8]) ➞ -1

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
stockpicker(int *a, size_t n)
{
	int m, p;
	size_t i;

	if (n == 0)
		return -1;

	p = 0;
	m = a[0];
	for (i = 1; i < n; i++) {
		m = min(m, a[i]);
		p = max(p, a[i] - m);
	}
	return (p <= 0) ? -1 : p;
}

int
main(void)
{
	int a1[] = {44, 30, 24, 32, 35, 30, 40, 38, 15};
	int a2[] = {10, 12, 4, 5, 9};
	int a3[] = {14, 20, 4, 12, 5, 11};
	int a4[] = {80, 60, 10, 8};
	int a5[] = {90, 100, 111, 0, 1, 2, 3};
	int a6[] = {1, 2, 4, 10, 100, 2, 3};
	int a7[] = {10, 1000, 1, 1, 1, 2000, 3};
	int a8[] = {7, 1, 5, 5, 2, 1, 3};
	int a9[] = {100, 10, 8, 5};

	assert(stockpicker(a1, nelem(a1)) == 16);
	assert(stockpicker(a2, nelem(a2)) == 5);
	assert(stockpicker(a3, nelem(a3)) == 8);
	assert(stockpicker(a4, nelem(a4)) == -1);
	assert(stockpicker(a5, nelem(a5)) == 21);
	assert(stockpicker(a6, nelem(a6)) == 99);
	assert(stockpicker(a7, nelem(a7)) == 1999);
	assert(stockpicker(a8, nelem(a8)) == 4);
	assert(stockpicker(a9, nelem(a9)) == -1);

	return 0;
}
