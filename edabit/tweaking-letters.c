/*

Create a function that tweaks letters by one forward (+1) or backwards (-1) according to an array.
Examples

tweakLetters("apple", [0, 1, -1, 0, -1]) ➞ "aqold"
// "p" + 1 => "q"; "p" - 1 => "o"; "e" - 1 => "d"

tweakLetters("many", [0, 0, 0, -1]) ➞ "manx"

tweakLetters("rhino", [1, 1, 1, 1, 1]) ➞ "sijop"

Notes

Don't worry about capital letters.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
mod(int a, int b)
{
	a %= b;
	if (a < 0)
		a += b;
	return a;
}

char *
tweak(char *s, int *a)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if ('a' <= s[i] && s[i] <= 'z')
			s[i] = 'a' + mod(s[i] - 'a' + a[i], 26);
	}
	return s;
}

int
main(void)
{
	char s1[] = "apple";
	char s2[] = "many";
	char s3[] = "rhino";
	char s4[] = "xyz";
	char s5[] = "abc";

	int a1[] = { 0, 1, -1, 0, -1 };
	int a2[] = { 0, 0, 0, -1 };
	int a3[] = { 1, 1, 1, 1, 1 };
	int a4[] = { 1, 1, 1 };
	int a5[] = { -1, -1, -1 };

	assert(strcmp(tweak(s1, a1), "aqold") == 0);
	assert(strcmp(tweak(s2, a2), "manx") == 0);
	assert(strcmp(tweak(s3, a3), "sijop") == 0);
	assert(strcmp(tweak(s4, a4), "yza") == 0);
	assert(strcmp(tweak(s5, a5), "zab") == 0);

	return 0;
}
