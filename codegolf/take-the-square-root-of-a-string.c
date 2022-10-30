/*

Motivation

In this challenge your task was to multiply two strings, this naturally introduces a way to take the square root of a string.
How does it work?

Given a string (for example pub) the first thing you need to do, is to determine the ASCII code for each character:

"pub" -> [112, 117, 98]

Next you map these codes to the range [0..94] by subtracting 32 of each value:

[112, 117, 98] -> [80, 85, 66]

Now you need to find for each value its root modulo 95 (eg. 40*40 % 95 = 80, you could also pick 55):

[80, 85, 66] -> [40, 35, 16]

And finally you'll map it back to the range [32..126] and convert it back to a string:

[40, 35, 16] -> [72, 67, 48] -> "HC0"

Indeed "HC0" ⊗ "HC0" = "pub" as you can verify with a solution from the other challenge here.

The ones familiar with modular arithmetic probably noticed that the square root modulo 95 does not always exist, for example there's no root for 2. In such a case the square root of a string is not defined and your program/function may crash, loop indefinetly etc.

For your convenience, here's the list of chars that have a square root (the first one is a space):

 !$%&)+03489:>CDGLMQVW]`bjlpqu

Rules

    You will write a program/function that takes a string (or list of chars) as an argument and returns any square root if it exists
    You may assume that the input always has a square root
    The input may consist of an empty string
    The input will be in the printable range ([32..126])
    The output is either printed to the console or you return a string if the square root exists
    In case the square root doesn't exist, the behavior of your program/function is left undefined
    If you choose to print the root to the console trailing newlines or whitespaces are fine

Test cases

Note that these are not necessarily the only solutions:

''              -> ''
'pub'           -> 'HC0'
'pull!'         -> 'HC33!'
'M>>M'          -> '>MM>'
'49'            -> '4%'
'64'            -> undefined
'Hello, World!' -> undefined

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int
modroot(int x, int m)
{
	int i;

	for (i = 1; i < m; i++) {
		if ((i * i) % m == x)
			return i;
	}
	return 0;
}

char *
strsqrt(const char *s, char *b)
{
	size_t i;

	for (i = 0; s[i]; i++)
		b[i] = 32 + modroot(s[i] - 32, 95);
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	strsqrt(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("", "");
	test("pub", "HC0");
	test("pull!", "HC33!");
	test("M>>M", ">MM>");
	test("49", "4%");

	return 0;
}
