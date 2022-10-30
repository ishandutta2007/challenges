/*

Create a recursive function that takes two parameters and repeats the string n number of times.
The first parameter txt is the string to be repeated and the second parameter is the number of times the string is to be repeated.

Examples

Repetition("ab", 3) ➞ "ababab"

Repetition("kiwi", 1) ➞ "kiwi"

Repetition("cherry", 2) ➞ "cherrycherry"

Notes

The second parameter of the function is positive integer.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
repeat(const char *s, size_t n, char *b)
{
	size_t i;

	if (n == 0) {
		b[0] = '\0';
		return 0;
	}

	for (i = 0; s[i]; i++)
		b[i] = s[i];

	repeat(s, n - 1, b + i);
	return b;
}

void
test(const char *s, size_t n, const char *r)
{
	char b[128];

	repeat(s, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("kiwi", 1, "kiwi");
	test("cherry", 2, "cherrycherry");
	test("soccer", 2, "soccersoccer");
	test("ab", 3, "ababab");
	test("this", 1, "this");
	test("ciao", 4, "ciaociaociaociao");
	test("charon", 5, "charoncharoncharoncharoncharon");
	test("sa", 10, "sasasasasasasasasasa");
	test("AAA", 0, "");

	return 0;
}
