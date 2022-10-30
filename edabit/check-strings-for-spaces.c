/*

Create a function that returns true if a string contains any spaces.

Notes

    An empty string does not contain any spaces.
    Try doing this without RegEx.
    Don't forget to return the result.
    If you get stuck on a challenge, find help in the Resources tab.
    If you're really stuck, unlock solutions in the Solutions tab.

*/

#include <stdio.h>
#include <ctype.h>

int
hasspaces(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (isspace(s[i]))
			return 1;
	}
	return 0;
}

int
main(void)
{
	printf("%d\n", hasspaces("hello"));
	printf("%d\n", hasspaces("hello, world"));
	printf("%d\n", hasspaces(" "));
	printf("%d\n", hasspaces(""));
	printf("%d\n", hasspaces(",./!@#"));
	printf("%d\n", hasspaces("Foo"));
	printf("%d\n", hasspaces("Foo bar"));
	printf("%d\n", hasspaces("Foo "));
	printf("%d\n", hasspaces(" Foo"));
	printf("%d\n", hasspaces(",./;'[]-="));
	return 0;
}
