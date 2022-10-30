/*

Mathison recently inherited an ancient papyrus that contained some text. Unfortunately, the text was not a PANGRAM.
Now, Mathison has a particular liking for holoalphabetic strings and the text bothers him.
The good news is that Mathison can buy letters from the local store in order to turn his text into a pangram.

However, each letter has a price and Mathison is not very rich. Can you help Mathison find the cheapest way to obtain a pangram?

Input

The first line of the input file will contain one integer, T, representing the number of tests.

Each test will be formed from two lines. The first one contains 26 space-separated integers, representing the prices of all letters.
The second will contain Mathison's initial text (a string of N lowercase letters).

Output

The output file will contain T lines, one for each test. Each line will contain the answer for the corresponding test.

Constraints and notes
1 ≤ T ≤ 10
1 ≤ N ≤ 50,000
All prices are natural numbers between 1 and 1,000,000 (i.e. 106).
A pangram is a string that contains every letter of the Latin alphabet at least once.
All purchased letters are added to the end of the string.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
cost(int c[26], const char *s)
{
	size_t h[26];
	size_t i;
	int p, r;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++) {
		p = s[i] - 'a';
		if (0 <= p && p < 26)
			h[p]++;
	}

	r = 0;
	for (i = 0; i < 26; i++) {
		if (!h[i])
			r += c[i];
	}
	return r;
}

int
main(void)
{
	int c1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
	const char *s1 = "abcdefghijklmopqrstuvwz";

	const char *s2 = "thequickbrownfoxjumpsoverthelazydog";

	assert(cost(c1, s1) == 63);
	assert(cost(c1, s2) == 0);

	return 0;
}
