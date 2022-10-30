/*

Given a simple math expression as a string, neatly format it as an equation.
Examples

formatMath("3 + 4") ➞ "3 + 4 = 7"

formatMath("3 - 2") ➞ "3 - 2 = 1"

formatMath("4 x 5") ➞ "4 x 5 = 20"

formatMath("6 / 3") ➞ "6 / 3 = 2"

Notes

    You will need to deal with addition, subtraction, multiplication and division.
    Division will have whole number answers (and will obviously not involve 0).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
mathfmt(const char *s, char *b, size_t n)
{
	int x, y, z;
	char op;

	if (sscanf(s, "%d %c %d", &x, &op, &y) != 3) {
		snprintf(b, n, "invalid equation");
		return b;
	}

	switch (op) {
	case '+':
		z = x + y;
		break;
	case '-':
		z = x - y;
		break;
	case 'x':
		z = x * y;
		break;
	case '/':
		if (y)
			z = x / y;
		break;
	}

	if (y)
		snprintf(b, n, "%d %c %d = %d", x, op, y, z);
	else
		snprintf(b, n, "%d %c %d = NaN", x, op, y);
	return b;
}

int
main(void)
{
	char b[80];

	assert(!strcmp(mathfmt("3 + 4", b, sizeof(b)), "3 + 4 = 7"));
	assert(!strcmp(mathfmt("3 - 2", b, sizeof(b)), "3 - 2 = 1"));
	assert(!strcmp(mathfmt("4 x 5", b, sizeof(b)), "4 x 5 = 20"));
	assert(!strcmp(mathfmt("6 / 3", b, sizeof(b)), "6 / 3 = 2"));
	assert(!strcmp(mathfmt("9 / 3", b, sizeof(b)), "9 / 3 = 3"));
	assert(!strcmp(mathfmt("21 / 3,", b, sizeof(b)), "21 / 3 = 7"));
	assert(!strcmp(mathfmt("24 / 3,", b, sizeof(b)), "24 / 3 = 8"));
	assert(!strcmp(mathfmt("80 / 8,", b, sizeof(b)), "80 / 8 = 10"));
	assert(!strcmp(mathfmt("60 / 30", b, sizeof(b)), "60 / 30 = 2"));
	assert(!strcmp(mathfmt("44 - 11", b, sizeof(b)), "44 - 11 = 33"));
	assert(!strcmp(mathfmt("48 + 35", b, sizeof(b)), "48 + 35 = 83"));
	assert(!strcmp(mathfmt("8 + 5", b, sizeof(b)), "8 + 5 = 13"));
	assert(!strcmp(mathfmt("46 - 11", b, sizeof(b)), "46 - 11 = 35"));
	assert(!strcmp(mathfmt("23 x 46", b, sizeof(b)), "23 x 46 = 1058"));
	assert(!strcmp(mathfmt("11 + 1", b, sizeof(b)), "11 + 1 = 12"));
	assert(!strcmp(mathfmt("29 - 21", b, sizeof(b)), "29 - 21 = 8"));
	assert(!strcmp(mathfmt("24 x 26", b, sizeof(b)), "24 x 26 = 624"));
	assert(!strcmp(mathfmt("47 + 8", b, sizeof(b)), "47 + 8 = 55"));
	assert(!strcmp(mathfmt("42 - 48", b, sizeof(b)), "42 - 48 = -6"));
	assert(!strcmp(mathfmt("33 x 44", b, sizeof(b)), "33 x 44 = 1452"));
	assert(!strcmp(mathfmt("26 + 3", b, sizeof(b)), "26 + 3 = 29"));
	assert(!strcmp(mathfmt("32 + 17", b, sizeof(b)), "32 + 17 = 49"));
	assert(!strcmp(mathfmt("3 x 26", b, sizeof(b)), "3 x 26 = 78"));
	assert(!strcmp(mathfmt("12 x 25", b, sizeof(b)), "12 x 25 = 300"));
	assert(!strcmp(mathfmt("43 + 31", b, sizeof(b)), "43 + 31 = 74"));
	assert(!strcmp(mathfmt("28 + 27", b, sizeof(b)), "28 + 27 = 55"));
	assert(!strcmp(mathfmt("24 - 11", b, sizeof(b)), "24 - 11 = 13"));
	assert(!strcmp(mathfmt("20 x 50", b, sizeof(b)), "20 x 50 = 1000"));
	assert(!strcmp(mathfmt("36 - 30", b, sizeof(b)), "36 - 30 = 6"));
	assert(!strcmp(mathfmt("34 x 48", b, sizeof(b)), "34 x 48 = 1632"));
	assert(!strcmp(mathfmt("26 + 8", b, sizeof(b)), "26 + 8 = 34"));
	assert(!strcmp(mathfmt("25 - 44", b, sizeof(b)), "25 - 44 = -19"));
	assert(!strcmp(mathfmt("24 x 25", b, sizeof(b)), "24 x 25 = 600"));
	assert(!strcmp(mathfmt("40 x 17", b, sizeof(b)), "40 x 17 = 680"));
	assert(!strcmp(mathfmt("44 - 7", b, sizeof(b)), "44 - 7 = 37"));
	assert(!strcmp(mathfmt("37 x 41", b, sizeof(b)), "37 x 41 = 1517"));
	assert(!strcmp(mathfmt("15 - 1", b, sizeof(b)), "15 - 1 = 14"));
	assert(!strcmp(mathfmt("16 x 4", b, sizeof(b)), "16 x 4 = 64"));
	assert(!strcmp(mathfmt("13 x 43", b, sizeof(b)), "13 x 43 = 559"));
	assert(!strcmp(mathfmt("7 x 11", b, sizeof(b)), "7 x 11 = 77"));
	assert(!strcmp(mathfmt("12 - 25", b, sizeof(b)), "12 - 25 = -13"));
	assert(!strcmp(mathfmt("37 + 6", b, sizeof(b)), "37 + 6 = 43"));
	assert(!strcmp(mathfmt("32 x 46", b, sizeof(b)), "32 x 46 = 1472"));
	assert(!strcmp(mathfmt("31 x 5", b, sizeof(b)), "31 x 5 = 155"));
	assert(!strcmp(mathfmt("17 - 37", b, sizeof(b)), "17 - 37 = -20"));
	assert(!strcmp(mathfmt("31 + 36", b, sizeof(b)), "31 + 36 = 67"));
	assert(!strcmp(mathfmt("17 x 34", b, sizeof(b)), "17 x 34 = 578"));
	assert(!strcmp(mathfmt("24 - 3", b, sizeof(b)), "24 - 3 = 21"));
	assert(!strcmp(mathfmt("48 + 33", b, sizeof(b)), "48 + 33 = 81"));
	assert(!strcmp(mathfmt("19 + 1", b, sizeof(b)), "19 + 1 = 20"));
	assert(!strcmp(mathfmt("45 + 1", b, sizeof(b)), "45 + 1 = 46"));
	assert(!strcmp(mathfmt("34 + 24", b, sizeof(b)), "34 + 24 = 58"));
	assert(!strcmp(mathfmt("32 + 41", b, sizeof(b)), "32 + 41 = 73"));
	assert(!strcmp(mathfmt("1 - 21", b, sizeof(b)), "1 - 21 = -20"));
	assert(!strcmp(mathfmt("40 x 8", b, sizeof(b)), "40 x 8 = 320"));
	assert(!strcmp(mathfmt("4 - 16", b, sizeof(b)), "4 - 16 = -12"));
	assert(!strcmp(mathfmt("30 - 43", b, sizeof(b)), "30 - 43 = -13"));
	assert(!strcmp(mathfmt("26 + 49", b, sizeof(b)), "26 + 49 = 75"));
	assert(!strcmp(mathfmt("24 x 38", b, sizeof(b)), "24 x 38 = 912"));

	return 0;
}
