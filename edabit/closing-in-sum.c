/*

Create a function that returns the sum of the digits formed from the first and last digits, all the way to the center of the number.

Worked Example

closingInSum("2520") ➞ 72

// The first and last digits are 2 and 0.
// 2 and 0 form 20.
// The second and second to last digits are 5 and 2.
// 5 and 2 form 52.

// 20 + 52 = 72

Examples

closingInSum("121") ➞ 13
// 11 + 2

closingInSum("1039") ➞ 22
// 19 + 3

closingInSum("22225555") ➞ 100
// 25 + 25 + 25 + 25

Notes

    If the number has an odd number of digits, simply add on the single-digit number in the center (see example #1).
    Any number which is zero-padded counts as a single digit (see example #2).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

unsigned
closingsum(const char *s)
{
	size_t i, n;
	unsigned r;

	n = strlen(s);
	r = 0;
	for (i = 0; i < n / 2; i++)
		r += (s[i] - '0') * 10 + (s[n - i - 1] - '0');
	if (n & 1)
		r += (s[n / 2] - '0');
	return r;
}

int
main(void)
{
	assert(closingsum("10710356439481") == 205);
	assert(closingsum("403672023435605") == 248);
	assert(closingsum("121") == 13);
	assert(closingsum("1039") == 22);
	assert(closingsum("22225555") == 100);
	assert(closingsum("2520") == 72);
	assert(closingsum("5332824166496569") == 331);
	assert(closingsum("72314137318116") == 237);
	assert(closingsum("44013947776") == 160);
	assert(closingsum("378842185820") == 344);
	assert(closingsum("288422776554") == 294);
	assert(closingsum("5000275401986") == 173);
	assert(closingsum("600132227071") == 139);
	assert(closingsum("9703929506546") == 335);
	assert(closingsum("5707454878893") == 327);
	assert(closingsum("9057820232020") == 319);
	assert(closingsum("916905437689753") == 388);
	assert(closingsum("4963792985202586") == 526);
	assert(closingsum("923410871280811") == 298);
	assert(closingsum("9769354257577") == 427);
	assert(closingsum("6227181120333") == 273);
	assert(closingsum("1446833112446") == 281);
	assert(closingsum("12211153605642") == 156);
	assert(closingsum("3414146315434510") == 283);

	return 0;
}
