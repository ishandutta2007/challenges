/*

An ice cream sandwich is a string that is formed by two identical ends and a different middle.
Some examples of ice cream sandwiches:

"AABBBAA"

"3&&3"

"yyyyymmmmmmmmyyyyy"

"hhhhhhhhmhhhhhhhh"

Notice how left and right ends of the sandwich are identical in both length and in repeating character. The middle section is distinctly different.
Not ice cream sandwiches:

"BBBBB"
// You can't have just plain icecream.

"AAACCCAA"
// You can't have unequal sandwich ends.

"AACDCAA"
// You can't have more than one filling.

"A"
// You can't have fewer than 3 characters.

Write a function that returns true if a string is an ice cream sandwich and false otherwise.
Examples

isIcecreamSandwich("CDC") ➞ true

isIcecreamSandwich("AAABB") ➞ false

isIcecreamSandwich("AA") ➞ false

Notes

An ice cream sandwich must have a minimum length of 3 characters, and at least two of these characters must be distinct (you can't only have the filling!).

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
icesand(const char *s)
{
	size_t i, j, n;

	n = strlen(s);
	if (n < 3)
		return false;

	i = 0;
	j = n - 1;
	while (s[i] == s[0] && s[j] == s[0] && i < j) {
		i++;
		j--;
	}

	for (; i < j; i++) {
		if (s[i] != s[i + 1])
			return false;
	}

	return s[i] != s[0];
}

int
main(void)
{
	assert(icesand("AABBBAA") == true);
	assert(icesand("3&&3") == true);
	assert(icesand("yyyyymmmmmmmmyyyyy") == true);
	assert(icesand("hhhhhhhhmhhhhhhhh") == true);
	assert(icesand("CDC") == true);
	assert(icesand("BBBBB") == false);
	assert(icesand("AAACCCAA") == false);
	assert(icesand("AACDCAA") == false);
	assert(icesand("AAABB") == false);
	assert(icesand("AA") == false);
	assert(icesand("A") == false);
	assert(icesand("") == false);
	assert(icesand("yyyyymmmmmfmmmyyyyy") == false);
	assert(icesand("yyyyyfmmmmfmmfyyyyy") == false);
	assert(icesand("AAA") == false);
	assert(icesand("AAB") == false);

	return 0;
}
