/*

Arun is obsessed with primes, especially five. He considers a number to be luckiest if it has the highest number of five in it.
If two numbers have the same frequency of five, Arun considers the larger of them to be luckiest, and if there is no five in any number, the first given number is considered luckiest.
Help him choose the luckiest number.

Examples

getLuckiest([-544, 666, -645, -445]) ➞ -445

getLuckiest([5, 12, 55, 11]) ➞ 55

getLuckiest([5, 12, -55,  11]) ➞ -55

getLuckiest([515, 1255, -55,  1]) ➞ 1255

getLuckiest([44, 12, 7, 40]) ➞ 44

Notes

Return 0 if given an empty array.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
count5(int n)
{
	int r;

	n = abs(n);
	for (r = 0; n; n /= 10)
		r += ((n % 10) == 5);
	return r;
}

int
luckiest(int *a, size_t n)
{
	int v, x, y;
	size_t i;

	if (n == 0)
		return 0;

	v = a[0];
	x = count5(v);
	for (i = 1; i < n; i++) {
		y = count5(a[i]);
		if (x < y || (x == y && y && v < a[i])) {
			v = a[i];
			x = y;
		}
	}
	return v;
}

int
main(void)
{
	int a1[] = {-544, 666, -645, -445};
	int a2[] = {-55, -155, 45, 31, 67};
	int a3[] = {5, 12, 55, 11};
	int a4[] = {5, 12, -55, 11};
	int a5[] = {515, 1255, -55, 1};
	int a6[] = {44, 12, 7, 40};
	int a7[] = {-1, -43, -67, 3};

	assert(luckiest(a1, nelem(a1)) == -445);
	assert(luckiest(NULL, 0) == 0);
	assert(luckiest(a2, nelem(a2)) == -55);
	assert(luckiest(a3, nelem(a3)) == 55);
	assert(luckiest(a4, nelem(a4)) == -55);
	assert(luckiest(a5, nelem(a5)) == 1255);
	assert(luckiest(a6, nelem(a6)) == 44);
	assert(luckiest(a7, nelem(a7)) == -1);

	return 0;
}
