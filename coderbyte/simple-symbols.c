/*

Have the function SimpleSymbols(str) take the str parameter being passed and determine if it is an acceptable sequence by either returning the string true or false.
The str parameter will be composed of + and = symbols with several letters between them (ie. ++d+===+c++==a) and for the string to be true each letter must be surrounded by a + symbol.
So the string to the left would be false. The string will not be empty and will have at least one letter. 

*/
#include <stdio.h>
#include <ctype.h>

const char *
simplesymbols(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (isalpha(s[i])) {
			if (i == 0 || (s[i - 1] != '+' || s[i + 1] != '+'))
				return "false";
		}
	}
	return "true";
}

int
main(void)
{
	printf("%s\n", simplesymbols("++d+===+c++==a"));
	printf("%s\n", simplesymbols("+d+=3=+s+"));
	printf("%s\n", simplesymbols("f++d+"));
	return 0;
}
