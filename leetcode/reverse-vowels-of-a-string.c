/*

Write a function that takes a string as input and reverse only the vowels of a string.

Note:
The vowels does not include the letter "y".

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
isvowel(int c)
{
	return strchr("aeiou", tolower(c)) != NULL;
}

char *
revvow(char *s, size_t n)
{
	size_t i, j;
	char c;

	if (n == 0)
		return s;

	i = 0;
	j = n - 1;
	while (i < j) {
		if (!isvowel(s[i]))
			i++;
		else if (!isvowel(s[j]))
			j--;
		else {
			c = s[i];
			s[i] = s[j];
			s[j] = c;
			i++;
			j--;
		}
	}
	return s;
}

int
main(void)
{
	char a[] = "hello";
	printf("%s\n", revvow(a, nelem(a) - 1));

	char b[] = "leetcode";
	printf("%s\n", revvow(b, nelem(b) - 1));

	char c[] = "abebbbbb";
	printf("%s\n", revvow(c, nelem(c) - 1));

	return 0;
}
