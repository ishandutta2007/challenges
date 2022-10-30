/*

A resistor is a common electrical component found in every electronic circuit. Usually a resistor has a color-based code (as painted bands over it) to decipher through a table.
Color	Digits	Magnitude	Tolerance	T.C.R.
Black	0	0	-	-
Brown	1	1	±1%	100ppm/k
Red	2	2	±2%	50ppm/k
Orange	3	3	-	15ppm/k
Yellow	4	4	-	25ppm/k
Green	5	5	±0.5%	-
Blue	6	6	±0.25%	10ppm/k
Violet	7	7	±0.1%	5ppm/k
Gray	8	8	±0.05%	-
White	9	9	-	-
Gold	-	-1	±5%	-
Silver	-	-2	±10%	-

Starting from the left assign a number to each coloured band:

    4 bands resistor:
        1st and 2nd color: digits from column 1.
        3rd color: 10 elevated to the digit of column 2.
        4th color: tolerance from column 3.
    5 bands resistor:
        1st, 2nd and 3rd color: digits from column 1.
        4th color: 10 elevated to the digit of column 2.
        5th color: tolerance from column 3.
    6 bands resistor:
        From 1st to 5th: as above.
        6th color: coefficient from column 4.

Then, when numbers have replaced colors:

    Resistance is equal to the number resulting by the union of digits from column 1 multiplied for the magnitude calculated from column 2: is measured in Ohms (symbol: Ω). When Ohms are in the thousands order the notation is kΩ (kiloOhms), in the millions order the notation is MΩ (MegaOhms), in the billions order the notation is GΩ (GigaOhms).
    Tolerance and TCR (temperature coefficient of resistance, only for 6-banded resistors) are the results of columns 3 and 4.

Given an array of colors you must return the resistor resistance, tolerance and (eventually) the TCR as a string (with identifiers separated by spaces between them).
Examples

resistorCode(["red", "yellow", "blue", "green"]) ➞ "24MΩ ±0.5%"
// red + yellow = 24; blue = 10^6, green = ±0.5%
// resistance * magnitude = 24000000 (24M)

resistorCode(["white", "black", "white", "blue", "gold"]) ➞ "909MΩ ±5%"
// white + black + white = 909

resistorCode(["black", "white", "black", "orange", "red", "yellow"]) ➞ "90kΩ ±2% 25ppm/k"
// black + white + black = 090 = 90; orange = 10^3
// resistance * magnitude = 90000 (90k)

Notes

    For more info about resistors and their color codes check the Resources tab.
    All given arrays are valid, no exceptions to handle.

*/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
snprint(char *str, size_t size, const char *fmt, ...)
{
	va_list ap;
	size_t n;

	va_start(ap, fmt);
	n = vsnprintf(str, size, fmt, ap);
	va_end(ap);
	return (size < n) ? size : n;
}

char *
resistorcode(const char **r, size_t nr, char *b, size_t n)
{
	static const struct {
		const char *pre;
		double mag;
	} units[] = {
		{ "", 1e0 },
		{ "k", 1e3 },
		{ "M", 1e6 },
		{ "G", 1e9 },
	};

	static const struct {
		const char *name;
		int val;
		double mag;
		const char *tol;
		const char *tcr;
	} codes[] = {
		{ "black", 0, 1e0, NULL, NULL },
		{ "brown", 1, 1e1, u8"±1%", "100ppm/k" },
		{ "red", 2, 1e2, u8"±2%", "50ppm/k" },
		{ "orange", 3, 1e3, NULL, "15ppm/k" },
		{ "yellow", 4, 1e4, NULL, "25ppm/k" },
		{ "green", 5, 1e5, u8"±0.5%", NULL },
		{ "blue", 6, 1e6, u8"±0.25%", "10ppm/k" },
		{ "violet", 7, 1e7, u8"±0.1%", "5ppm/k" },
		{ "gray", 8, 1e8, u8"±0.05%", NULL },
		{ "white", 9, 1e9, NULL, NULL },
		{ "gold", -1, 1e-1, u8"±5%", NULL },
		{ "silver", -2, 1e-2, u8"±10%", NULL },
		{ NULL },
	};

	size_t i, j, l, o;
	double v;
	int f[6];

	if (!(4 <= nr && nr <= 6))
		return NULL;

	for (i = 0; i < nr; i++) {
		f[i] = -1;
		for (j = 0; j < nelem(codes); j++) {
			if (!strcmp(r[i], codes[j].name)) {
				f[i] = j;
				break;
			}
		}
		if (f[i] < 0)
			return NULL;
	}

	o = (nr == 4) ? 2 : 3;
	v = 0;
	for (i = 0; i < o; i++)
		v = (v * 10) + codes[f[i]].val;
	v *= codes[f[o]].mag;

	j = 0;
	for (i = 0; i < nelem(units) - 1; i++) {
		if (v < units[i + 1].mag) {
			j = i;
			break;
		}
	}
	if (i + 1 >= nelem(units))
		j = nelem(units) - 1;

	l = 0;
	l += snprint(b + l, n - l, u8"%.1f%sΩ %s", v / units[j].mag, units[j].pre, codes[f[o + 1]].tol);
	if (nr > 5)
		l += snprint(b + l, n - l, " %s", codes[f[5]].tcr);

	return b;
}

int
main(void)
{
	const char *r1[] = { "red", "yellow", "blue", "green" };
	const char *r2[] = { "white", "black", "white", "blue", "gold" };
	const char *r3[] = { "black", "white", "black", "orange", "red", "yellow" };
	const char *r4[] = { "black", "blue", "black", "brown" };
	const char *r5[] = { "orange", "yellow", "white", "gold", "gray" };
	const char *r6[] = { "yellow", "brown", "green", "black", "green", "orange" };
	const char *r7[] = { "brown", "violet", "red", "silver" };
	const char *r8[] = { "green", "gray", "black", "silver", "blue" };
	const char *r9[] = { "white", "white", "white", "white", "silver", "violet" };
	char b[80];

	printf("%s\n", resistorcode(r1, nelem(r1), b, sizeof(b)));
	printf("%s\n", resistorcode(r2, nelem(r2), b, sizeof(b)));
	printf("%s\n", resistorcode(r3, nelem(r3), b, sizeof(b)));
	printf("%s\n", resistorcode(r4, nelem(r4), b, sizeof(b)));
	printf("%s\n", resistorcode(r5, nelem(r5), b, sizeof(b)));
	printf("%s\n", resistorcode(r6, nelem(r6), b, sizeof(b)));
	printf("%s\n", resistorcode(r7, nelem(r7), b, sizeof(b)));
	printf("%s\n", resistorcode(r8, nelem(r8), b, sizeof(b)));
	printf("%s\n", resistorcode(r9, nelem(r9), b, sizeof(b)));
	return 0;
}
