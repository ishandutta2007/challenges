/*

A number n is called uban if its name (in English) does not contain the letter "u".
In particular, it cannot contain the terms "four", "hundred", and "thousand", so the uban number following 99 is 1,000,000.

Write a function to determine if the given integer is uban.

Examples

IsUban(456) ➞ false

IsUban(25) ➞ true

IsUban(1098) ➞ false

Notes

N/A

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

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

bool
isuban(long x)
{
	char b[1024];

	spellout(b, sizeof(b), x);
	return strchr(b, 'u') == NULL;
}

int
main(void)
{
	assert(isuban(456) == false);
	assert(isuban(25) == true);
	assert(isuban(1098) == false);
	assert(isuban(0) == true);
	assert(isuban(24) == false);
	assert(isuban(223) == false);
	assert(isuban(2051) == false);
	assert(isuban(627) == false);
	assert(isuban(6258) == false);
	assert(isuban(12) == true);
	assert(isuban(202) == false);
	assert(isuban(98) == true);
	assert(isuban(6592) == false);
	assert(isuban(393) == false);
	assert(isuban(1000096l) == true);
	assert(isuban(40) == true);

	return 0;
}
