/*

Write a function that recursively determines if a string is a palindrome.
Examples

isPalindrome("abcba") ➞ true

isPalindrome("b") ➞ true

isPalindrome("") ➞ true

isPalindrome("ad") ➞ false

Notes

An empty string counts as a palindrome.

*/

#include <assert.h>
#include <string.h>

int
ispalindromerec(const char *s, size_t i, size_t j)
{
	if (i >= j)
		return 1;
	if (s[i] != s[j])
		return 0;
	return ispalindromerec(s, i + 1, j - 1);
}

int
ispalindrome(const char *s)
{
	size_t n;

	n = strlen(s);
	if (n == 0)
		return 1;

	return ispalindromerec(s, 0, n - 1);
}

int
main(void)
{
	assert(ispalindrome("abcba") == 1);
	assert(ispalindrome("abbba") == 1);
	assert(ispalindrome("abbbba") == 1);
	assert(ispalindrome("abccdba") == 0);
	assert(ispalindrome("abbaa") == 0);
	assert(ispalindrome("abbbbb") == 0);
	assert(ispalindrome("ad") == 0);
	assert(ispalindrome("b") == 1);
	assert(ispalindrome("") == 1);

	return 0;
}
