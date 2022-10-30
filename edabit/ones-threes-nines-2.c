/*

Given an integer between 0 and 26, make a variable (self.answer). That variable would be assigned to a string in this format:

"nines:your answer, threes:your answer, ones:your answer"

You need to find out how many ones, threes, and nines it would at least take for the number of each to add up to the given integer when multiplied by one, three or nine (depends).
Examples

ones_threes_nines(10) ➞ "nines:1, threes:0, ones:1"

ones_threes_nines(15) ➞ "nines:1, threes:2, ones:0"

ones_threes_nines(22) ➞ "nines:2, threes:1, ones:1"

Notes

    Each of the ones, threes or nines could only be either 0, 1 or 2.
    You must use a class.
    After the comma, you must put a space.
    See version #1 of this series.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
ones_threes_nines(int x, char *b)
{
	int r[3];

	memset(r, 0, sizeof(r));
	if (x >= 9) {
		r[0] = x / 9;
		x %= 9;
	}
	if (x >= 3) {
		r[1] = x / 3;
		x %= 3;
	}
	r[2] = x;
	sprintf(b, "nines:%d, threes:%d, ones:%d", r[0], r[1], r[2]);
	return b;
}

int
main(void)
{
	char b[80];

	assert(!strcmp(ones_threes_nines(1, b), "nines:0, threes:0, ones:1"));
	assert(!strcmp(ones_threes_nines(5, b), "nines:0, threes:1, ones:2"));
	assert(!strcmp(ones_threes_nines(7, b), "nines:0, threes:2, ones:1"));
	assert(!strcmp(ones_threes_nines(10, b), "nines:1, threes:0, ones:1"));
	assert(!strcmp(ones_threes_nines(12, b), "nines:1, threes:1, ones:0"));
	assert(!strcmp(ones_threes_nines(15, b), "nines:1, threes:2, ones:0"));
	assert(!strcmp(ones_threes_nines(22, b), "nines:2, threes:1, ones:1"));
	assert(!strcmp(ones_threes_nines(25, b), "nines:2, threes:2, ones:1"));

	return 0;
}
