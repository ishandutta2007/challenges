/*

You are given a string containing characters A and B only.
Your task is to change it into a string such that there are no matching adjacent characters.
To do this, you are allowed to delete zero or more characters in the string.

Your task is to find the minimum number of required deletions.

For example, given the string s=AABAAB
remove an A at positions 0 and 3 to make s=ABAB in 2 deletions.

*/

#include <stdio.h>

size_t
deletes(const char *s)
{
	size_t i, n;

	if (s[0] == '\0')
		return 0;

	n = 0;
	for (i = 1; s[i]; i++) {
		if (s[i] == s[i - 1])
			n++;
	}
	return n;
}

int
main(void)
{
	printf("%zu\n", deletes("AABAAB"));
	printf("%zu\n", deletes("AAAA"));
	printf("%zu\n", deletes("BBBBB"));
	printf("%zu\n", deletes("ABABABAB"));
	printf("%zu\n", deletes("BABABA"));
	printf("%zu\n", deletes("AAABBB"));
	printf("%zu\n", deletes(""));
	return 0;
}
