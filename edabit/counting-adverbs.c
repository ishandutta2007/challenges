/*

Create a function that counts the number of adverbs in a sentence. An adverb is a word that ends with ly.
Examples

countAdverbs("She ran hurriedly towards the stadium.") ➞ 1

countAdverbs("She ate the lasagna heartily and noisily.") ➞ 2

countAdverbs("He hates potatoes.") ➞ 0

countAdverbs("He was happily, crazily, foolishly over the moon.") ➞ 3

Notes

    Do NOT count words where the ly is in the beginning or the middle (e.g. Lysol, Illya).
    For the purpose of this exercise, ignore the nuances of the English language (some adjectives also end in ly).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t
countadverbs(const char *s)
{
	const char *p;
	size_t c;

	c = 0;
	for (p = s; *p; p += 2) {
		p = strstr(p, "ly");
		if (!p)
			break;
		if (isspace(p[2]) || ispunct(p[2]) || p[2] == '\0')
			c++;
	}
	return c;
}

int
main(void)
{
	assert(countadverbs("She ran hurriedly towards the stadium.") == 1);
	assert(countadverbs("She ate the lasagna heartily and noisily.") == 2);
	assert(countadverbs("He hates potatoes.") == 0);
	assert(countadverbs("He was happily, crazily, foolishly over the moon.") == 3);
	assert(countadverbs("She writes poetry beautifully.") == 1);
	assert(countadverbs("There are many fat geese in the park.") == 0);
	assert(countadverbs("The horse acted aggressively and stubbornly.") == 2);
	assert(countadverbs("She forgot where to buy the lysol.") == 0);
	assert(countadverbs("Ilya ran to the store.") == 0);

	return 0;
}
