/*

Write a function that returns true if every consecutive sequence of ones is followed by a consecutive sequence of zeroes of the same length.

*/

#include <stdio.h>

int
samelength(const char *s)
{
	size_t i, o, z;

	for (i = 0; s[i];) {
		if (s[i] != '1') {
			i++;
			continue;
		}

		for (o = 0; s[i] == '1'; i++)
			o++;

		for (z = 0; s[i] == '0'; i++)
			z++;

		if (o != z)
			return 0;
	}
	return 1;
}

int
main(void)
{
	printf("%d\n", samelength("10"));
	printf("%d\n", samelength("1010"));
	printf("%d\n", samelength("1100"));
	printf("%d\n", samelength("10101110001100"));
	printf("%d\n", samelength("1111000010101100"));
	printf("%d\n", samelength("1001"));
	printf("%d\n", samelength("101001"));
	printf("%d\n", samelength("101"));
	printf("%d\n", samelength("10010"));
	printf("%d\n", samelength("110"));
	printf("%d\n", samelength("11001"));
	printf("%d\n", samelength("11100011000"));
	return 0;
}
