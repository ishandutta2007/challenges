/*

Read two strings from stdin.
Output Yes if one string is a rotated version of the other.
Otherwise output No

Testcases

Input

CodeGolf GolfCode

Output

Yes

Input

stackexchange changestackex

Output

Yes

Input

stackexchange changestack

Output

No

Input

Hello World

Output

No

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
rotated(const char *s, const char *t)
{
	size_t i, j, n, m;

	n = strlen(s);
	m = strlen(t);
	if (n != m)
		return false;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (s[j] != t[(i + j) % n])
				break;
		}
		if (j == n)
			return true;
	}
	return false;
}

int
main(void)
{
	assert(rotated("CodeGolf", "GolfCode") == true);
	assert(rotated("stackexchange", "changestackex") == true);
	assert(rotated("stackexchange", "changestack") == false);
	assert(rotated("Hello", "World") == false);
	assert(rotated("shifted", "ftedshi") == true);

	return 0;
}
