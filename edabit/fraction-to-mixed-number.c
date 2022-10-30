/*

Create a function that takes a string representing a fraction, and return a string representing that input as a mixed number.

    Mixed numbers are of the form 1 2/3 — note the space between the whole number portion and the fraction portion.
    Resulting fractions should be fully reduced (see example #2).
    If a result is a whole number with no fractional remainder, return only the whole number portion (see example #3).
    If a result is only fractional with no whole number, return only the fractional portion (see example #4).
    If a result is negative, the whole number should carry the negative sign. If the result would not have a whole number portion, the numerator of the fractional portion should carry the negative sign (see examples #5 - #7).

Examples

mixedNumber("5/4") ➞ "1 1/4"

mixedNumber("6/4") ➞ "1 1/2"

mixedNumber("8/4") ➞ "2"

mixedNumber("4/6") ➞ "2/3"

mixedNumber("-1/4") ➞ "-1/4"

mixedNumber("-5/4") ➞ "-1 1/4"

mixedNumber("-8/4") ➞ "-2"

Notes

All provided inputs will be formatted similarly, negative numbers will be provided in the numerator portion only, and all inputs will contain no spaces, invalid characters, or zero denominators.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

int
snprint(char *str, size_t size, const char *fmt, ...)
{
	va_list ap;
	size_t n;

	va_start(ap, fmt);
	n = vsnprintf(str, size, fmt, ap);
	va_end(ap);
	return (n > size) ? size : n;
}

long
sign(long a)
{
	return (a < 0) ? -1 : 1;
}

long
gcd(long a, long b)
{
	long t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

char *
mixednumber(const char *s, char *b, size_t n)
{
	long x, y, z, sgn;
	size_t l;

	if (sscanf(s, "%ld/%ld", &x, &y) != 2)
		return NULL;
	if (y == 0) {
		snprintf(b, n, "%ld/%ld", x, y);
		return b;
	}

	sgn = sign(x) * sign(y);
	z = gcd(x, y);
	x = labs(x / z);
	y = labs(y / z);

	l = 0;
	if (x / y)
		l += snprint(b + l, n - l, "%ld", sgn * x / y);
	if (x % y) {
		if (l)
			l += snprint(b + l, n - l, " ");
		if (!l && sgn < 0)
			l += snprint(b + l, n - l, "-");
		l += snprint(b + l, n - l, "%ld/%ld", x % y, y);
	}
	if (!l)
		snprintf(b, n, "0");

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	mixednumber(s, b, sizeof(b));
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("5/4", "1 1/4");
	test("6/4", "1 1/2");
	test("8/4", "2");
	test("4/6", "2/3");
	test("-1/4", "-1/4");
	test("-5/4", "-1 1/4");
	test("-8/4", "-2");
	test("0/32768", "0");
	test("73/5", "14 3/5");
	test("3855/889785", "257/59319");
	test("82346/197", "418");
	test("-2037450/204", "-9987 1/2");
	test("0/0", "0/0");
	test("245/0", "245/0");
	test("56/2", "28");

	return 0;
}
