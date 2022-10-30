/*

In Haskell the list notation:

[a,b,c]

Is just syntactic sugar for:

a:b:c:[]

And the string notation:

"abc"

Is just syntactic sugar for:

['a','b','c']

This means that the string:

"abc"

Is the same as:

'a':'b':'c':[]

Task

Given a string you should output what the de-syntaxed version would look like in Haskell.

Rules

    You will receive a string by any valid input method, you should output a string ending with :[] with every character from the input surrounded by ' and separated by :. The empty string should output [].

    You can assume that you will not receive any characters that require escaping (e.g. ', newlines, tabs ...) and that input will be in the printable ascii range

    This is code-golf you should aim to minimize the byte count of your answer

Test Cases

"" -> []
"a" -> 'a':[]
"Hello, World" -> 'H':'e':'l':'l':'o':',':' ':'W':'o':'r':'l':'d':[] 

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
desugar(const char *s, char *b)
{
	size_t i, l;

	l = 0;
	for (i = 0; s[i]; i++)
		l += sprintf(b + l, "'%c':", s[i]);
	l += sprintf(b + l, "[]");
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	desugar(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("", "[]");
	test("a", "'a':[]");
	test("Hello, World", "'H':'e':'l':'l':'o':',':' ':'W':'o':'r':'l':'d':[]");

	return 0;
}
