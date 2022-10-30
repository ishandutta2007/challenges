/*

Given two strings comprised of + and -, return a new string which shows how the two strings interact in the following way:

    When positives and positives interact, they remain positive.
    When negatives and negatives interact, they remain negative.
    But when negatives and positives interact, they become neutral, and are shown as the number 0.

Worked Example

neutralise("+-+", "+--") ➞ "+-0"
# Compare the first characters of each string, then the next in turn.
# "+" against a "+" returns another "+".
# "-" against a "-" returns another "-".
# "+" against a "-" returns "0".
# Return the string of characters.

Examples

neutralise("--++--", "++--++") ➞ "000000"

neutralise("-+-+-+", "-+-+-+") ➞ "-+-+-+"

neutralise("-++-", "-+-+") ➞ "-+00"

Notes

The two strings will be the same length.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
neutralise(const char *s, const char *t, char *b)
{
	size_t i;

	for (i = 0; s[i] && t[i]; i++)
		b[i] = (s[i] == t[i]) ? s[i] : '0';
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *t)
{
	assert(!strcmp(s, t));
}

int
main(void)
{
	char b[80];

	test(neutralise("--++--", "++--++", b), "000000");
	test(neutralise("-+-+-+", "-+-+-+", b), "-+-+-+");
	test(neutralise("-++-", "-+-+", b), "-+00");
	test(neutralise("--++", "++++", b), "00++");
	test(neutralise("+++--+---", "++----++-", b), "++0--000-");
	test(neutralise("-----", "-----", b), "-----");
	test(neutralise("-+", "++", b), "0+");
	test(neutralise("--", "-+", b), "-0");
	test(neutralise("-++", "+--", b), "000");
	test(neutralise("++-++--++-", "-+++-++-++", b), "0+0+0000+0");
	test(neutralise("-++-+-++-", "+-++++---", b), "00+0+000-");
	test(neutralise("---++-+--", "-+++--++-", b), "-00+0-+0-");
	test(neutralise("+-----+++-", "--+-+-++--", b), "0-0-0-++0-");
	test(neutralise("+-----+-", "---++-++", b), "0--00-+0");
	test(neutralise("-+--+-+---", "-+--+-+-+-", b), "-+--+-+-0-");
	test(neutralise("+-+", "-++", b), "00+");
	test(neutralise("-++", "-+-", b), "-+0");
	test(neutralise("---+", "-+++", b), "-00+");
	test(neutralise("+--", "+--", b), "+--");
	test(neutralise("--+++-+-", "+++++---", b), "00+++-0-");

	return 0;
}
