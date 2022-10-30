/*

Given a string consisting of only upper and lower case letters, output an if it begins with a vowel, and a if not.
For the purposes of this challenge, we'll ignore normal grammar rules, and use a very basic rule instead: if the input begins with a vowel (any of AEIOUaeiou), then output an.
Otherwise, output a.

Your program should be case insensitive (computer and CoMpUtER are the same). This is code-golf, so the shortest code in bytes wins
Test cases

airplane: an
water: a
snake: a
hybrid: a
igloo: an
WATER: a
IglOO: an
HoUr: a
unIverSe: an
youTH: a

Note that for the last 3, they contradict typical grammar rules, in favour of our simplified rule, and that y is not counted as a vowel

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
ana(const char *s)
{
	if (strchr("AEIOUaeiou", s[0]))
		return "an";
	return "a";
}

int
main(void)
{
	assert(!strcmp(ana("airplane"), "an"));
	assert(!strcmp(ana("water"), "a"));
	assert(!strcmp(ana("snake"), "a"));
	assert(!strcmp(ana("hybrid"), "a"));
	assert(!strcmp(ana("igloo"), "an"));
	assert(!strcmp(ana("WATER"), "a"));
	assert(!strcmp(ana("IglOO"), "an"));
	assert(!strcmp(ana("HoUr"), "a"));
	assert(!strcmp(ana("unIverSe"), "an"));
	assert(!strcmp(ana("youTH"), "a"));

	return 0;
}
