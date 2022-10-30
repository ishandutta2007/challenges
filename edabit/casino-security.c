/*

You're head of security at a casino that has money being stolen from it. You get the data in the form of strings and you have to set off an alarm if a thief is detected.

    If there is no guard between thief and money, return "ALARM!"
    If the money is protected, return "Safe"

String Components

    x - Empty Space
    T - Thief
    G - Guard
    $ - Money

Examples

security("xxxxTTxGxx$xxTxxx") ➞ "ALARM!"

security("xxTxxG$xxxx$xxxx") ➞ "Safe"

security("TTxxxx$xxGxx$Gxxx") ➞ "ALARM!"

Notes

Money at the extremes are safe.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
proc(const char *s, size_t i, int f)
{
	switch (s[i]) {
	case 'T':
		f |= 0x1;
		break;
	case 'G':
		f &= ~0x1;
		break;
	case '$':
		f |= ((f & 0x1) << 1);
		break;
	}
	return f;
}

const char *
security(const char *s)
{
	size_t i, l;
	int f, g;

	f = g = 0;
	l = strlen(s);
	for (i = 0; i < l; i++) {
		f = proc(s, i, f);
		g = proc(s, l - i - 1, g);
		if ((f | g) & 0x2)
			return "ALARM!";
	}
	return "Safe";
}

void
test(const char *s, const char *r)
{
	assert(!strcmp(security(s), r));
}

int
main(void)
{
	test("xxTxxx$xxxTxxxGxxT", "ALARM!");
	test("xGxx$xxGxxxTTT", "Safe");
	test("TxGxx$xxx$xxxGxxT", "Safe");
	test("GxxxTxxGxxTxx$xx$xxTxxG", "ALARM!");
	test("xxGTxx$xx$xxxxxxG", "ALARM!");
	test("xxTxxxxxxxx$xGxxxxxxT", "ALARM!");
	test("xx$xxGxxxx$xxxxxxxxxxT", "ALARM!");
	test("xxxTxxxxT", "Safe");
	test("xxGxxxGGG", "Safe");
	test("x$xx$x$x$xx", "Safe");

	return 0;
}
