/*

This is a reverse coding challenge. Normally you're given explicit directions with how to create a function.
Here, you must generate your own function to satisfy the relationship between the inputs and outputs.

Your task is to create a function that, when fed the inputs below, produce the sample outputs shown.

*/

#include <stdio.h>
#include <ctype.h>

char *
gen(const char *s, char *b, size_t n)
{
	size_t i, j, k, l;
	char c;

	if (n == 0)
		return b;

	l = 0;
	for (i = 0; (c = s[i]); i++) {
		k = 1;
		if (isdigit(s[i + 1]))
			k = s[++i] - '0';

		for (j = 0; j < k && l < n; j++)
			b[l++] = c;
	}

	if (l > 0 && l + 1 >= n)
		l--;
	b[l] = '\0';
	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", gen("A4B5C2", b, sizeof(b)));
	printf("%s\n", gen("C2F1E5", b, sizeof(b)));
	printf("%s\n", gen("T4S2V2", b, sizeof(b)));
	printf("%s\n", gen("A1B2C3D4", b, sizeof(b)));
	printf("%s\n", gen("ABCDEF", b, sizeof(b)));
	printf("%s\n", gen("ABCDEF", b, 1));
	printf("%s\n", gen("", b, 1));
	printf("%s\n", gen("ABC", b, 2));
	return 0;
}
