/*

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t
lastword(const char *s)
{
	size_t i, j, n;

	n = strlen(s);
	if (n == 0)
		return 0;

	i = n - 1;
	while (isspace(s[i]) && i > 0)
		i--;

	for (j = 0;; i--) {
		if (!isspace(s[i]))
			j++;
		else
			break;
		if (i == 0)
			break;
	}
	return j;
}

int
main(void)
{
	printf("%zu\n", lastword("Hello World"));
	printf("%zu\n", lastword("Race"));
	printf("%zu\n", lastword("Boxcar        "));
	printf("%zu\n", lastword("WASD        XASDE\t\t"));
	return 0;
}
