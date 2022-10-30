/*

Create a function that takes an array of booleans that represent whether or not a player has logged into a game that day.
Output the longest streak of consecutive logged in days.

Examples

dailyStreak([true, true, false, true]) ➞ 2

dailyStreak([false, false, false]) ➞ 0

dailyStreak([true, true, true, false, true, true]) ➞ 3

Notes

    Return your output as an integer.
    If a given array is all false, return 0 (see example #2).

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

size_t
streak(bool *a, size_t n)
{
	size_t i, j, r;

	r = 0;
	for (i = 0; i < n; i = j) {
		for (j = i + 1; j < n; j++) {
			if (a[i] != a[j])
				break;
		}
		if (a[i])
			r = max(r, j - i);
	}
	return r;
}

int
main(void)
{
	bool a1[] = {true, true, false, true};
	bool a2[] = {false, false, false};
	bool a3[] = {true, true, true, false};
	bool a4[] = {true, true, true, false, true, true};
	bool a5[] = {true, false};
	bool a6[] = {true, false, true};
	bool a7[] = {true, false, true};
	bool a8[] = {true, false, true, true};

	assert(streak(a1, nelem(a1)) == 2);
	assert(streak(a2, nelem(a2)) == 0);
	assert(streak(a3, nelem(a3)) == 3);
	assert(streak(a4, nelem(a4)) == 3);
	assert(streak(a5, nelem(a5)) == 1);
	assert(streak(a6, nelem(a6)) == 1);
	assert(streak(a7, nelem(a7)) == 1);
	assert(streak(a8, nelem(a8)) == 2);

	return 0;
}
