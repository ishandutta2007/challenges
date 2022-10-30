/*

Create a function that takes two arguments: a father's current age f_age and his son's current age s_age.
Сalculate how many years ago the father was twice as old as his son, or in how many years he will be twice as old.

Examples

age_difference(36, 7) ➞ 22
# 22 years from now, the father will be 58 years old and his son will be 29 years old.

age_difference(55, 30) ➞ 5
# 5 years ago, the father was 50 years old and his son was 25 years old.

age_difference(42, 21) ➞ 0

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int
agediff(int f, int s)
{
	return abs(f - s * 2);
}

int
main(void)
{
	assert(agediff(36, 7) == 22);
	assert(agediff(55, 30) == 5);
	assert(agediff(42, 21) == 0);
	assert(agediff(22, 1) == 20);
	assert(agediff(29, 0) == 29);

	return 0;
}
