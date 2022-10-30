/*

There's a great war between the even and odd numbers. Many numbers already lost their life in this war and it's your task to end this. You have to determine which group is larger: the even, or the odd. The larger group wins.

Create a function that takes an array of integers and sum up the even and odd numbers seperatly and then substract the smaller one from the bigger one. Return the substraction.
Examples

warOfNumbers([2, 8, 7, 5]) ➞ 2
// 2 + 8 = 10
// 7 + 5 = 12
// 12 - 10

warOfNumbers([12, 90, 75]) ➞ 27

warOfNumbers([5, 9, 45, 6, 2, 7, 34, 8, 6, 90, 5, 243]) ➞ 168

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
war(int *a, size_t n)
{
	size_t i;
	int x;

	x = 0;
	for (i = 0; i < n; i++) {
		if (a[i] & 1)
			x += a[i];
		else
			x -= a[i];
	}
	return abs(x);
}

int
main(void)
{
	int a1[] = { 2, 8, 7, 5 };
	int a2[] = { 12, 90, 75 };
	int a3[] = { 5, 9, 45, 6, 2, 7, 34, 8, 6, 90, 5, 243 };
	int a4[] = { 654, 7, 23, 3, 78, 4, 56, 34 };
	int a5[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a6[] = { 97, 83, 209, 141, 134, 298, 110, 207, 229, 275, 115, 64, 244, 278 };
	int a7[] = { 332, 92, 35, 315, 109, 168, 320, 230, 63, 323, 16, 204, 105, 17, 226, 157, 245, 44, 223, 136, 93 };
	int a8[] = { 322, 89, 36, 310, 297, 157, 251, 55, 264, 244, 200, 304, 25, 308, 311, 269, 303, 257, 6, 311, 307, 310, 50, 46, 54, 237, 59, 105, 267 };
	int a9[] = { 50, 100, 149, 1, 200, 199, 3, 2 };

	assert(war(a1, nelem(a1)) == 2);
	assert(war(a2, nelem(a2)) == 27);
	assert(war(a3, nelem(a3)) == 168);
	assert(war(a4, nelem(a4)) == 793);
	assert(war(a5, nelem(a5)) == 5);
	assert(war(a6, nelem(a6)) == 228);
	assert(war(a7, nelem(a7)) == 83);
	assert(war(a8, nelem(a8)) == 846);
	assert(war(a9, nelem(a9)) == 0);

	return 0;
}
