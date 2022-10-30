/*

Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

*/

#include <stdio.h>
#include <ctype.h>

size_t
segments(const char *s)
{
	size_t i, c, l;

	c = 0;
	l = 0;
	for (i = 0; s[i]; i++) {
		if (isspace(s[i])) {
			l += !!c;
			c = 0;
		} else
			c++;
	}
	l += !!c;

	return l;
}

int
main(void)
{
	printf("%zu\n", segments("Hello, my name is John"));
	printf("%zu\n", segments("TXA   \t\t\t\t"));
	printf("%zu\n", segments("||>>    \t  \t\t\\t\t\t\t\t\tg"));
	return 0;
}
