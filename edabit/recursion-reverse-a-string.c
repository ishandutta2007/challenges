/*

Write a function that reverses a string. Make your function recursive.

Examples

reverse("hello") ➞ "olleh"

reverse("world") ➞ "dlrow"

reverse("a") ➞ "a"

reverse("") ➞ ""

Notes

    For non-base cases, your function must call itself at least once.
    Check the Resources tab for info on recursion.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
recurse(const char *s, char *b, size_t *i, size_t *j)
{
	if (s[*j] == '\0') {
		b[*j] = '\0';
		return;
	}

	(*j)++;
	recurse(s, b, i, j);
	b[--(*j)] = s[(*i)++];
}

char *
reverse(const char *s, char *b)
{
	size_t i, j;

	i = j = 0;
	recurse(s, b, &i, &j);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	reverse(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("hello", "olleh");
	test("world", "dlrow");
	test("a", "a");
	test("", "");

	return 0;
}
