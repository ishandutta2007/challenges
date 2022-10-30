/*

The Christian holiday of Easter Sunday is a movable feast. It can occur on any date from March 22 to April 25.
The date depends on the timing between the Paschal Full Moon and the spring equinox.
It wasn't until the late 19th century that a formula was developed to accurately predict Easter's date for a given year.

Your task is to use this formula, also known as Butcher's Algorithm, to write a function that will return the date of Easter for any year after 1600.
See the Resources tab for a detailed description of the algorithm.

Examples

easterDate(1600) ➞ "April 2"

easterDate(2020) ➞ "April 12"

easterDate(1853) ➞ "March 27"

easterDate(3535) ➞ "April 14"

Notes

Before 1600 the Julian calendar was used in most countries. The algorithm we're using is based on the Gregorian calendar, which is still in use today.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

// http://www.oremus.org/liturgy/etc/ktf/app/easter.html
char *
easter(int y, char *b, size_t n)
{
	int d, e, g, s, l, p;

	g = mod(y, 19) + 1;
	s = ((y - 1600) / 100) - ((y - 1600) / 400);
	l = (((y - 1400) / 100) * 8) / 25;
	p = mod(3 - 11 * g + s - l, 30);
	if (p == 29 || (p == 28 && g > 11))
		p--;
	d = mod(y + y / 4 - y / 100 + y / 400, 7);
	e = p + 1 + mod(4 - d - p, 7);
	if (e < 11) {
		e += 21;
		snprintf(b, n, "March %d", e);
	} else {
		e -= 10;
		snprintf(b, n, "April %d", e);
	}
	return b;
}

void
test(int y, const char *r)
{
	char b[128];

	easter(y, b, sizeof(b));
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(1600, "April 2");
	test(1715, "April 21");
	test(1758, "March 26");
	test(1853, "March 27");
	test(1872, "March 31");
	test(1899, "April 2");
	test(1900, "April 15");
	test(1944, "April 9");
	test(1989, "March 26");
	test(2000, "April 23");
	test(2070, "March 30");
	test(2099, "April 12");
	test(3535, "April 14");
	test(6009, "April 12");
	test(9999, "March 28");

	return 0;
}
