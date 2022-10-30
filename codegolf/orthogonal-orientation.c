/*

Task: Given an input consisting of exactly one of the characters <>^v, output a second input consisting of the printable ASCII characters (from space to tilde), oriented with the arrow.

Let's assume the second input to the program is ABC. This is what it should do:

Input >: print ABC.
Input <: print CBA.
Input ^: print C\nB\nA, or the input rotated -90°.
Input v: print A\nB\nC, or the input rotated 90°.
Test cases
input => \n output
---
">", "thanks!" =>
thanks!
---
"<", "Hello, World!" =>
!dlroW ,olleH
---
"^", "This is text." =>
.
t
x
e
t

s
i

s
i
h
T
---
"v", "Tokyo" =>
T
o
k
y
o
---
"<", ">>>" =>
>>>

*/

#include <stdio.h>
#include <string.h>

void
display(int t, const char *s)
{
	size_t i, n;

	n = strlen(s);
	switch (t) {
	case '>':
		printf("%s", s);
		break;

	case '<':
		for (i = n; i; i--)
			printf("%c", s[i - 1]);
		break;

	case '^':
		for (i = n; i; i--)
			printf("%c%s", s[i - 1], (i > 1) ? "\n" : "");
		break;

	case 'v':
		for (i = 0; i < n; i++)
			printf("%c%s", s[i], (i < n - 1) ? "\n" : "");
		break;
	}
	printf("\n\n");
}

int
main(void)
{
	display('>', "ABC");
	display('<', "ABC");
	display('^', "ABC");
	display('v', "ABC");
	display('>', "thanks!");
	display('<', "Hello, World!");
	display('^', "This is text.");
	display('v', "Tokyo");
	display('<', ">>>");

	return 0;
}
