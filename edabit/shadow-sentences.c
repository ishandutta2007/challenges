/*

Given two sentences, return whether they are shadows of each other. This means that all of the word lengths are the same, but the corresponding words don't share any common letters.

Examples

shadowSentence("they are round", "fold two times") ➞ true

shadowSentence("own a boat", "buy my wine") ➞ false
// No words share common letters, but "a" and "my" have different lengths.

shadowSentence("his friends", "our company") ➞ false
// Word lengths are the same but "friends" and "company" share the letter "n".

shadowSentence("salmonella supper", "birthright") ➞ false
// Setences with different numbers of words.

Notes

    All sentences will be given in lowercase, and will have no punctuation.
    Return false if the sentences have different numbers of words.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t
skipws(const char *s)
{
	size_t i;

	i = 0;
	while (isspace(s[i]))
		i++;
	return i;
}

size_t
match(const char *s, char h[256], int b, int *f)
{
	size_t i;
	int v;

	for (i = 0; s[i] && !isspace(s[i]); i++) {
		v = s[i] & 0xff;
		h[v] |= b;
		if (h[v] == 3) {
			*f = 1;
			break;
		}
	}
	return i;
}

bool
shadow(const char *s, const char *t)
{
	size_t i, j, n, m;
	char h[256];
	int f;

	for (i = j = 0; s[i] && t[j]; i += n, j += m) {
		i += skipws(s + i);
		j += skipws(t + j);

		memset(h, 0, sizeof(h));
		f = 0;
		n = match(s + i, h, 1, &f);
		m = match(t + j, h, 2, &f);

		if (n != m || f)
			return false;
	}
	return !s[i] && !t[j];
}

int
main(void)
{
	assert(shadow("they are round", "fold two times") == true);
	assert(shadow("impossible poetry", "gargantuan cliffs") == true);
	assert(shadow("seemingly unlimited", "cutthroat crossbows") == true);
	assert(shadow("empty cookie jar", "adorn fluffy wig") == true);

	assert(shadow("own a boat", "buy my wine") == false);
	assert(shadow("his friends", "our company") == false);
	assert(shadow("a normal sentence", "a normal sentence") == false);
	assert(shadow("salmonella supper", "birthright") == false);

	return 0;
}
