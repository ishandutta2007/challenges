/*

A pair of strings form a strange pair if both of the following are true:

    The 1st string's first letter = 2nd string's last letter.
    The 1st string's last letter = 2nd string's first letter.

Create a function that returns true if a pair of strings constitutes a strange pair, and false otherwise.

Examples

IsStrangePair("ratio", "orator") ➞ true
// "ratio" ends with "o" and "orator" starts with "o".
// "ratio" starts with "r" and "orator" ends with "r".

IsStrangePair("sparkling", "groups") ➞ true

IsStrangePair("bush", "hubris") ➞ false

IsStrangePair("", "") ➞ true

Notes

It should work on a pair of empty strings (they trivially share nothing).

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

bool
strangepair(const char *s, const char *t)
{
	size_t n, m;

	n = strlen(s);
	m = strlen(t);
	n = max(n, 1);
	m = max(m, 1);
	return s[0] == t[m - 1] && t[0] == s[n - 1];
}

int
main(void)
{
	assert(strangepair("ratio", "orator") == true);
	assert(strangepair("sparkling", "groups") == true);
	assert(strangepair("mentee", "eminem") == true);
	assert(strangepair("yahtzee", "easy") == true);
	assert(strangepair("bush", "hubris") == false);
	assert(strangepair("edit", "cheese") == false);
	assert(strangepair("false", "true") == false);
	assert(strangepair("cupid", "dionysus") == false);
	assert(strangepair("futile", "elephant") == false);
	assert(strangepair("", "") == true);
	assert(strangepair("", "abc") == false);
	assert(strangepair("a", "a") == true);
	assert(strangepair("a", "b") == false);
	assert(strangepair("&!", "!&") == true);
	assert(strangepair("5556", "65") == true);

	return 0;
}
