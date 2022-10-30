/*

A string S is called Chef's favourite if every substring chef in S must have a substring code before it.

You are given a string S of size N that contains both code and chef as a substring. Please determine if S is Chef's favourite.

Note: A substring is a continuous part of string which can be obtained by deleting some (may be none) character's from the beginning and some (may be none) character's from the end.

Input Format

The first line of the input contains an integer T - the number of test cases. The test cases then follow.
The first line of each test contains an integer N - the size of the string.
The second line of each test contains a string S.

Output Format

For each test case, output on a single line AC if S is Chef's favourite, or WA otherwise.

Constraints
1≤T≤10
1≤N≤10^4
|S|=N
S consists only of lowercase English characters
Both code and chef appear as a substring at least once in S

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
favorite(const char *s)
{
	size_t i;

	for (i = 0; s[i] && s[i + 1] && s[i + 2] && s[i + 3]; i++) {
		if (!strncmp(s + i, "code", 4))
			return "AC";
		if (!strncmp(s + i, "chef", 4))
			return "WA";
	}
	return "WA";
}

int
main(void)
{
	assert(!strcmp(favorite("codechef"), "AC"));
	assert(!strcmp(favorite("chefcode"), "WA"));
	assert(!strcmp(favorite("sxycodeghychef"), "AC"));
	assert(!strcmp(favorite("sxychefvsvcodehghchef"), "WA"));

	return 0;
}
