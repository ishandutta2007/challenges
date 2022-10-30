/*

Create a function that takes a string and returns the sum of vowels, where some vowels are considered numbers.
Vowel	Number
A	4
E	3
I	1
O	0
Examples

sumOfVowels("Let\'s test this function.") ➞ 8

sumOfVowels("Do I get the correct output?") ➞ 10

sumOfVowels("I love edabit!") ➞ 12

Notes

Vowels are case-insensitive (e.g. A = 4 and a = 4).

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

unsigned
sumvowels(const char *s)
{
	unsigned r;
	size_t i;

	r = 0;
	for (i = 0; s[i]; i++) {
		switch (tolower(s[i])) {
		case 'a':
			r += 4;
			break;
		case 'e':
			r += 3;
			break;
		case 'i':
			r += 1;
			break;
		}
	}
	return r;
}

int
main(void)
{
	assert(sumvowels("Let\'s test this function.") == 8);
	assert(sumvowels("Do I get the correct output?") == 10);
	assert(sumvowels("I love edabit!") == 12);
	assert(sumvowels("Will you still need me, will you still feed me when I\'m 64?") == 26);
	assert(sumvowels("The greatest glory in living lies not in never falling, but in rising every time we fall.") == 52);

	return 0;
}
