// Implement function ToLowerCase() that has a string parameter str,
// and returns the same string in lowercase.

#include <stdio.h>
#include <ctype.h>

char *
strlower(char *s)
{
	size_t i;

	for (i = 0; s[i]; i++)
		s[i] = tolower(s[i]);
	return s;
}

int
main(void)
{
	char s1[] = "Hello";
	char s2[] = "here";
	char s3[] = "LOVELY";

	printf("%s\n", strlower(s1));
	printf("%s\n", strlower(s2));
	printf("%s\n", strlower(s3));
	return 0;
}
