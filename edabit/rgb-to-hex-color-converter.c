/*

Create a function that converts color in RGB format to Hex format.
Examples

rgbToHex("rgb(0, 128, 192)") ➞ "#0080c0"

rgbToHex("rgb(45, 255, 192)") ➞ "#2dffc0"

rgbToHex("rgb(0, 0, 0)") ➞ "#000000"

Notes

The Hex format should be displayed in lowercase.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
rgb2hex(const char *s, char *b, size_t n)
{
	int i, c[3];

	if (sscanf(s, "rgb(%d, %d, %d)", &c[0], &c[1], &c[2]) != 3)
		return NULL;
	for (i = 0; i < 3; i++) {
		if (!(0 <= c[i] && c[i] <= 255))
			return NULL;
	}

	snprintf(b, n, "#%02x%02x%02x", c[0], c[1], c[2]);
	return b;
}

void
test(const char *s, const char *t)
{
	char b[80];

	rgb2hex(s, b, sizeof(b));
	assert(strcmp(b, t) == 0);
}

int
main(void)
{
	test("rgb(0, 128, 192)", "#0080c0");
	test("rgb(45, 255, 192)", "#2dffc0");
	test("rgb(255, 255, 255)", "#ffffff");
	test("rgb(192, 192, 192)", "#c0c0c0");
	test("rgb(255, 0, 0)", "#ff0000");
	test("rgb(0, 0, 255)", "#0000ff");
	test("rgb(0, 0, 0)", "#000000");
	test("rgb(11, 12, 13)", "#0b0c0d");

	return 0;
}
