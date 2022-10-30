/*

You are given three inputs: a string, one letter, and a second letter.

Write a function that returns True if every instance of the first letter occurs before every instance of the second letter.

Notes

All strings will be in lower case.
All strings will contain the first and second letters at least once.

*/

#include <stdio.h>

const char *
fbs(const char *s, char a, char b)
{
	size_t i, j, c[2];

	c[0] = c[1] = 0;
	for (i = j = 0; s[i]; i++) {
		if (s[i] == b)
			j = 1;

		if (s[i] == a)
			c[j]++;
	}
	return (c[0] > 0 && c[1] == 0) ? "True" : "False";
}

int
main(void)
{
	printf("%s\n", fbs("precarious kangaroos", 'a', 'j'));
	printf("%s\n", fbs("knaves knew about waterfalls", 'k', 'w'));
	printf("%s\n", fbs("maria makes money", 'm', 'o'));
	printf("%s\n", fbs("the hostess made pecan pie", 'h', 'p'));
	printf("%s\n", fbs("barry the butterfly flew away", 'b', 'f'));
	printf("%s\n", fbs("moody muggles", 'm', 'g'));

	printf("%s\n", fbs("happy birthday", 'a', 'y'));
	printf("%s\n", fbs("precarious kangaroos", 'k', 'a'));
	printf("%s\n", fbs("maria makes money", 'm', 'i'));
	printf("%s\n", fbs("taken by the beautiful sunrise", 'u', 's'));
	printf("%s\n", fbs("sharp cheddar biscuit", 't', 's'));
	printf("%s\n", fbs("moody muggles", 'm', 'o'));

	return 0;
}
