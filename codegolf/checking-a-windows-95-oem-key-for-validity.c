/*

Introduction

Windows 95 used a very simple algorithm for verifying license keys. The scheme of an OEM license key always looked like this:

xxxyy-OEM-NNNNNNN-zzzzz

The day can be anything within 001-366, and the year cannot be lower than 95 or above 03.

xxx represents the day of the year the key was printed on (for example 192 = 10th of July) and is a number between 001-366. yy represents the year the key was printed on and cannot be lower than 95 or above 03.

This means for example, a key with 19296 as the first segment was printed on 10th of July 1996.

The second segment is always OEM.

The third segment (NN..) is always starts with 00 and the sum of the digits has to be divisible by 7

The fourth segment is irrelevant, provided the field is the appropriate length, but has to be filled out with digits.
Challange

Given a string, output a truthy or falsy value whether this oem key is valid or not.
Rules

    You may provide a function or a program
    This is code-golf, so the submission with the least amount of bytes wins!

Test cases
Valid keys

12899-OEM-0042134-31009
15795-OEM-0001355-07757
35201-OEM-0009165-64718

Invalid keys

12804-OEM-0033143-31009
16595-OEM-0001695-9
12899-OEM-0022134-31009
27497-OEM-0525347-80387

*/

#include <assert.h>
#include <stdio.h>

int
valid(const char *s)
{
	int a, b, d, y, v;
	size_t n;

	n = 0;
	while (s[n] && n < 24)
		n++;

	if (n != 23)
		return 0;

	if (sscanf(s, "%3d%2d-OEM-00%5d-%7d", &d, &y, &a, &b) != 4)
		return 0;

	if (!(1 <= d && d <= 366) || (3 < y && y < 95))
		return 0;

	for (v = 0; a; a /= 10)
		v += a % 10;
	if (v % 7)
		return 0;

	return 1;
}

int
main(void)
{
	assert(valid("12899-OEM-0042134-31009"));
	assert(valid("15795-OEM-0001355-07757"));
	assert(valid("35201-OEM-0009165-64718"));

	assert(!valid("12804-OEM-0033143-31009"));
	assert(!valid("16595-OEM-0001695-9"));
	assert(!valid("12899-OEM-0022134-31009"));
	assert(!valid("27497-OEM-0525347-80387"));
	assert(!valid("27497-JOK-0525347-80387"));

	return 0;
}
