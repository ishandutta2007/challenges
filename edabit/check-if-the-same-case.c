/*

Create a function that returns true if an input string contains only uppercase or only lowercase letters.
Examples

SameCase("hello") ➞ true

SameCase("HELLO") ➞ true

SameCase("Hello") ➞ false

SameCase("ketcHUp") ➞ false

Notes

N/A

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool
samecase(const char *s)
{
	size_t i;
	int l;

	l = islower(s[0]);
	for (i = 0; s[i]; i++) {
		if (l != islower(s[i]))
			return false;
	}
	return true;
}

int
main(void)
{
	assert(samecase("hello") == true);
	assert(samecase("HELLO") == true);
	assert(samecase("Hello") == false);
	assert(samecase("ketcHUp") == false);
	assert(samecase("mArmALadE") == false);
	assert(samecase("marmalade") == true);
	assert(samecase("MARMALADE") == true);
	assert(samecase("ketchUP") == false);
	assert(samecase("pickle") == true);
	assert(samecase("MUSTARD") == true);

	return 0;
}
