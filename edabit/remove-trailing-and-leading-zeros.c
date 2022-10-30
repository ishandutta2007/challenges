/*

Create a function that takes in a number as a string n and returns the number without trailing and leading zeros.

    Trailing Zeros are the zeros after a decimal point which don't affect the value (e.g. the last three zeros in 3.4000 and 3.04000).
    Leading Zeros are the zeros before a whole number which don't affect the value (e.g. the first three zeros in 000234 and 000230).

Examples

removeLeadingTrailing("230.000") ➞ "230"

removeLeadingTrailing("00402") ➞ "402"

removeLeadingTrailing("03.1400") ➞ "3.14"

removeLeadingTrailing("30") ➞ "30"

Notes

    Return a string.
    If you get a number with .0 on the end, return the integer value (e.g. return "4" rather than "4.0").
    If the number is 0, 0.0, 000, 00.00, etc... return "0".

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
trimz(const char *s, char *b)
{
	size_t i, j;
	int f;

	if (s[0] == '\0') {
		b[0] = '\0';
		return b;
	}

	i = j = 0;
	while (s[i] == '0')
		i++;

	if (s[i] == '.')
		b[j++] = '0';

	f = 0;
	while (s[i]) {
		if (s[i] == '.')
			f = 1;
		b[j++] = s[i++];
	}

	if (f) {
		while (j > 0 && b[j - 1] == '0')
			j--;

		if (j > 0 && b[j - 1] == '.')
			j--;
	}
	if (j == 0)
		b[j++] = '0';

	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	trimz(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("230.000", "230");
	test("00402", "402");
	test("03.1400", "3.14");
	test("30", "30");
	test("24340", "24340");
	test("0404040", "404040");
	test("0", "0");
	test("00", "0");
	test("0.000000", "0");
	test("0000.000", "0");
	test("00.0001", "0.0001");
	test("10000", "10000");
	test("1345", "1345");
	test("30.000020", "30.00002");
	test("00200.1900001", "200.1900001");

	return 0;
}
