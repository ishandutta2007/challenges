/*

Create a function that takes a string as an argument and returns true if each letter in the string is surrounded by a plus sign. Return false otherwise.

Notes

For clarity, each letter must have a plus sign on both sides.

*/

#include <stdio.h>
#include <ctype.h>

int
plussign(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (!isalpha(s[i]))
			continue;
		if (i == 0 || s[i - 1] != '+' || s[i + 1] != '+')
			return 0;
	}
	return 1;
}

int
main(void)
{
	printf("%d\n", plussign("+f+d+c+#+f+"));
	printf("%d\n", plussign("+d+=3=+s+"));
	printf("%d\n", plussign("+d+k+##f+"));
	printf("%d\n", plussign("hf+d++#+f+"));
	printf("%d\n", plussign("+d+i+#+c+"));
	printf("%d\n", plussign("a+"));
	printf("%d\n", plussign("f++d+g+8+"));
	printf("%d\n", plussign("+s+7+fg+r+8+"));
	return 0;
}
