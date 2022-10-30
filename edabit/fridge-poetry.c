/*

Write a function that returns true if it's possible to build a phrase s1 using only the characters from another phrase s2.
Examples

canBuild("got 2 go", "gogogo 2 today") ➞ true

canBuild("sit on top", "its a moo point") ➞ true

canBuild("long high add or", "highway road go long") ➞ false

canBuild("fill tuck mid", "truck falls dim") ➞ false

Notes

    All letters will be in lower case.
    Numbers and special characters included.
    Ignore whitespaces.
    Do not count white space as a character.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool
canbuild(const char *s, const char *t)
{
	size_t i, h[2][256];

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[0][s[i] & 0xff]++;
	for (i = 0; t[i]; i++)
		h[1][t[i] & 0xff]++;

	for (i = 0; i < 256; i++) {
		if (h[1][i] < h[0][i] && !isspace(i))
			return false;
	}
	return true;
}

int
main(void)
{
	assert(canbuild("got 2 go", "go go go 2 today") == true);
	assert(canbuild("for an angel", "angel forest nymph awaken") == true);
	assert(canbuild("sit on top", "its a moo point") == true);
	assert(canbuild("solar to oven", "love desolate rose thorn") == true);
	assert(canbuild("gate im in", "magnetizing") == true);
	assert(canbuild("moreso", "mount rushmore") == true);
	assert(canbuild("dool", "ken doll") == false);
	assert(canbuild("world of make believe", "make believe world") == false);
	assert(canbuild("long high add or", "highway road go long") == false);
	assert(canbuild("fill tuck mid", "truck falls dim") == false);
	assert(canbuild("skin man i", "man in mask") == false);
	assert(canbuild("foolish prides", "foolish pride") == false);

	return 0;
}
