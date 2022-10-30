/*

Taken straight from the ACM Winter Programming Contest 2013. You are a person who likes to take things literally. Therefore, for you, the end of The World is ed; the last letters of "The" and "World" concatenated.

Make a program which takes a sentence, and output the last letter of each word in that sentence in as little space as possible (fewest bytes).
Words are separated with anything but letters from the alphabet (65 - 90, 97 - 122 on the ASCII table.) That means underscores, tildes, graves, curly braces, etc. are separators.
There can be more than one seperator between each word.

asdf jkl;__zxcv~< vbnm,.qwer| |uiop -> flvmrp
pigs, eat dogs; eat Bob: eat pigs -> ststbts
looc si siht ,gnitirw esreveR -> citwR
99_bottles_of_beer_on_the_wall -> sfrnel

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
isletter(int c)
{
	c = tolower(c);
	return ('a' <= c && c <= 'z');
}

char *
end(const char *s, char *b)
{
	size_t i, j;
	int c;

	c = 0;
	for (i = j = 0; s[i]; i++) {
		if (isletter(s[i]))
			c = s[i];
		else if (c) {
			b[j++] = c;
			c = 0;
		}
	}
	if (c)
		b[j++] = c;
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	end(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("asdf jkl;__zxcv~< vbnm,.qwer| |uiop", "flvmrp");
	test("pigs, eat dogs; eat Bob: eat pigs", "ststbts");
	test("looc si siht ,gnitirw esreveR", "citwR");
	test("99_bottles_of_beer_on_the_wall", "sfrnel");

	return 0;
}
