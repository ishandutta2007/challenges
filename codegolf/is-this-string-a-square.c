/*

A string is considered to be square if the following conditions are met:

Each line has the same number of characters
The number of characters on each line is equal to the number of lines.
Your task is to write a program or function which determines whether or not a given input string is a square.

You may require input to be delimited by your choice of LF, CR, or CRLF.

The newline character(s) are not considered part of the line's length.

You may require there to be or to not be a trailing newline in input, which doesn't count as an additional line.

Input is a string or 1D char array; it is not a list of strings.

You may assume input is non-empty and only contains printable ASCII, including spaces.

You must output a truthy value for square strings and a falsy one for other strings.

Truthy test cases:
foo
bar
baz
.
.s.
.ss
.s.
(s represents space)
ss
ss
(s represents space)
aaaaa
aaaaa
aaaaa
aaaaa
aaaaa
Falsy test cases:
..
.
.


.
....


....
4444
333
22
333
333
abc.def.ghi
Note extra blank lines in some of the falsy cases.

*/

#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

bool
squarish(const char *s)
{
	size_t x, w, h;
	size_t i;

	x = w = h = 0;
	for (i = 0;; i++) {
		if (s[i] == '\n' || s[i] == '\0') {
			if (w == 0)
				w = x;

			if (w != x)
				return false;

			x = 0;
			h = h + 1;
		} else
			x = x + 1;

		if (s[i] == '\0')
			break;
	}

	return w == h;
}

int
main(void)
{
	assert(squarish("foo\nbar\nbaz") == true);
	assert(squarish(".") == true);
	assert(squarish(". .\n. .\n. .") == true);
	assert(squarish("  \n  ") == true);
	assert(squarish("aaaaa\naaaaa\naaaaa\naaaaa\naaaaa") == true);

	assert(squarish("..\n.") == false);
	assert(squarish(". \n") == false);
	assert(squarish("....\n\n\n....") == false);
	assert(squarish("4444\n333\n22") == false);
	assert(squarish("333\n333") == false);
	assert(squarish("abc.def.ghi") == false);

	return 0;
}
