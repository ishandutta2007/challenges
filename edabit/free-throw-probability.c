/*

What's the probability of someone making a certain amount of free throws in a row given their free throw success percentage?
If Sally makes 50% of her free shot throws. Then Sally's probability of making 5 in a row would be 3%.

Examples

freeThrows(75%, 5) ➞ 24%

freeThrows(25%, 3) ➞ 2%

freeThrows(90%, 30) ➞ 4%

Notes

    The success rate is a string.
    The function should return a string with the percent sign.
    Round your answer to the nearest whole number.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *
freethrows(const char *s, unsigned t, char *b, size_t n)
{
	unsigned p;

	if (sscanf(s, "%u%%", &p) != 1)
		return NULL;

	snprintf(b, n, "%.0f%%", pow(p * 1.0 / 100, t) * 100);
	return b;
}

int
main(void)
{
	char b[80];

	assert(!strcmp(freethrows("50%", 5, b, sizeof(b)), "3%"));
	assert(!strcmp(freethrows("75%", 10, b, sizeof(b)), "6%"));
	assert(!strcmp(freethrows("25%", 3, b, sizeof(b)), "2%"));
	assert(!strcmp(freethrows("90%", 30, b, sizeof(b)), "4%"));
	assert(!strcmp(freethrows("1%", 0, b, sizeof(b)), "100%"));

	return 0;
}
