/*

Often times in commercials, phone numbers contain letters so that they're easy to remember (e.g. 1-800-VERIZON).
Write a program that will convert a phone number that contains letters into a phone number with only numbers and the appropriate dash.
Click here to learn more about the telephone keypad.

Example Execution: Input: 1-800-COMCAST Output: 1-800-266-2278

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
conv(int c)
{
	if (isdigit(c))
		return c - '0';

	c = toupper(c);
	if ('A' <= c && c <= 'C')
		return 2;
	if ('D' <= c && c <= 'F')
		return 3;
	if ('G' <= c && c <= 'I')
		return 4;
	if ('J' <= c && c <= 'L')
		return 5;
	if ('M' <= c && c <= 'O')
		return 6;
	if ('P' <= c && c <= 'S')
		return 7;
	if ('T' <= c && c <= 'V')
		return 8;
	if ('W' <= c && c <= 'Z')
		return 9;

	return -1;
}

char *
tel2num(const char *s, char *b)
{
	char p[32];
	size_t i, j;
	int c;

	for (i = j = 0; s[i] && i < nelem(p); i++) {
		c = conv(s[i]);
		if (c >= 0)
			p[j++] = c;
	}

	switch (j) {
	case 11:
		sprintf(b, "%d-%d%d%d-%d%d%d-%d%d%d%d",
		        p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10]);
		break;

	case 10:
		sprintf(b, "%d%d%d-%d%d%d-%d%d%d%d",
		        p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9]);
		break;

	case 7:
		sprintf(b, "%d%d%d-%d%d%d%d",
		        p[0], p[1], p[2], p[3], p[4], p[5], p[6]);
		break;

	default:
		return NULL;
	}

	return b;
}

void
test(const char *s, const char *r)
{
	char b[32];

	assert(tel2num(s, b) != NULL);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("1-800-COMCAST", "1-800-266-2278");
	test("1-800-VERIZON", "1-800-837-4966");
	test("555-ABCD", "555-2223");
	test("555-593-2413", "555-593-2413");

	return 0;
}
