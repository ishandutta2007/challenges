/*

Create a function that takes a string str and modifies the given string as per the below examples:
Examples

mumbling("MubAshIr") ➞ "M-Uu-Bbb-Aaaa-Sssss-Hhhhhh-Iiiiiii-Rrrrrrrr"

mumbling("maTT") ➞ "M-Aa-Ttt-Tttt"

mumbling("EdaBit") ➞ "E-Dd-Aaa-Bbbb-Iiiii-Tttttt"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *
mumbling(const char *s, char *b)
{
	size_t i, j, k;
	char u, l;

	for (i = j = 0; s[i]; i++) {
		u = l = s[i];
		if (isalpha(s[i])) {
			u = toupper(s[i]);
			l = tolower(s[i]);
		}

		b[j++] = u;
		for (k = 0; k < i; k++)
			b[j++] = l;
		if (s[i + 1])
			b[j++] = '-';
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	mumbling(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("MubAshIr", "M-Uu-Bbb-Aaaa-Sssss-Hhhhhh-Iiiiiii-Rrrrrrrr");
	test("maTT", "M-Aa-Ttt-Tttt");
	test("airForce", "A-Ii-Rrr-Ffff-Ooooo-Rrrrrr-Ccccccc-Eeeeeeee");
	test("EdaBit", "E-Dd-Aaa-Bbbb-Iiiii-Tttttt");
	test("PaKiStAn", "P-Aa-Kkk-Iiii-Sssss-Tttttt-Aaaaaaa-Nnnnnnnn");

	return 0;
}
