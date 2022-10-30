/*

Create a function that takes an array of strings and return the number of smiley faces contained within it. These are the components that make up a valid smiley:

    A smiley has eyes. Eyes can be : or ;.
    A smiley has a nose but it doesn't have to. A nose can be - or ~.
    A smiley has a mouth which can be ) or D.

No other characters are allowed except for those mentioned above.

Notes

    You will always be given an array as input.
    An empty array should return 0.
    The order of each facial element will always be the same.
    Noses are optional (e.g. :) and :-) are both valid).

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
smileys(const char **s, size_t n)
{
	const char *p;
	unsigned m;
	size_t i, j;
	int c, t;

	m = 0;
	for (i = 0; i < n; i++) {
		p = s[i];
		t = 0;
		for (j = 0; (c = p[j] & 0xff); j++) {
			switch (t) {
			case 0:
				if (c == ':' || c == ';')
					t = 1;
				break;
			case 1:
				if (c == '-' || c == '~') {
					t = 2;
					break;
				}
				// fallthrough
			case 2:
				if (c == ')' || c == 'D')
					m++;
				t = 0;
				break;
			}
		}
	}
	return m;
}

int
main(void)
{
	const char *s1[] = {":)", ";(", ";}", ":-D"};
	printf("%u\n", smileys(s1, nelem(s1)));

	const char *s2[] = {";D", ":-(", ":-)", ";~)"};
	printf("%u\n", smileys(s2, nelem(s2)));

	const char *s3[] = {";]", ":[", ";*", ":$", ";-D"};
	printf("%u\n", smileys(s3, nelem(s3)));

	const char *s4[] = {";(", ":>", ":}", ":]"};
	printf("%u\n", smileys(s4, nelem(s4)));

	const char *s5[] = {":)", ":)", ":)", ":)", ":)", ":)", ":)", ":)", ":)", ":)", ":)", ":)", ":)"};
	printf("%u\n", smileys(s5, nelem(s5)));

	const char *s6[] = {":)", ":(", ":D", ":O", ":;"};
	printf("%u\n", smileys(s6, nelem(s6)));

	const char *s7[] = {":-)", ";~D", ":-D", ":_D"};
	printf("%u\n", smileys(s7, nelem(s7)));

	const char *s8[] = {":---)", "))", ";~~D", ";D"};
	printf("%u\n", smileys(s8, nelem(s8)));

	const char *s9[] = {";~)", ":)", ":-)", ":--)"};
	printf("%u\n", smileys(s9, nelem(s9)));

	const char *s10[] = {":o)", ":--D", ";-~)"};
	printf("%u\n", smileys(s10, nelem(s10)));

	printf("%u\n", smileys(NULL, 0));

	return 0;
}
