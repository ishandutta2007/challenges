/*

Given a string consisting of printable ASCII chars, produce an output consisting of its unique chars in the original order. In other words, the output is the same as the input except that a char is removed if it has appeared previously.

No built-ins for finding unique elements in an array can be used (for example, MATLAB has a unique function that does that). The idea is to do it manually.

Further details:

Either functions or programs are allowed.
Input and output can be in the form of function arguments, stdin/stdout (even for functions), or a mix of those.
If stdin or stdout are used, a string is understood as just the sequence of chars.
If function arguments are used, the sequence of chars may need to be enclosed in quotation marks or equivalent symbols that the programming language of choice uses for defining strings.
The output should be a string containing only the unique characters of the input.
So no extra linebreaks, spaces etc. The only exception is: if the output is displayed in stdout, most displaying functions add a trailing \n (to separate the string from what will come next).
So one trailing \n is acceptable in stdout.
If possible, post a link to an online interpreter/compiler so that others can try your code.
This is code golf, so shortest code in bytes wins.

Some examples, assuming stdin and stdout:

Input string:

Type unique chars!
Output string:

Type uniqchars!
Input string

"I think it's dark and it looks like rain", you said
Output string

"I think'sdarloe,yu
Input string

3.1415926535897932384626433832795
Output string

3.14592687

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
uniqchars(const char *s, char *b)
{
	char h[256];
	size_t i, j;
	int c;

	memset(h, 0, sizeof(h));
	for (i = j = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if (!h[c]) {
			b[j++] = c;
			h[c] = 1;
		}
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	uniqchars(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Type unique chars!", "Type uniqchars!");
	test("\"I think it's dark and it looks like rain\", you said", "\"I think'sdarloe,yu");
	test("3.1415926535897932384626433832795", "3.14592687");

	return 0;
}
