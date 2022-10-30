/*

In BlackJack, cards are counted with -1, 0, 1 values:

    2, 3, 4, 5, 6 are counted as +1
    7, 8, 9 are counted as 0
    10, J, Q, K, A are counted as -1

Create a function that counts the number and returns it from the array of cards provided.

Notes

    String inputs will always be upper case.
    You do not need to consider case sensitivity.
    If the argument is empty, return 0.
    No input other than: 2, 3, 4, 5, 6, 7, 8, 9, 10, "J", "Q", "K", "A".

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cardcount(char *s, size_t n)
{
	size_t i;
	char c;
	int v;

	v = 0;
	for (i = 0; i < n; i++) {
		c = toupper(s[i]);
		if (2 <= c && c <= 6)
			v++;
		else if (c == 10 || strchr("JQKA", c))
			v--;
	}

	return v;
}

int
main(void)
{
	char c1[] = { 5, 9, 10, 3, 'J', 'A', 4, 8, 5 };
	char c2[] = { 'A', 'A', 'K', 'Q', 'Q', 'J' };
	char c3[] = { 'A', 5, 5, 2, 6, 2, 3, 8, 9, 7 };
	char c4[] = { 2, 2, 2, 2, 2, 2, 2, 2 };
	char c5[] = { 'A', 'A', 'A', 'A', 'A', 'A', 'A' };
	char c6[] = { 'A', 'K', 'Q', 'J', 10, 9, 8, 7, 6, 5, 4, 3, 2 };

	assert(cardcount(c1, nelem(c1)) == 1);
	assert(cardcount(c2, nelem(c2)) == -6);
	assert(cardcount(c3, nelem(c3)) == 5);
	assert(cardcount(c4, nelem(c4)) == 8);
	assert(cardcount(c4, 0) == 0);
	assert(cardcount(c5, nelem(c5)) == -7);
	assert(cardcount(c6, nelem(c6)) == 0);

	return 0;
}
