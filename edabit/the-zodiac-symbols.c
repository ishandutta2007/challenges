/*

In Western astrology, there are twelve possible date intervals for establishing the zodiac sign of a person, with each sign having its own symbol.
Sign	Symbol	Interval
Aries	♈	March 21 – April 20
Taurus	♉	April 21 – May 21
Gemini	♊	May 22 – June 21
Cancer	♋	June 22 – July 22
Leo	♌	July 23 – August 22
Virgo	♍	August 23 – September 23
Libra	♎	September 24 – October 23
Scorpio	♏	October 24 – November 22
Sagittarius	♐	November 23 – December 21
Capricorn	♑	December 22 – January 20
Aquarius	♒	January 21 – February 19
Pisces	♓	February 20 – March 20

Given a string dob being a date of birth in the U.S. full format, implement a function that returns the related zodiac symbol accordingly to the table above.
Examples

zodiacSymbol("May 9, 1951") ➞ "♉"
// Taurus

zodiacSymbol("October 31, 1977") ➞ "♏"
// Scorpio

zodiacSymbol("January 19, 1985") ➞ "♑"
// Capricorn

Notes

    A list of the Unicode characters to return is already given in the Code tab.
    In each date interval listed into the table, the starting date and the end date are the inclusive bounds of the range to consider.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
zodiac(const char *s)
{
	static const struct {
		const char *sym;
		int start[2];
		int end[2];
	} tab[] = {
		{ u8"♈", { 3, 21 }, { 4, 20 } },
		{ u8"♉", { 4, 21 }, { 5, 21 } },
		{ u8"♊", { 5, 22 }, { 6, 21 } },
		{ u8"♋", { 6, 22 }, { 7, 22 } },
		{ u8"♌", { 7, 23 }, { 8, 22 } },
		{ u8"♍", { 8, 23 }, { 9, 23 } },
		{ u8"♎", { 9, 24 }, { 10, 23 } },
		{ u8"♏", { 10, 24 }, { 11, 22 } },
		{ u8"♐", { 11, 23 }, { 12, 21 } },
		{ u8"♑", { 12, 22 }, { 1, 20 } },
		{ u8"♒", { 1, 21 }, { 2, 19 } },
		{ u8"♓", { 2, 20 }, { 3, 20 } },
	};

	struct tm tm;
	const int *x, *y;
	const char *p;
	size_t i;

	p = strptime(s, "%b %d, %Y", &tm);
	if (*p != '\0')
		return "";

	for (i = 0; i < nelem(tab); i++) {
		x = tab[i].start;
		y = tab[i].end;
		p = tab[i].sym;

		if (tm.tm_mon + 1 == x[0] && tm.tm_mday >= x[1])
			return p;
		if (tm.tm_mon + 1 == y[0] && tm.tm_mday <= y[1])
			return p;
	}

	return "";
}

int
main(void)
{
	assert(!strcmp(zodiac("May 9, 1951"), u8"♉"));
	assert(!strcmp(zodiac("October 31, 1977"), u8"♏"));
	assert(!strcmp(zodiac("January 19, 1985"), u8"♑"));
	assert(!strcmp(zodiac("February 3, 1943"), u8"♒"));
	assert(!strcmp(zodiac("August 28, 1990"), u8"♍"));
	assert(!strcmp(zodiac("April 18, 1929"), u8"♈"));
	assert(!strcmp(zodiac("September 24, 1985"), u8"♎"));
	assert(!strcmp(zodiac("May 29, 1988"), u8"♊"));
	assert(!strcmp(zodiac("June 30, 1998"), u8"♋"));
	assert(!strcmp(zodiac("July 23, 1983"), u8"♌"));
	assert(!strcmp(zodiac("March 20, 1970"), u8"♓"));
	assert(!strcmp(zodiac("November 26, 2000"), u8"♐"));

	return 0;
}
