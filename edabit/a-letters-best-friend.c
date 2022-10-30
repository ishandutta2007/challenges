/*

Given a string, return if a given letter always appears immediately before another given letter.

Worked Example

bestFriend("he headed to the store", "h", "e") ➞ true

// All occurences of "h": ["he", "headed", "the"]
// All occurences of "h" have an "e" after it.
// Return true

Examples

bestFriend("he headed to the store", "h", "e") ➞ true

bestFriend("i found an ounce with my hound", "o", "u") ➞ true

bestFriend("we found your dynamite", "d", "y") ➞ false

Notes

    Don't count letters with spaces between them (example #3).
    All sentences will be given in lowercase.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
bff(const char *s, int a, int b)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] == a && s[i + 1] != b)
			return false;
	}
	return true;
}

int
main(void)
{
	assert(bff("he headed to the store", 'h', 'e') == true);
	assert(bff("i found an ounce with my hound", 'o', 'u') == true);
	assert(bff("those were their thorns they said", 't', 'h') == true);

	assert(bff("we found your dynamite", 'd', 'y') == false);
	assert(bff("look they took the cookies", 'o', 'o') == false);
	assert(bff("go to edabit and meditate", 'e', 'd') == false);

	return 0;
}
