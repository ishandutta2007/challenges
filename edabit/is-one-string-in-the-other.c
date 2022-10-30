/*

Create a function that takes two strings and returns true if either of the strings appears at the very end of the other string.
Return false otherwise. The character * is a wildcard, so it can take the place of any character.

Examples

Overlap("ABC", "Ican'tsingmyABC") ➞ true

Overlap("abc", "Ican'tsingmyABC") ➞ true

Overlap("Ican'tsingmyABC", "abc") ➞ true

Overlap("hello world", "hello") ➞ false

Overlap("+=", "this should work too +=") ➞ true

Overlap("hey", "*********") ➞ true

Notes

Your function should NOT be case sensitive (see example #2).

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool
overlap(const char *s, const char *t)
{
	size_t n, m;
	char a, b;

	n = strlen(s);
	m = strlen(t);
	while (n && m) {
		a = tolower(s[--n]);
		b = tolower(t[--m]);
		if (a != b && a != '*' && b != '*')
			return false;
	}
	return true;
}

int
main(void)
{
	assert(overlap("ABC", "Ican'tsingmyABC") == true);
	assert(overlap("abc", "Ican'tsingmyABC") == true);
	assert(overlap("Ican'tsingmyABC", "abc") == true);
	assert(overlap("*bc", "Ican'tsingmyABC") == true);
	assert(overlap("abc", "Ican'tsingmy***") == true);
	assert(overlap("ab", "Ican'tsingmy**c") == false);
	assert(overlap("hello world", "hello") == false);
	assert(overlap("+=", "this should work too +=") == true);
	assert(overlap("don't forget hyphens-", "-") == true);
	assert(overlap("don't forget periods ", ".") == false);
	assert(overlap("this will always be true", "*") == true);
	assert(overlap("this will always be false", "F") == false);
	assert(overlap("hey", "*********") == true);
	assert(overlap("a*c", "*b*") == true);
	assert(overlap("last test", "congrats you passed the last test") == true);

	return 0;
}
