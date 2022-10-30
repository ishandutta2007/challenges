/*

Write a function that changes every letter to the next letter:

"a" becomes "b"
"b" becomes "c"
"d" becomes "e"
and so on ...

*/

#include <stdio.h>

int
next(int c)
{
	if ('a' <= c && c <= 'z')
		return 'a' + (c - 'a' + 1) % 26;
	if ('A' <= c && c <= 'Z')
		return 'A' + (c - 'A' + 1) % 26;
	return c;
}

char *
move(char *s)
{
	size_t i;

	for (i = 0; s[i]; i++)
		s[i] = next(s[i]);
	return s;
}

int
main(void)
{
	char s1[] = "hello";
	char s2[] = "bye";
	char s3[] = "welcome";
	char s4[] = "lol";
	char s5[] = "zZAa";

	printf("%s\n", move(s1));
	printf("%s\n", move(s2));
	printf("%s\n", move(s3));
	printf("%s\n", move(s4));
	printf("%s\n", move(s5));
	return 0;
}
