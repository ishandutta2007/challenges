/*

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9.
    X can be placed before L (50) and C (100) to make 40 and 90.
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

*/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
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
itor(char *b, size_t n, unsigned x)
{
	static const struct {
		const char *sym;
		unsigned val;
	} tab[] = {
	    {"I", 1},
	    {"IV", 4},
	    {"V", 5},
	    {"IX", 9},
	    {"X", 10},
	    {"XL", 40},
	    {"L", 50},
	    {"XC", 90},
	    {"C", 100},
	    {"CD", 400},
	    {"D", 500},
	    {"CM", 900},
	    {"M", 1000},
	};

	size_t i, l;

	l = 0;
	l += snprint(b + l, n - l, "");

	for (i = nelem(tab) - 1;; i--) {
		while (x >= tab[i].val) {
			l += snprint(b + l, n - l, tab[i].sym);
			x -= tab[i].val;
		}
		if (i == 0)
			break;
	}

	return b;
}

int
main(void)
{
	char b[80];
	printf("%s\n", itor(b, sizeof(b), 0));
	printf("%s\n", itor(b, sizeof(b), 3));
	printf("%s\n", itor(b, sizeof(b), 4));
	printf("%s\n", itor(b, sizeof(b), 9));
	printf("%s\n", itor(b, sizeof(b), 58));
	printf("%s\n", itor(b, sizeof(b), 1994));
	printf("%s\n", itor(b, sizeof(b), 2));
	printf("%s\n", itor(b, sizeof(b), 12));
	printf("%s\n", itor(b, sizeof(b), 27));
	printf("%s\n", itor(b, sizeof(b), 6));
	return 0;
}
