/*

A very simple challenge today. Output a truthy value whether the ASCII character (or it's code) supplied is a brainfuck instruction (one of +-,.<>[]), and a falsy value if it's a comment (everything else).

Input

+
#
<
>
.
P
,

Output

true
false
true
true
true
false
true

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
isbf(char c)
{
	return strchr("+-,.<>[]", c) != NULL;
}

int
main(void)
{
	assert(isbf('+') == true);
	assert(isbf('#') == false);
	assert(isbf('<') == true);
	assert(isbf('>') == true);
	assert(isbf('.') == true);
	assert(isbf('P') == false);
	assert(isbf(',') == true);

	return 0;
}
