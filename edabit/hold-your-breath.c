/*

You will be given an array of numbers which represent your character's altitude above sea level at regular intervals:

    Positive numbers represent height above the water.
    0 is sea level.
    Negative numbers represent depth below the water's surface.

Create a function which returns whether your character survives their unsupervised diving experience, given an array of integers.

    Your character starts with a maximum breath meter of 10, and you can replenish your breath by 4 for every item in the array which you are at or above sealevel.

    However, when diving underwater, your breath meter decreases by 2 per item in the array. Watch out, if your breath diminishes to 0, your character dies!

Worked Example

divingMinigame([-5, -15, -4, 0, 5]) ➞ true

// Breath meter starts at 10.
// -5 is below water, so breath meter decreases to 8.
// -15 is below water, so breath meter decreases to 6.
// -4 is below water, so breath meter decreases to 4.
// 0 is at sea level, so breath meter increases to 8.
// 5 is above sea level and breath meter is capped at 10 (would've been 12 otherwise).
// Character survives!

Examples

divingMinigame([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]) ➞ true

divingMinigame([-3, -6, -2, -6, -2]) ➞ false

divingMinigame([2, 1, 2, 1, -3, -4, -5, -3, -4]) ➞ false

Notes

    Lists may be of any length.
    All arrays are valid.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
survive(int *a, size_t n)
{
	size_t i;
	int v;

	v = 10;
	for (i = 0; i < n; i++) {
		v += (a[i] >= 0) ? 4 : -2;
		v = (v < 10) ? v : 10;
		if (v <= 0)
			return false;
	}
	return true;
}

int
main(void)
{
	int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int a2[] = {-5, -15, -4, 0, 5};
	int a3[] = {0, -4, 0, -4, -5, -2};
	int a4[] = {-4, -3, -4, -3, 5, 2, -5, -20, -42, -4, 5, 3, 5};
	int a5[] = {-3, -6, -2, -6, -2};
	int a6[] = {-4, -5, -2, -7, 2, -1000, -2000, -1};
	int a7[] = {1, 2, 1, 2, 1, 2, 1, 2, 1, -3, -4, -5, -3, -4};
	int a8[] = {-5, -5, -5, -5, -5, 2, 2, 2, 2, 2, 2, 2, 2};

	assert(survive(a1, nelem(a1)) == true);
	assert(survive(a2, nelem(a2)) == true);
	assert(survive(a3, nelem(a3)) == true);
	assert(survive(a4, nelem(a4)) == true);
	assert(survive(a5, nelem(a5)) == false);
	assert(survive(a6, nelem(a6)) == false);
	assert(survive(a7, nelem(a7)) == false);
	assert(survive(a8, nelem(a8)) == false);

	return 0;
}
