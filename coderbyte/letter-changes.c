/*
 
Have the function LetterChanges(str) take the str parameter being passed and modify it using the following algorithm.
Replace every letter in the string with the letter following it in the alphabet (ie. c becomes d, z becomes a).
Then capitalize every vowel in this new string (a, e, i, o, u) and finally return this modified string. 

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
charchange(int c)
{
	if ('a' <= c && c <= 'z')
		c = 'a' + ((c - 'a' + 1) % 26);
	else if ('A' <= c && c <= 'Z')
		c = 'A' + ((c - 'A' + 1) % 26);
	if (strchr("aeiou", c))
		c = toupper(c);
	return c;
}

char *
letterchanges(char *s)
{
	size_t i;

	for (i = 0; s[i]; i++)
		s[i] = charchange(s[i]);
	return s;
}

int
main(void)
{
	char a[] = "hello*3";
	printf("%s\n", letterchanges(a));

	char b[] = "fun times!";
	printf("%s\n", letterchanges(b));

	char c[] = "zztak";
	printf("%s\n", letterchanges(c));

	return 0;
}
