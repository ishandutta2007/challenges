/*

Write a regular expression that matches numbers whose digits are not repeated (i.e. digits are distinct).

Examples

regularExpression.test("123") ➞ true

regularExpression.test("112233") ➞ false

regularExpression.test("1025") ➞ true

Notes

Input is a number as a string.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
distinct(const char *s)
{
	size_t i, j;

	for (i = 0; s[i]; i = j) {
		j = i + 1;
		while (s[i] == s[j])
			j++;

		if (i + 1 != j)
			return false;
	}
	return true;
}

int
main(void)
{
	assert(distinct("123") == true);
	assert(distinct("112233") == false);
	assert(distinct("1025") == true);
	assert(distinct("11") == false);
	assert(distinct("108") == true);
	assert(distinct("2314412221234") == false);
	assert(distinct("725") == true);

	return 0;
}
