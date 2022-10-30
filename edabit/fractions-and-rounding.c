/*

Given a fraction frac (given in the format "1/2" for example) and n number of decimal places, return a sentence in the following format:

"{fraction} rounded to {n} decimal places is {answer}"
Examples

fracRound("1/3", 5) ➞ "1/3 rounded to 5 decimal places is 0.33333"

fracRound("2/8", 4) ➞ "2/8 rounded to 4 decimal places is 0.2500"

fracRound("22/7", 2) ➞ "22/7 rounded to 2 decimal places is 3.14"

Notes

    Add trailing zeros if n is greater than the actual number of decimal places the fraction has (see example #2).
    Numbers greater than one may be given as top-heavy fractions (no mixed numbers).
    n won't be 1 because that would cause "decimal places" to be "decimal place", making the challenge more cumbersome than it needs to be.

*/

#include <stdio.h>
#include <string.h>

char *
fracround(const char *s, unsigned d, char *b, size_t n)
{
	int x, y;

	if (sscanf(s, "%d/%d", &x, &y) != 2)
		return NULL;

	snprintf(b, n, "%s rounded to %u decimal places is %.*f", s, d, d, x * 1.0 / y);
	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", fracround("1/3", 5, b, sizeof(b)));
	printf("%s\n", fracround("2/8", 4, b, sizeof(b)));
	printf("%s\n", fracround("22/7", 2, b, sizeof(b)));
	printf("%s\n", fracround("23/2", 2, b, sizeof(b)));
	printf("%s\n", fracround("40/77", 3, b, sizeof(b)));
	printf("%s\n", fracround("15/58", 3, b, sizeof(b)));
	printf("%s\n", fracround("2/92", 2, b, sizeof(b)));
	printf("%s\n", fracround("21/65", 6, b, sizeof(b)));
	printf("%s\n", fracround("29/40", 3, b, sizeof(b)));
	printf("%s\n", fracround("49/38", 6, b, sizeof(b)));
	printf("%s\n", fracround("20/69", 3, b, sizeof(b)));
	printf("%s\n", fracround("17/46", 6, b, sizeof(b)));
	printf("%s\n", fracround("46/28", 4, b, sizeof(b)));
	printf("%s\n", fracround("12/89", 3, b, sizeof(b)));
	printf("%s\n", fracround("9/76", 7, b, sizeof(b)));
	printf("%s\n", fracround("20/64", 4, b, sizeof(b)));
	printf("%s\n", fracround("28/77", 7, b, sizeof(b)));
	printf("%s\n", fracround("17/52", 4, b, sizeof(b)));
	printf("%s\n", fracround("21/98", 6, b, sizeof(b)));
	printf("%s\n", fracround("49/61", 4, b, sizeof(b)));
	printf("%s\n", fracround("28/62", 3, b, sizeof(b)));
	printf("%s\n", fracround("17/36", 3, b, sizeof(b)));
	printf("%s\n", fracround("8/41", 2, b, sizeof(b)));
	printf("%s\n", fracround("50/37", 7, b, sizeof(b)));
	printf("%s\n", fracround("21/41", 3, b, sizeof(b)));
	printf("%s\n", fracround("1/48", 7, b, sizeof(b)));
	printf("%s\n", fracround("12/58", 6, b, sizeof(b)));
	printf("%s\n", fracround("28/99", 5, b, sizeof(b)));
	printf("%s\n", fracround("24/72", 4, b, sizeof(b)));
	printf("%s\n", fracround("45/90", 3, b, sizeof(b)));
	printf("%s\n", fracround("46/85", 5, b, sizeof(b)));
	printf("%s\n", fracround("45/86", 6, b, sizeof(b)));
	printf("%s\n", fracround("42/42", 7, b, sizeof(b)));

	return 0;
}
