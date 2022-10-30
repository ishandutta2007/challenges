/*

Given a string s consisting from digits and #, translate s to English lowercase characters as follows:

    Characters ("a" to "i") are represented by ("1" to "9").
    Characters ("j" to "z") are represented by ("10#" to "26#").

Examples

decrypt("10#11#12") ➞ "jkab"

decrypt("1326#") ➞ "acz"

decrypt("25#") ➞ "y"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
di(int x, int y)
{
	return 'a' + 10 * (x - '0') + (y - '1');
}

char *
decrypt(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (isdigit(s[i]) && isdigit(s[i + 1]) && s[i + 2] == '#') {
			b[j++] = di(s[i], s[i + 1]);
			i += 2;
		} else if (isdigit(s[i]))
			b[j++] = di('0', s[i]);
		else
			b[j++] = '?';
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	decrypt(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("10#11#12", "jkab");
	test("1326#", "acz");
	test("25#", "y");
	test("12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#", "abcdefghijklmnopqrstuvwxyz");

	return 0;
}
