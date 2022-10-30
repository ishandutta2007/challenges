/*

A string is an almost-palindrome if, by changing only one character, you can make it a palindrome.
Create a function that returns true if a string is an almost-palindrome and false otherwise.

Examples

almostPalindrome("abcdcbg") ➞ true
// Transformed to "abcdcba" by changing "g" to "a".

almostPalindrome("abccia") ➞ true
// Transformed to "abccba" by changing "i" to "b".

almostPalindrome("abcdaaa") ➞ false
// Can't be transformed to a palindrome in exactly 1 turn.

almostPalindrome("1234312") ➞ false

Notes

Return false if the string is already a palindrome.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
almostpalindrome(const char *s)
{
	size_t c, i, n;

	n = strlen(s);
	for (i = c = 0; i < n / 2 && c < 2; i++) {
		if (s[i] != s[n - i - 1])
			c++;
	}
	return c == 1;
}

int
main(void)
{
	assert(almostpalindrome("abcdcbg") == true);
	assert(almostpalindrome("abccia") == true);
	assert(almostpalindrome("abcdaaa") == false);
	assert(almostpalindrome("gggfgig") == true);
	assert(almostpalindrome("gggffff") == false);
	assert(almostpalindrome("GIGGG") == true);
	assert(almostpalindrome("ggggi") == true);
	assert(almostpalindrome("ggggg") == false);
	assert(almostpalindrome("gggfggg") == false);
	assert(almostpalindrome("1234312") == false);
	assert(almostpalindrome("") == false);

	return 0;
}
