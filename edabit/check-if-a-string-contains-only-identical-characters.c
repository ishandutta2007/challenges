/*

Write a function that returns true if all characters in a string are identical and false otherwise.
Examples

isIdentical("aaaaaa") ➞ true

isIdentical("aabaaa") ➞ false

isIdentical("ccccca") ➞ false

isIdentical("kk") ➞ true

Notes

N/A

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
isidentical(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] != s[i + 1] && s[i + 1] != '\0')
			return false;
	}
	return true;
}

int
main(void)
{
	assert(isidentical("aaaaaa") == true);
	assert(isidentical("aabaaa") == false);
	assert(isidentical("ccccca") == false);
	assert(isidentical("kk") == true);
	assert(isidentical("kkkkk") == true);
	assert(isidentical("ckkkk") == false);
	assert(isidentical("kkkkck") == false);
	assert(isidentical("aabc") == false);
	assert(isidentical("ccc") == true);
	assert(isidentical("aabbbb") == false);
	assert(isidentical("bbbbbb") == true);

	return 0;
}
