/*

The International Standard Book Number (ISBN) is a unique identifying number given to each published book. ISBNs assigned after January 2007 are 13 digits long (ISBN-13), however books with 10-digit ISBNs are still in wide use.

An ISBN-10 is verified this way:

isbn10 = "0330301624"

Line up the digits with the numbers 10 to 1:

0	3	3	0	3	0	1	6	2	4
10	9	8	7	6	5	4	3	2	1

Multiply each digit with the number below it (the 10th digit in an ISBN can be an X. This last X simply means 10).

Sum up the products:

0 + 27 + 24 + 0 + 18 + 0 + 4 + 18 + 4 + 4 = 99

If the sum is divisible by 11, the ISBN-10 is valid.

An ISBN-13 is verified this way:

isbn13 = "9780316066525"

Line up the digits with alternating 1s and 3s:

9	7	8	0	3	1	6	0	6	6	5	2	5
1	3	1	3	1	3	1	3	1	3	1	3	1

Multiply each digit with the number below it and get the sum:

9 + 21 + 8 + 0 + 3 + 3 + 6 + 0 + 6 + 18 + 5 + 6 + 5 = 90

If the sum is divisible by 10, the ISBN-13 is valid.

Create a function that takes a string of numbers (possibly with an X at the end) and...

    Return "Invalid" if it is not a valid ISBN-10 or ISBN-13.
    Return "Valid" if it is a valid ISBN-13.
    If it is a valid ISBN-10, convert it into an ISBN-13 and return the ISBN-13 number.

Convert a valid ISBN-10 to ISBN-13 by tacking 978 to the start, then changing the last digit (the check digit) so that the resulting number passes the ISBN-13 check.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int
calcbn(const char *s, unsigned long *v, size_t *l)
{
	unsigned long r;
	size_t i, n;

	*l = n = strlen(s);
	if (n != 10 && n != 13)
		return 0;

	r = 0;
	for (i = 0; s[i]; i++) {
		if (n == 10 && i == 9 && s[i] == 'X') {
			r += 10 * (i + 1);
			continue;
		}

		if (!isdigit(s[i]))
			return 0;

		if (n == 10)
			r += (s[i] - '0') * (i + 1);
		else
			r += (s[i] - '0') * ((i & 1) ? 3 : 1);
	}
	*v = r;

	if (n == 10 && (r % 11) != 0)
		return 0;
	if (n == 13 && (r % 10) != 0)
		return 0;
	return 1;
}

char *
isbn13(const char *s, char *b, size_t n)
{
	unsigned long v;
	size_t l;

	if (n < 13)
		return NULL;

	if (!calcbn(s, &v, &l))
		snprintf(b, n, "Invalid");
	else if (l == 10) {
		snprintf(b, n, "978%s", s);
		b[12] = '0';
		calcbn(b, &v, &l);
		b[12] = '0' + 10 - (v % 10);
	} else if (l == 13)
		snprintf(b, n, "Valid");
	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", isbn13("0330301824", b, sizeof(b)));
	printf("%s\n", isbn13("0316066524", b, sizeof(b)));
	printf("%s\n", isbn13("0330301624", b, sizeof(b)));
	printf("%s\n", isbn13("9780316066525", b, sizeof(b)));
	printf("%s\n", isbn13("9783866155237", b, sizeof(b)));
	printf("%s\n", isbn13("9780345453747", b, sizeof(b)));
	printf("%s\n", isbn13("031606652X", b, sizeof(b)));
	printf("%s\n", isbn13("9783876155237", b, sizeof(b)));
	printf("%s\n", isbn13("0345453747", b, sizeof(b)));
	printf("%s\n", isbn13("0316066524", b, sizeof(b)));
	printf("%s\n", isbn13("3866155239", b, sizeof(b)));
	printf("%s\n", isbn13("817450494X", b, sizeof(b)));

	return 0;
}
