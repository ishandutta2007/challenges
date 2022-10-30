/*


Your task is to write a program that will output a readable list of every five letter words with the structure:

consonant - vowel - consonant - vowel - consonant

The output should be sorted alphabetically with one word per line and no words repeated twice. It can be lowercase or uppercase but not mixed. So the list could start and end like this:

babab
babac
babad
...
zyzyw
zyzyx
zyzyz
Vowels are a-e-i-o-u-y, the other 20 English-alphabet letters are consonants.
Words don't have to be actual dictionary words.
Shortest code wins.

Note: A few years ago I stumbled upon a program on a university website that did exactly that. Turns out my first and last name fit the c-v-c-v-c constraint, and i'd been googling myself.

*/

#include <stdio.h>
#include <string.h>

int
isvowel(int c)
{
	return strchr("aeiouy", c) != NULL;
}

void
gen(int i, int n, char *b)
{
	int c;

	if (i >= n) {
		b[i] = '\0';
		printf("%s\n", b);
		return;
	}

	for (c = 'a'; c <= 'z'; c++) {
		if ((i & 1) != isvowel(c))
			continue;

		b[i] = c;
		gen(i + 1, n, b);
	}
}

int
main(void)
{
	char b[16];

	gen(0, 5, b);
	return 0;
}
