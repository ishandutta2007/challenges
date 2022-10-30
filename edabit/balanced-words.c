/*

We can assign a value to each character in a word, based on their position in the alphabet (a = 1, b = 2, ... , z = 26). A balanced word is one where the sum of values on the left-hand side of the word equals the sum of values on the right-hand side. For odd length words, the middle character (balance point) is ignored.

Write a function that returns true if the word is balanced, and false if it's not.
Examples

balanced("zips") ➞ true
// "zips" = "zi|ps" = 26+9|16+19 = 35|35 = true

balanced("brake") ➞ false
// "brake" = "br|ke" = 2+18|11+5 = 20|16 = false

Notes

    All words will be lowercase, and have a minimum of 2 characters.
    Palindromic words will always be balanced.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
balanced(const char *s)
{
	unsigned x, y;
	size_t i, l;

	x = y = 0;
	l = strlen(s);
	for (i = 0; i < l / 2; i++)
		x += s[i];
	for (i = l / 2 + (l & 1); i < l; i++)
		y += s[i];

	return x == y;
}

int
main(void)
{
	assert(balanced("") == 1);
	assert(balanced("a") == 1);
	assert(balanced("zips") == 1);
	assert(balanced("brake") == 0);
	assert(balanced("at") == 0);
	assert(balanced("forgetful") == 0);
	assert(balanced("vegetation") == 1);
	assert(balanced("disillusioned") == 0);
	assert(balanced("abstract") == 1);
	assert(balanced("clever") == 0);
	assert(balanced("conditionalities") == 1);
	assert(balanced("seasoning") == 1);
	assert(balanced("uptight") == 0);
	assert(balanced("ticket") == 0);
	assert(balanced("calculate") == 0);
	assert(balanced("measure") == 0);
	assert(balanced("join") == 0);
	assert(balanced("anesthesiologies") == 1);
	assert(balanced("command") == 0);
	assert(balanced("graphite") == 1);
	assert(balanced("quadratically") == 1);
	assert(balanced("right") == 0);
	assert(balanced("fossil") == 1);
	assert(balanced("sparkling") == 0);
	assert(balanced("dolphin") == 1);
	assert(balanced("baseball") == 1);
	assert(balanced("immense") == 0);
	assert(balanced("pattern") == 1);
	assert(balanced("hand") == 0);
	assert(balanced("radar") == 1);
	assert(balanced("oven") == 0);
	assert(balanced("immutability") == 1);
	assert(balanced("kayak") == 1);
	assert(balanced("bartender") == 1);
	assert(balanced("weight") == 0);
	assert(balanced("lightbulbs") == 1);
	assert(balanced("tail") == 1);

	return 0;
}
