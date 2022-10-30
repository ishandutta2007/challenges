/*

In this challenge, you have to find the numeric value of a given word.
Instead of the usual sum of Unicode values, you have to convert the whole word into a decimal number from a base equal to ten plus the position in the alphabet of the "highest" letter of the word (counting from a = 1 to z = 26).

Given a word, implement a function that returns an integer being the decimal value obtained after the conversion from the word specific base, accordingly to the instructions above.
Examples

wordToDecimal("Edabit") ➞ 351010469
// The highest letter of "Edabit" in the alphabet is "T"
// "T" is the 20th letter of the alphabet: adding 10 the result is 30
// "Edabit" in base-30 is equal to 351010469 in base-10

wordToDecimal("JavaScript") ➞ 680575028284221
// The highest letter of "JavaScript" in the alphabet is "v"
// "v" is the 22th letter of the alphabet: adding 10 the result is 32
// "JavaScript" in base-32 is equal to 680575028284221 in base-10

wordToDecimal("ZERO") ➞ 1652100
// The highest letter of "ZERO" in the alphabet is "Z"
// "Z" is the 26th letter of the alphabet: adding 10 the result is 36
// "ZERO" in base-36 is equal to 1652100 in base-10

Notes

    The bases that accept letters in their representation are those starting from 11 (using 10 digits and 1 letter) up to 36 (using 10 digits and 26 letters).
    JS Note: This challenge is thinked and designed to avoid results bigger than the max safe integer representable in JS, so that the BigInt() method will be not necessary to pass it.
    Every given word will be a valid one made of just letters, either lowercased or uppercased.

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef unsigned long long uvlong;

uvlong
basechar(const char *s)
{
	size_t i;
	int b, c;

	b = 0;
	for (i = 0; s[i]; i++) {
		c = tolower(s[i]);
		if ('a' <= c && c <= 'z')
			b = max(b, c - 'a' + 1);
	}
	return 10 + b;
}

uvlong
word2dec(const char *s)
{
	uvlong b, r;
	size_t i;
	int c;

	b = basechar(s);
	r = 0;
	for (i = 0; s[i]; i++) {
		c = tolower(s[i]);
		if ('a' <= c && c <= 'z')
			c = c - 'a' + 10;
		else
			c = 0;

		r = (r * b) + c;
	}
	return r;
}

int
main(void)
{
	assert(word2dec("Edabit") == 351010469ull);
	assert(word2dec("JavaScript") == 680575028284221ull);
	assert(word2dec("ZERO") == 1652100ull);
	assert(word2dec("oNe") == 15589ull);
	assert(word2dec("TwO") == 32661ull);
	assert(word2dec("THRee") == 23973734ull);
	assert(word2dec("Four") == 470886ull);
	assert(word2dec("fIVe") == 510958ull);
	assert(word2dec("SIx") == 33013ull);
	assert(word2dec("seven") == 29851095ull);
	assert(word2dec("eigHt") == 11840939ull);

	return 0;
}
