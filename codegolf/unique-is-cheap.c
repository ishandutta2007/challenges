/*

Write a function or program that determines the cost of a given string, where

    the cost of each character equals the number of how many times the character has occurred up to this point in the string, and
    the cost of the string is the sum of its characters' costs.

Example

For an input of abaacab, the cost is computed as follows:

a b a a c a b
1   2 3   4    occurrence of a
  1         2  occurrence of b
        1      occurrence of c
1+1+2+3+1+4+2 = 14

Thus the cost for the string abaacab is 14.
Rules

    The score of your submission is the cost of your code as defined above, that is your submission run on its own source code, with a lower score being better.
    Your submission should work on strings containing printable ASCII-characters, plus all characters used in your submission.
    Characters are case-sensitive, that is a and A are different characters.

Testcases

input -> output
"abaacab" -> 14
"Programming Puzzles & Code Golf" -> 47
"" -> 0
"       " -> 28
"abcdefg" -> 7
"aA" -> 2

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

unsigned
cost(const char *s)
{
	size_t h[256], i;
	unsigned c;

	memset(h, 0, sizeof(h));
	for (c = i = 0; s[i]; i++)
		c += ++h[s[i] & 0xff];
	return c;
}

int
main(void)
{
	assert(cost("abaacab") == 14);
	assert(cost("Programming Puzzles & Code Golf") == 47);
	assert(cost("") == 0);
	assert(cost("       ") == 28);
	assert(cost("abcdefg") == 7);
	assert(cost("aA") == 2);

	return 0;
}
