/*

Syncopation means an emphasis on a weak beat of a bar of music; most commonly, beats 2 and 4 (and all other even-numbered beats if applicable).

s is a line of music, represented as a string, where hashtags # represent emphasized beats. Create a function that returns if the line of music contains any syncopation.
Examples

hasSyncopation(".#.#.#.#") ➞ true

hasSyncopation("#.#...#.") ➞ false

hasSyncopation("#.#.###.") ➞ true

Notes

All other unemphasized beats will be represented as a dot.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
syncopation(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] == '#' && (i & 1))
			return true;
	}
	return false;
}

int
main(void)
{
	assert(syncopation(".#.#.#.#") == true);
	assert(syncopation("#.#...#.") == false);
	assert(syncopation("#.#.###.") == true);
	assert(syncopation("..") == false);
	assert(syncopation("") == false);
	assert(syncopation("##") == true);
	assert(syncopation("####....") == true);
	assert(syncopation("#") == false);
	assert(syncopation(".#.#....") == true);
	assert(syncopation(".#.#") == true);
	assert(syncopation(".#.") == true);
	assert(syncopation("#.") == false);
	assert(syncopation(".#") == true);

	return 0;
}
