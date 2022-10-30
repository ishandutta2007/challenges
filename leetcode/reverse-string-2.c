/*

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string.
If there are less than k characters left, reverse all of them.
If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

Restrictions:
    The string consists of lower English letters only.
    Length of the given string and k will in the range [1, 10000]

*/

#include <stdio.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

void
swap(char *a, char *b)
{
	char t;

	t = *a;
	*a = *b;
	*b = t;
}

void
rev(char *s, size_t n, size_t l, size_t k)
{
	size_t i;

	i = min(l + k - 1, n - 1);
	while (i > l)
		swap(&s[l++], &s[i--]);
}

char *
revstr(char *s, size_t k)
{
	size_t i, n;

	n = strlen(s);
	for (i = 0; i < n; i += 2 * k)
		rev(s, n, i, k);
	return s;
}

int
main(void)
{
	char s1[] = "abcdefg";
	char s2[] = "hello";
	printf("%s\n", revstr(s1, 2));
	printf("%s\n", revstr(s2, 5));
	printf("%s\n", revstr(s2, 5));
	printf("%s\n", revstr(s2, 43));
	printf("%s\n", revstr(s2, 1));
	printf("%s\n", revstr(s2, 2));
	return 0;
}
