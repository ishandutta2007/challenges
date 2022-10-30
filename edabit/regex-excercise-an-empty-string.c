/*

If you've completed this RegEx series from I to XXII then you have been exposed to all of MDN's documentation on regular expressions special characters. You can check my Collections under Basic Reg Ex in my profile if you missed any. This next part of the series is to help solidify what you've learned. In order to save time I will be searching the web to find regular expression exercises to post here.

You can test for empty string like this:

"".length === 0 ➞ true

Use a regular expression to test for an empty string.

const REGEXP = /your solution/
REGEXP.test("") ➞ true

Notes

You can find the solution in the Resources tab.

*/

#include <stdio.h>
#include <assert.h>
#include <regex.h>

int
isempty(const char *s)
{
	regex_t re;
	regmatch_t m;
	int r;

	if (regcomp(&re, "^$", 0) != 0)
		return -1;
	r = regexec(&re, s, 1, &m, 0);
	regfree(&re);
	return r == 0;
}

int
main(void)
{
	assert(isempty("") == 1);
	assert(isempty("z") == 0);
	assert(isempty("a") == 0);
	assert(isempty("v") == 0);
	assert(isempty("$|10!#_!EA") == 0);
	assert(isempty("&*()_\\") == 0);
	assert(isempty("^$") == 0);
	assert(isempty("a") == 0);

	return 0;
}
