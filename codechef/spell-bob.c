/*

Chef likes to play with cards a lot. Today, he's playing a game with three cards.
Each card has a letter written on the top face and another (possibly identical) letter written on the bottom face.
Chef can arbitrarily reorder the cards and/or flip any of the cards in any way he wishes (in particular, he can leave the cards as they were).
He wants to do it in such a way that the letters on the top faces of the cards, read left to right, would spell out the name of his favorite friend Bob.

Determine whether it is possible for Chef to spell "bob" with these cards.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single string with length 3 denoting the characters written on the top faces of the first, second and third card.
The second line contains a single string with length 3 denoting the characters written on the bottom faces of the first, second and third card.

Output

For each test case, print a single line containing the string "yes" (without quotes) if Chef can spell "bob" or "no" (without quotes) if he cannot.

Constraints
1≤T≤20,000
each string contains only lowercase English letters

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool
bob(const char s[4], const char t[4])
{
	int b, o;
	int i, j;
	int c;

	for (i = 0; i < 8; i++) {
		b = o = 0;
		for (j = 0; j < 3; j++) {
			c = (i & (1 << j)) ? s[j] : t[j];
			c = tolower(c);
			b += (c == 'b');
			o += (c == 'o');
		}
		if (b >= 2 && o >= 1)
			return true;
	}

	return false;
}

int
main(void)
{
	assert(bob("bob", "rob") == true);
	assert(bob("dbc", "ocb") == true);
	assert(bob("boc", "obc") == false);

	return 0;
}
