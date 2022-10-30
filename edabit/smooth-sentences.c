/*

Carlos is a huge fan of something he calls smooth sentences. A smooth sentence is one where the last letter of each word is identical to the first letter the following word.

To illustrate, the following would be a smooth sentence: "Carlos swam masterfully."

Since "Carlos" ends with an "s" and swam begins with an "s" and swam ends with an "m" and masterfully begins with an "m".
Examples

IsSmooth("Marta appreciated deep perpendicular right trapezoids") ➞ true

IsSmooth("Someone is outside the doorway") ➞ false

IsSmooth("She eats super righteously") ➞ true

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool
isletter(int c)
{
	return isalpha(c);
}

bool
issmooth(const char *s)
{
	size_t i;
	int c;

	c = -1;
	for (i = 0; s[i];) {
		while (!isletter(s[i]))
			i++;

		if (c > 0 && tolower(c) != tolower(s[i]))
			return false;

		while (isletter(s[i]))
			c = s[i++];
	}

	return true;
}

int
main(void)
{
	assert(issmooth("Marta appreciated deep perpendicular right trapezoids") == true);
	assert(issmooth("Someone is outside the doorway") == false);
	assert(issmooth("She eats super righteously") == true);
	assert(issmooth("Ben naps so often") == true);
	assert(issmooth("Cute triangles are cute") == false);
	assert(issmooth("Mad dislikes sharp pointy yoyos") == true);
	assert(issmooth("Rita asks Sam mean numbered dilemmas") == true);
	assert(issmooth("Marigold daffodils streaming happily.") == false);
	assert(issmooth("Simply wonderful laughing.") == false);

	return 0;
}
