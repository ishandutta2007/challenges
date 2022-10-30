/*

Create a function that takes a string as an argument and returns a coded (h4ck3r 5p34k) version of the string.

Notes

In order to work properly, the function should replace all 'a's with 4, 'e's with 3, 'i's with 1, 'o's with 0, and 's's with 5.

*/

#include <stdio.h>

char *
hackerspeak(char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case 'a':
			s[i] = '4';
			break;
		case 'e':
			s[i] = '3';
			break;
		case 'i':
			s[i] = '1';
			break;
		case 'o':
			s[i] = '0';
			break;
		case 's':
			s[i] = '5';
			break;
		}
	}
	return s;
}

int
main(void)
{
	char a[] = "javascript is cool";
	printf("%s\n", hackerspeak(a));

	char b[] = "programming is fun";
	printf("%s\n", hackerspeak(b));

	char c[] = "become a coder";
	printf("%s\n", hackerspeak(c));

	return 0;
}
