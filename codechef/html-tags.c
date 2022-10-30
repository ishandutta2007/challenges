/*

In addition to CP, Chef recently developed an interest in Web Development and started learning HTML.
Now he wants to create his own HTML Code Editor. As a subproblem, he wants to check if a typed HTML closing tag has correct syntax or not.

A closing HTML tag must:

Start with "</"
End with ">"
Have only lower-case alpha-numeric characters as its body (between "</" and ">"). That is, each character of the body should either be a digit or a lower-case English letter.
Have a non-empty body.
Help Chef by printing "Success" if the tag is fine. If not, print "Error".

Input

The first line contains an integer T, the number of test cases. Then T test cases follow.
Each test case is a single line of input, a string describing the tag we need to check.

Output

For each test case, output in a single line, "Success" if it is a valid closing tag and "Error" otherwise (without quotes).
You may print each character of the string in uppercase or lowercase (for example, the strings "SuccEss", "success", "Success", "SUCCESS" et cetera will all be treated as identical).

Constraints
1≤T≤1000
1≤ length(Tag) ≤1000
The characters of the string belong to the ASCII range [33,126] (note that this excludes space.)

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
valid(const char *s)
{
	size_t i;

	if (s[0] != '<' || s[1] != '/')
		return false;

	for (i = 2; s[i] != '>' && s[i] != '\0'; i++) {
		if ('0' <= s[i] && s[i] <= '9')
			continue;
		if ('a' <= s[i] && s[i] <= 'z')
			continue;
		return false;
	}

	return !(i == 2 || s[i] != '>' || s[i + 1] != '\0');
}

int
main(void)
{
	assert(valid("</h1>") == true);
	assert(valid("Clearly_Invalid") == false);
	assert(valid("</singlabharat>") == true);
	assert(valid("</5>") == true);
	assert(valid("<//aA>") == false);
	assert(valid("</>") == false);
	assert(valid("</h>x") == false);

	return 0;
}
