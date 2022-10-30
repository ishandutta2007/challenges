/*

Write a function that returns the minimum number of swaps to convert the first binary string into the second.

Notes

    Both binary strings will be of equal length.
    Both binary strings will have an equal number of zeroes and ones.
    A swap is switching two elements in a string (swaps do not have to be adjacent).

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>

ssize_t
minswaps(const char *a, const char *b)
{
	size_t i, p[4];
	ssize_t c;

	memset(p, 0, sizeof(p));
	c = 0;
	for (i = 0; a[i] && b[i]; i++) {
		c += (a[i] != b[i]);
		p[0] += (a[i] == '0');
		p[1] += (a[i] == '1');
		p[2] += (b[i] == '0');
		p[3] += (b[i] == '1');
	}

	if (p[0] != p[2] || p[1] != p[3])
		return -1;
	if (p[0] + p[1] != i || p[2] + p[3] != i)
		return -1;
	if (a[i] != '\0' || b[i] != '\0')
		return -1;

	return c / 2;
}

int
main(void)
{
	assert(minswaps("1001", "1001") == 0);
	assert(minswaps("1100", "1001") == 1);
	assert(minswaps("110011", "010111") == 1);
	assert(minswaps("1100", "0011") == 2);
	assert(minswaps("110011", "001111") == 2);
	assert(minswaps("10011001", "01100101") == 3);
	assert(minswaps("11111000001100", "10110010100110") == 3);
	assert(minswaps("01100100100111", "10110010100110") == 3);
	assert(minswaps("11110011001", "01100110111") == 3);
	assert(minswaps("100110001", "010100110") == 3);
	assert(minswaps("100101011", "011001101") == 3);
	assert(minswaps("10011001", "01100110") == 4);
	return 0;
}
