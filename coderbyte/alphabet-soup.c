/*

Have the function AlphabetSoup(str) take the str string parameter being passed and return the string with the letters in alphabetical order (ie. hello becomes ehllo).
Assume numbers and punctuation symbols will not be included in the string. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int
cmp(const void *a, const void *b)
{
	int x = *(char *)a;
	int y = *(char *)b;
	return x - y;
}

char *
alphabetsoup(char *s)
{
	size_t i, j, k;

	for (i = j = k = 0;; i++) {
		if ((isspace(s[i]) || s[i] == '\0') && j != k)
			qsort(&s[j], k - j + 1, sizeof(*s), cmp);

		if (s[i] == '\0')
			break;

		if (isspace(s[i]))
			j = i;
		k = i;
	}
	return s;
}

int
main(void)
{
	char a[] = "coderbyte";
	printf("%s\n", alphabetsoup(a));

	char b[] = "hooplah";
	printf("%s\n", alphabetsoup(b));

	char c[] = "hello    \tworld";
	printf("%s\n", alphabetsoup(c));

	char d[] = "xabc\t1332 pe r";
	printf("%s\n", alphabetsoup(d));

	return 0;
}
