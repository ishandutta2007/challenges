/*

There are 5 cities in the country.

The map of the country is given below.

The tour starts from the red city.

Smiley face

Each road is associated with a character.

Initially, there is an empty string.

Every time a road has been travelled the character associated gets appended to the string.

At the green city either the string can be printed or the tour can be continued.

In the problem, you are given a string tell whether it is possible to print the string while following the rules of the country?

Input:

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains a single line of input, a string s. The string consists only of 0′s and 1′s.

Output:

For each testcase, output "YES" or "NO" depending on the input.

Constraints
1≤T≤10000
1≤lengthofeachstring≤10000
1≤Summationlength≤10^5

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
printable(const char *s)
{
	static const int tab[6][2] = {
	    {0, 0},
	    {1, 2},
	    {3, 2},
	    {4, 2},
	    {5, 2},
	    {1, 2},
	};

	size_t i;
	int c;

	c = 1;
	for (i = 0; s[i]; i++) {
		if (s[i] != '0' && s[i] != '1')
			return false;

		c = tab[c][s[i] - '0'];
	}
	return c == 5;
}

int
main(void)
{
	assert(printable("100") == false);

	return 0;
}
