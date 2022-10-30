/*

Virtually every single book, play, movie, novel, and game has at least one character.
Most have more, and some even have thousands! As every good writer knows, the difficulty of creating a character increases with each new major character added.
This is because fictional characters are truly developed through their relationships with others.

If there are no characters or only one character, no relationships need to be explored.
With two characters, there is one relationship. If there are three characters, however, there are four relationships:
the ones between each pair of characters, and finally the relationship when all three are together.
In general, the relationship between all subsets of at least two characters must be explored.

Given a literary work with N characters, how many relationships need to be explored?

Input

The input contains a single integer, N (0≤N≤30), the number of characters.

Output

Output a single line with the number of relationships that need to be explored.

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
relationships(uvlong n)
{
	uvlong i, r;

	r = 0;
	for (i = 2; i <= n; i++)
		r += (1ull << (i - 1)) - 1;
	return r;
}

int
main(void)
{
	assert(relationships(1) == 0);
	assert(relationships(3) == 4);

	return 0;
}
