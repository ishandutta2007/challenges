/*

A barcode of EAN-13 symbology consists of 13 digits (0-9). The last digit of this barcode is its check digit. It is calculated by the following means (the barcode 8923642469559 is used as an example):

    Starting from the second digit, sum up all alternating digits and multiply the sum by 3:

    8 9 2 3 6 4 2 4 6 9 5 5 9
      |   |   |   |   |   |
      9 + 3 + 4 + 4 + 9 + 5 = 34
                               |
                               34 × 3 = 102

    Then, sum up all of the remaining digits, but do not include the last digit:

    8 9 2 3 6 4 2 4 6 9 5 5 9
    |   |   |   |   |   |
    8 + 2 + 6 + 2 + 6 + 5 = 29

    Add the numbers obtained in steps 1 and 2 together:

    29 + 102 = 131

    The number you should add to the result of step 3 to get to the next multiple of 10 (140 in this case) is the check digit.

If the check digit of the barcode matches the one calculated as explained earlier, the barcode is valid.

More examples:

6537263729385 is valid. 1902956847427 is valid. 9346735877246 is invalid. The check digit should be 3, not 6.

Your goal is to write a program that will:

    Receive a barcode as its input.
    Check whether the barcode is valid
    Return 1 (or equivalent) if the barcode is valid, 0 (or equivalent) otherwise.

This is code-golf, so the shortest code in terms of bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int
roundup(int x, int m)
{
	return (x + (m - 1)) / m * m;
}

int
isean13(const char *s)
{
	int a, b, c, d;
	size_t i, n;

	for (n = 0; s[n] && n < 14; n++) {
		if (isdigit(!s[n]))
			return 0;
	}
	if (n != 13)
		return 0;

	a = b = 0;
	for (i = 0; i < n - 1; i += 2) {
		a += s[i + 1] - '0';
		b += s[i] - '0';
	}

	c = (a * 3) + b;
	d = roundup(c, 10) - c;
	return (d == s[n - 1] - '0');
}

int
main(void)
{
	assert(isean13("8923642469559") == 1);
	assert(isean13("6537263729385") == 1);
	assert(isean13("1902956847427") == 1);
	assert(isean13("9346735877246") == 0);

	return 0;
}
