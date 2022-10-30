/*

Objective

Write a program or function that checks if a variable name is valid and output 1 or True if it is valid, 0.5 if it is valid but starts with an underscore (_), and 0 or False if it is not valid.
Rules

    A variable name in most languages is valid if it begins with an underscore or letter (a-z, A-Z, _) and the rest of the characters are either underscores, letters, or numbers. (a-z, A-Z, 0-9, _)
    Output 1 or True if the variable name is valid and 0 or False if not valid.
    However, it is not good practice to start a variable with an underscore, so return 0.5 if it starts with an underscore and the name is valid.

Test Cases
Input

abcdefghijklmnop
Output

1
Input

_test_
Output

0.5 (starts with an underscore)
Input

123abc
Output

0 (starts with a number)
Input

A_b1C_23
Output

1
Input

_!
Output

0 (not 0.5 because it's not valid)
Input

magical pony1
Output

0 (no spaces)

Standard loopholes apply.

This is code-golf, so shortest code wins.

Bonus: -10% if your program/function outputs 0 for an empty string("").

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

double
namevalue(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] == '_')
			continue;
		if ('a' <= s[i] && s[i] <= 'z')
			continue;
		if ('A' <= s[i] && s[i] <= 'Z')
			continue;
		if ('0' <= s[i] && s[i] <= '9')
			continue;

		return 0;
	}

	if (i == 0 || isdigit(s[0]))
		return 0;
	if (s[0] == '_')
		return 0.5;

	return 1;
}

int
main(void)
{
	assert(namevalue("abcdefghijklmnop") == 1);
	assert(namevalue("_test_") == 0.5);
	assert(namevalue("123abc") == 0);
	assert(namevalue("A_b1C_23") == 1);
	assert(namevalue("_!") == 0);
	assert(namevalue("magical pony1") == 0);

	return 0;
}
