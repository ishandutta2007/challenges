/*

Basing on this SO question.

Challenge is rather simple: given a date period in the format YYYYMM output it in the format MMMYY.
Rules:

    The input will be a number or a string exactly 6 characters long, consisting only of digits.
    Last two digits will be between 01 and 12.
    Output must be in the form MMMYY, where MMM represents uppercase three-letter code for the month (below) and YY represents two last digits of the YYYY part of the input.

List of months with corresponding code:

MM    MMM
01    JAN
02    FEB
03    MAR
04    APR
05    MAY
06    JUN
07    JUL
08    AUG
09    SEP
10    OCT
11    NOV
12    DEC

Examples:

Input     Output
201604    APR16
200001    JAN00
000112    DEC01
123405    MAY34

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
convert(const char *s, char *b)
{
	static const char *tab[] = {
	    "JAN",
	    "FEB",
	    "MAR",
	    "APR",
	    "MAY",
	    "JUN",
	    "JUL",
	    "AUG",
	    "SEP",
	    "OCT",
	    "NOV",
	    "DEC",
	};

	size_t n;
	int m;

	n = 0;
	while (n < 7 && s[n])
		n++;

	if (n != 6)
		return NULL;

	m = 10 * (s[4] - '0') + (s[5] - '0');
	if (!(1 <= m && m <= 12))
		return NULL;

	sprintf(b, "%s%c%c", tab[m - 1], s[2], s[3]);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	assert(convert(s, b));
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("201604", "APR16");
	test("200001", "JAN00");
	test("000112", "DEC01");
	test("123405", "MAY34");
	test("200011", "NOV00");

	return 0;
}
