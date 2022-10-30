/*

In this challenge, you have to mix two or more colors to get a brand new color from their average rgb values.

Each color will be represented in its hexadecimal notation, and so as a string starting with # containing three pairs of alphanumeric characters, equals to the three rgb values (in base 16) of red, green and blue.

To obtain the new color, you need to get the arithmetic average of the sums of the individual red, green and blue values of each given color. When the average is a float number, you have to round it to the nearest integer (rounding up for decimal parts equal to 0.5).

Mixing yellow and red:

Hexadecimal code of yellow = "#FFFF00"
Hexadecimal code of red = "#FF0000"

yellow to RGB = Red: ["FF" = 255], Green: ["FF" = 255], Blue: ["00", 0]
red to RGB = Red: [""FF = 255], Green: ["00" = 0], Blue: ["00" = 0]

Average of Red values = (255 + 255) / 2 = 255
Average of Green values = (255 + 0) / 2 = 127.5 = 128
Average of Blue values = (0 + 0) / 2 = 0 = 0

Rgb of new color = [255, 128, 0]
Hexadecimal conversion = [255 = "FF"], [128 = "80"], [0 = "00"]

New color = "#FF8000" (orange)

Given an array of strings colors containing a series of hexadecimal codes, implement a function that returns the hexadecimal code of the new color, as a new string.
Examples

hexColorMixer(["#FFFF00", "#FF0000"]) ➞ "#FF8000"
// Orange

hexColorMixer(["#FFFF00", "#0000FF"]) ➞ "#808080"
// Medium gray

hexColorMixer(["#B60E73", "#0EAEB6"]) ➞ "#625E95"
// Lavender

Notes

    Remember to round to the nearest integer the average of the rgb values.
    You can test the color codes in any hexadecimal-colors utility site, such as this one that I used for testing cases.
    All the given hexadecimal strings are valid; there are no exceptions to handle.
    If you're interested in rgb colors and their validation, you can give also try this challenge made by @Pustur (open this link in a new tab to avoid issues due to the refresh of the page)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
mixcolor(char *b, size_t n, const char **s, size_t m)
{
	unsigned c[3];
	double r[3];
	size_t i, j;

	memset(r, 0, sizeof(r));
	for (i = 0; i < m; i++) {
		if (sscanf(s[i], "#%02X%02X%02X", &c[0], &c[1], &c[2]) != 3)
			return NULL;

		for (j = 0; j < 3; j++)
			r[j] += c[j];
	}
	for (j = 0; j < 3; j++)
		c[j] = round(r[j] / m);

	snprintf(b, n, "#%02X%02X%02X", c[0], c[1], c[2]);
	return b;
}

void
test(const char **s, size_t m, const char *r)
{
	char b[80];

	mixcolor(b, sizeof(b), s, m);
	assert(strcmp(b, r) == 0);
}

int
main(void)
{
	const char *s1[] = { "#FFFF00", "#FF0000" };
	const char *s2[] = { "#FFFF00", "#0000FF" };
	const char *s3[] = { "#B60E73", "#0EAEB6" };
	const char *s4[] = { "#FF0000", "#00FF00", "#0000FF" };
	const char *s5[] = { "#99CC00", "#663399", "#1A8191" };
	const char *s6[] = { "#918381", "#D53B21", "#A54C83", "#DEFACF" };
	const char *s7[] = { "#140A23", "#46B31E", "#CFDF08", "#263534", "#EAD1FB", "#235E02" };
	const char *s8[] = { "#FFFFFF", "#000000", "#000000", "#FFFFFF" };
	const char *s9[] = { "#CCCCCC" };

	test(s1, nelem(s1), "#FF8000");
	test(s2, nelem(s2), "#808080");
	test(s3, nelem(s3), "#625E95");
	test(s4, nelem(s4), "#555555");
	test(s5, nelem(s5), "#5E8063");
	test(s6, nelem(s6), "#BA817D");
	test(s7, nelem(s7), "#65803F");
	test(s8, nelem(s8), "#808080");
	test(s9, nelem(s9), "#CCCCCC");

	return 0;
}
