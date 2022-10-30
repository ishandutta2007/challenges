/*

You are given a string. Your task is to determine whether number of occurrences of some character in the string is equal to
the sum of the numbers of occurrences of other characters in the string. 

*/
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
check(const char *s)
{
	size_t c[256], i, j;

	memset(c, 0, sizeof(c));
	for (i = 0; s[i]; i++)
		c[s[i] & 0xff]++;

	if (i & 1)
		return "NO";

	for (j = 0; j < nelem(c); j++) {
		if (c[j] == i / 2)
			return "YES";
	}
	return "NO";
}

int
main(void)
{
	printf("%s\n", check("acab"));
	printf("%s\n", check("zzqzqq"));
	printf("%s\n", check("abc"));
	printf("%s\n", check("kklkwwww"));
	printf("%s\n", check("x"));
	printf("%s\n", check("xy"));
	printf("%s\n", check(""));
	return 0;
}
