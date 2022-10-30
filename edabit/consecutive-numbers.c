/*

Given an array of random digits of any length, return true if the number n appears times times in a row, and false otherwise.
Worked Example

isThereConsecutive([1, 3, 5, 5, 3, 3, 1], 3, 2) ➞ true
// Second parameter is the number to look out for (3).
// Third parameter means you need to find the number 3 twice in a row.
// Return true if it can be found.

Examples

isThereConsecutive([1, 2, 3, 4, 5], 1, 1) ➞ true

isThereConsecutive([3], 1, 0) ➞ true

isThereConsecutive([2, 2, 3, 2, 2, 2, 2, 3, 4, 1, 5], 3, 2) ➞ false

isThereConsecutive([5, 5, 5, 5, 5], 5, 7) ➞ false

Notes

    Arrays will only contain positive single digit numbers.
    Expect all parameters to be valid.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
consecutive(int *a, size_t n, int v, size_t t)
{
	size_t i, j, k;

	for (i = j = k = 0; i < n; i++) {
		if (a[i] != v) {
			k |= j;
			j = 0;
		} else if (++j == t)
			return true;
	}
	return (k == 0 && t == 0);
}

int
main(void)
{
	int a1[] = {1, 2, 3, 4, 5};
	int a2[] = {2, 2, 2, 2, 2, 2, 3, 4, 1, 5};
	int a3[] = {5, 5, 5, 5, 5};
	int a4[] = {1, 3, 5, 5, 3, 3, 1};
	int a5[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 0, 0};
	int a6[] = {0};
	int a7[] = {3};
	int a8[] = {2, 2, 3, 2, 2, 2, 2, 3, 4, 1, 5};

	assert(consecutive(a1, nelem(a1), 1, 1) == true);
	assert(consecutive(a2, nelem(a2), 3, 2) == false);
	assert(consecutive(a3, nelem(a3), 5, 7) == false);
	assert(consecutive(a4, nelem(a4), 3, 2) == true);
	assert(consecutive(a5, nelem(a5), 5, 2) == true);
	assert(consecutive(a6, nelem(a6), 1, 1) == false);
	assert(consecutive(a7, nelem(a7), 1, 0) == true);
	assert(consecutive(a8, nelem(a8), 3, 2) == false);

	return 0;
}
