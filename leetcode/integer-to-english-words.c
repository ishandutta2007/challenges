/*

Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1.

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
	    "Zero",
	    "One",
	    "Two",
	    "Three",
	    "Four",
	    "Five",
	    "Six",
	    "Seven",
	    "Eight",
	    "Nine",
	    "Ten",
	    "Eleven",
	    "Twelve",
	    "Thirteen",
	    "Fourteen",
	    "Fifteen",
	    "Sixteen",
	    "Seventeen",
	    "Eighteen",
	    "Nineteen",
	};
	static const char *tens[] = {
	    "Twenty",
	    "Thirty",
	    "Forty",
	    "Fifty",
	    "Sixty",
	    "Seventy",
	    "Eighty",
	    "Ninety",
	};
	static const char *mag[] = {
	    "Thousand",
	    "Million",
	    "Billion",
	    "Trillion",
	    "Quadrillion",
	    "Quintillion",
	    "Sextillion",
	    "Septillion",
	};
	char s[80];
	size_t l;
	int i, m, t, r, o;

	m = snprint(s, sizeof(s), "%ld", x);
	l = 0;

	i = 0;
	if (s[i] == '-') {
		l += snprint(b + l, n - l, "Negative ");
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
			l += snprint(b + l, n - l, " ");

		if (t >= 100) {
			l += snprint(b + l, n - l, "%s Hundred", num[t / 100]);
			t %= 100;
			if (t != 0)
				l += snprint(b + l, n - l, " ");
		}

		if (t >= 20) {
			l += snprint(b + l, n - l, "%s", tens[t / 10 - 2]);
			if (t % 10)
				l += snprint(b + l, n - l, " %s", num[t % 10]);
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
	long t[] = {
	    123,
	    12345,
	    1234567,
	    1234567891,
	};
	char b[256];
	size_t i;

	for (i = 0; i < nelem(t); i++)
		printf("%ld %s\n", i, spellout(b, nelem(b), t[i]));
	return 0;
}
