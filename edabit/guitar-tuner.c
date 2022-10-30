/*

Create a function that takes guitar strings as an array of frequencies (numbers) and returns the display of a tuner as an array. You can find the frequencies of the strings on the Wikipedia page (check the Resources tab).

    The guitar strings are played 1st to 6th, High E to Low E.
    If the guitar string matches, return "OK" for that guitar string.
    If it's too low, return ">•" for 1 or 2 percent off (the arrow means, tune up).
    Return ">>•" if it's way off. For more than 3 percent.
    If it's too high, return "•<" for 1 or 2 percent, and "•<<" for more, (tune down).
    Check the rounded percentages.
    If 0 is given, the guitar string isn't played, return " - ".

Examples

tune([0, 246.94, 0, 0, 0, 80]) ➞ [" - ", "OK", " - ", " - ", " - ", ">>•"]

tune([329, 246, 195, 146, 111, 82]) ➞ ["OK", "OK", ">•", ">•", "•<", "OK" ]

tune([329.63, 246.94, 196, 146.83, 110, 82.41]) ➞ ["OK", "OK", "OK", "OK", "OK", "OK"]

Notes

Items in the array will always be numbers.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void
tune(double f[6], const char *p[6])
{
	static const double tab[] = {
		329.63,
		246.94,
		196.00,
		146.83,
		110.00,
		82.41,
	};

	double r;
	int i;

	for (i = 0; i < 6; i++) {
		if (f[i] == 0) {
			p[i] = " - ";
			continue;
		}

		r = f[i] / tab[i];
		if (0.995 <= r && r <= 1.005)
			p[i] = "OK";
		else if (0.98 <= r && r <= 1.02)
			p[i] = (f[i] < tab[i]) ? u8">•" : u8"•<";
		else
			p[i] = (f[i] < tab[i]) ? u8">>•" : u8"•<<";
	}
}

void
test(double f[6], const char *p[6])
{
	const char *b[6];
	int i;

	tune(f, b);
	for (i = 0; i < 6; i++)
		assert(strcmp(b[i], p[i]) == 0);
}

int
main(void)
{
	double f1[] = { 329.63, 246.94, 196, 146.83, 110, 82.41 };
	double f2[] = { 0, 0, 190, 0, 110, 0 };
	double f3[] = { 331, 248, 195, 147, 110, 84 };
	double f4[] = { 0, 246.94, 0, 0, 0, 80 };
	double f5[] = { 329, 246, 195, 146, 111, 82 };

	const char *p1[] = { "OK", "OK", "OK", "OK", "OK", "OK" };
	const char *p2[] = { " - ", " - ", u8">>•", " - ", "OK", " - " };
	const char *p3[] = { "OK", "OK", u8">•", "OK", "OK", u8"•<" };
	const char *p4[] = { " - ", "OK", " - ", " - ", " - ", u8">>•" };
	const char *p5[] = { "OK", "OK", u8">•", u8">•", u8"•<", "OK" };

	test(f1, p1);
	test(f2, p2);
	test(f3, p3);
	test(f4, p4);
	test(f5, p5);

	return 0;
}
