/*
Given a number, write out the spelling of a number.

Example:
1: one
-2147483648: negative two billion, one hundred forty-seven million, four hundred eighty-three thousand, six hundred forty-eight
2147483647: two billion, one hundred forty-seven million, four hundred eighty-three thousand, six hundred forty-seven

*/
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / (sizeof(x[0])))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
snprint(char *str, size_t size, const char *fmt, ...)
{
	va_list ap;
	size_t n;

	va_start(ap, fmt);
	n = vsnprintf(str, size, fmt, ap);
	va_end(ap);
	return min(size, n);
}

char *
spellout(char *b, size_t n, long x)
{
	static const char *num[] = {
	    "zero",
	    "one",
	    "two",
	    "three",
	    "four",
	    "five",
	    "six",
	    "seven",
	    "eight",
	    "nine",
	    "ten",
	    "eleven",
	    "twelve",
	    "thirteen",
	    "fourteen",
	    "fifteen",
	    "sixteen",
	    "seventeen",
	    "eighteen",
	    "nineteen",
	};
	static const char *tens[] = {
	    "twenty",
	    "thirty",
	    "forty",
	    "fifty",
	    "sixty",
	    "seventy",
	    "eighty",
	    "ninety",
	};
	static const char *mag[] = {
	    "thousand",
	    "million",
	    "billion",
	    "trillion",
	    "quadrillion",
	    "quintillion",
	    "sextillion",
	    "septillion",
	};
	char s[80];
	size_t l;
	int i, m, t, r, o;

	m = snprint(s, sizeof(s), "%ld", x);
	l = 0;

	i = 0;
	if (s[i] == '-') {
		l += snprint(b + l, n - l, "negative ");
		m--;
		i++;
	}

	o = 0;
	for (;;) {
		t = 0;
		switch ((r = m % 3)) {
		case 0:
			t += (s[i++] - '0') * 100;
			// fallthrough
		case 2:
			t += (s[i++] - '0') * 10;
			// fallthrough
		case 1:
			t += s[i++] - '0';
			break;
		}

		if (t != 0 && o)
			l += snprint(b + l, n - l, ", ");

		if (t >= 100) {
			l += snprint(b + l, n - l, "%s hundred", num[t / 100]);
			t %= 100;
			if (t != 0)
				l += snprint(b + l, n - l, " ");
		}

		if (t >= 20) {
			l += snprint(b + l, n - l, "%s", tens[t / 10 - 2]);
			if (t % 10)
				l += snprint(b + l, n - l, "-%s", num[t % 10]);
		} else if (!(r == 0 && t == 0) || (!o && t != 0))
			l += snprint(b + l, n - l, "%s", num[t]);

		m -= (r == 0) ? 3 : r;
		if (m <= 0)
			break;

		if (t != 0)
			l += snprint(b + l, n - l, " %s", mag[m / 3 - 1]);
		o = 1;
	}

	return b;
}

int
main(void)
{
	char b[256];
	long i;

	i = INT_MIN;
	printf("%ld %s\n", i, spellout(b, nelem(b), i));

	i = INT_MAX;
	printf("%ld %s\n", i, spellout(b, nelem(b), i));

	i = LONG_MIN;
	printf("%ld %s\n", i, spellout(b, nelem(b), i));

	i = LONG_MAX;
	printf("%ld %s\n", i, spellout(b, nelem(b), i));

	for (i = 0; i <= 1000000000; i++)
		printf("%ld %s\n", i, spellout(b, nelem(b), i));
	return 0;
}
