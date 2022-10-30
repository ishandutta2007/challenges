/*

Balanced strings are those who have equal quantity of 'L' and 'R' characters.

Given a balanced string s split it in the maximum amount of balanced strings.

Return the maximum amount of splitted balanced strings.

Constraints:

    1 <= s.length <= 1000
    s[i] = 'L' or 'R'

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <inttypes.h>

size_t
balanced(const char *s)
{
	size_t i, n;
	ssize_t j;

	for (i = j = n = 0; s[i]; i++) {
		(s[i] == 'L') ? j++ : j--;
		n += (j == 0);
	}

	return n;
}

int
main(void)
{
	printf("%zu\n", balanced("RLRRLLRLRL"));
	printf("%zu\n", balanced("RLLLLRRRLR"));
	printf("%zu\n", balanced("LLLLRRRR"));
	return 0;
}
