/*

Your challenge is to write a program that outputs the color of a given square from the chessboard.

You can see that the square a1 is dark, and h1 is a light square. Your program needs to output dark or light, when given a square. Some examples:

STDIN:  b1
STDOUT: light

STDIN:  g6
STDOUT: light

STDIN:  d4
STDOUT: dark
The rules:

You need to provide a full program that uses STDIN and uses STDOUT to output dark or light.
Assume that the input is always valid ([a-h][1-8])
This is code-golf, so shortest amount of bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
color(const char *s)
{
	int a, b;

	if (!s[0] || !s[1])
		return NULL;

	a = (s[0] - 'a') & 1;
	b = (s[1] - '1') & 1;
	return (a ^ b) ? "light" : "dark";
}

void
test(const char *s, const char *r)
{
	const char *p;

	p = color(s);
	printf("%s: %s\n", s, p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test("b1", "light");
	test("g6", "light");
	test("d4", "dark");
	test("a8", "light");
	test("b8", "dark");
	test("c8", "light");
	test("d8", "dark");
	test("e8", "light");
	test("f8", "dark");
	test("g8", "light");
	test("h8", "dark");
	test("h1", "light");
	test("d6", "dark");
	test("a2", "light");
	test("e2", "light");

	return 0;
}
