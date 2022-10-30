/*

Create a function that takes two strings and returns either true or false depending on whether they're anagrams or not.

Notes

Should be case insensitive.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
isanagram(const char *s, const char *t)
{
	size_t i, h[2][256];

	memset(h, 0, sizeof(h));
	for (i = 0; s[i] && t[i]; i++) {
		h[0][tolower(s[i]) & 0xff]++;
		h[1][tolower(t[i]) & 0xff]++;
	}
	if (s[i] != '\0' || t[i] != '\0')
		return 0;
	return memcmp(h[0], h[1], sizeof(h[1])) == 0;
}

int
main(void)
{
	printf("%d\n", isanagram("cristian", "Cristina"));
	printf("%d\n", isanagram("Dave Barry", "Ray Adverb"));
	printf("%d\n", isanagram("Nope", "Note"));
	printf("%d\n", isanagram("Apple", "Appeal"));
	return 0;
}
