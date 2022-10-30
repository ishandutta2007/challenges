/*

Traveling through Europe one needs to pay attention to how the license plate in the given country is displayed.
When crossing the border you need to park on the shoulder, unscrew the plate, re-group the characters according to the local regulations, attach it back and proceed with the journey.

Create a solution that can format the dmv number into a plate number with correct grouping.
The function input consists of string s and group length n. The output has to be upper case characters and digits.
The new groups are made from right to left and connected by -. The original order of the dmv number is preserved.

Examples

licensePlate("5F3Z-2e-9-w", 4) ➞ "5F3Z-2E9W"

licensePlate("2-5g-3-J", 2) ➞ "2-5G-3J"

licensePlate("2-4A0r7-4k", 3) ➞ "24-A0R-74K"

licensePlate("nlj-206-fv", 3) ➞ "NL-J20-6FV"

Notes

    You are expected to solve this challenge via a recursive approach.
    An iterative version of this challenge can be found via this link.
    A collection of challenges in recursion can be found via this link.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

unsigned
count(const char *s)
{
	if (*s == '\0')
		return 0;
	return (*s != '-') + count(s + 1);
}

char *
swaps(const char *s, unsigned n, unsigned l, char *b, unsigned i)
{
	if (*s == '\0') {
		*b = '\0';
		return b;
	}
	if (*s == '-')
		return swaps(s + 1, n, l, b, i);

	*b++ = toupper(*s++);
	if (++i >= l) {
		if (*s)
			*b++ = '-';
		i = 0;
		l = n;
	}
	return swaps(s, n, l, b, i);
}

char *
licenseplate(const char *s, unsigned n, char *b)
{
	unsigned l;

	l = count(s) % n;
	if (l == 0)
		l = n;
	return swaps(s, n, l, b, 0);
}

void
test(const char *s, unsigned n, const char *r)
{
	char b[128];

	licenseplate(s, n, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("5F3Z-2e-9-w", 4, "5F3Z-2E9W");
	test("2-5g-3-J", 2, "2-5G-3J");
	test("2-4A0r7-4k", 3, "24-A0R-74K");
	test("GB-bd519-KFC", 2, "GB-BD-51-9K-FC");
	test("BF-11gf9i-7819iT", 3, "BF-11G-F9I-781-9IT");
	test("Fin-Mmg-418", 3, "FIN-MMG-418");
	test("sPx-o755", 3, "S-PXO-755");
	test("de57-uk", 2, "DE-57-UK");
	test("d-kapa-7778", 4, "D-KAPA-7778");
	test("nlj-206-fv", 3, "NL-J20-6FV");

	return 0;
}
