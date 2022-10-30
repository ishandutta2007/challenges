/*

A palindrome is a word that is identical forward and backwards.

    mom
    racecar
    kayak

Given a word, create a function that checks whether it is a palindrome.
Examples

checkPalindrome("mom") ➞ true

checkPalindrome("scary") ➞ false

checkPalindrome("reviver") ➞ true

checkPalindrome("stressed") ➞ false

Notes

All test input is lower cased.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
ispalindrome(const char *s)
{
	size_t i, l;

	l = strlen(s);
	for (i = 0; i < l / 2; i++) {
		if (s[i] != s[l - i - 1])
			return false;
	}
	return true;
}

int
main(void)
{
	assert(ispalindrome("mom") == true);
	assert(ispalindrome("scary") == false);
	assert(ispalindrome("reviver") == true);
	assert(ispalindrome("stressed") == false);
	assert(ispalindrome("good") == false);
	assert(ispalindrome("refer") == true);
	assert(ispalindrome("something") == false);
	assert(ispalindrome("redder") == true);
	assert(ispalindrome("civic") == true);
	assert(ispalindrome("racecar") == true);
	assert(ispalindrome("kayak") == true);

	return 0;
}
