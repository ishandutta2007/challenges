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

Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	const char *prefix;
	int value;
} Numeral;

static Numeral num2[] = {
    {"IV", 4},
    {"IX", 9},
    {"XL", 40},
    {"XC", 90},
    {"CD", 400},
    {"CM", 900},
};

static Numeral num1[] = {
    {"I", 1},
    {"V", 5},
    {"X", 10},
    {"L", 50},
    {"C", 100},
    {"D", 500},
    {"M", 1000},
};

Numeral *
match(Numeral *p, size_t n, const char *s)
{
	size_t i;
	for (i = 0; i < n; i++) {
		if (!strcmp(s, p[i].prefix))
			return &p[i];
	}
	return NULL;
}

int
roman(const char *s)
{
	Numeral *p;
	size_t i;
	char b[3];
	int n;

	n = 0;
	for (i = 0; s[i]; i++) {
		b[0] = s[i];
		b[1] = s[i + 1];
		b[2] = '\0';

		if ((p = match(num2, nelem(num2), b))) {
			n += p->value;
			i++;
			continue;
		}

		b[1] = '\0';
		if ((p = match(num1, nelem(num1), b)))
			n += p->value;
	}
	return n;
}

int
main(void)
{
	printf("%d\n", roman("II"));
	printf("%d\n", roman("III"));
	printf("%d\n", roman("XII"));
	printf("%d\n", roman("XXVII"));
	printf("%d\n", roman("IV"));
	printf("%d\n", roman("V"));
	printf("%d\n", roman("IX"));
	printf("%d\n", roman("LVIII"));
	printf("%d\n", roman("MCMXCIV"));
	printf("%d\n", roman("CDIV"));
	return 0;
}
