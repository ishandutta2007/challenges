/*

There are two types of potions:

    Growing potion: "A"
    Shrinking potion: "B"

    If "A" immediately follows a digit, add 1 to the digit.
    If "B" immediately follows a digit, subtract 1 from the digit.

Create a function that returns a string according to these rules, removing the potions once they've been consumed.
Examples

afterPotion("3A78B51") ➞ "47751"
// 3 grows to 4, 8 shrinks to 7

afterPotion("9999B") ➞ "9998"

afterPotion("9A123") ➞ "10123"

afterPotion("567") ➞ "567"

Notes

    Digits that do not have a potion on their immediate right should be left alone.
    A digit will always either be followed by zero or exactly 1 potion.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
potion(const char *s, char *b)
{
	size_t i, j;
	int c;

	for (i = j = 0; s[i]; i++) {
		if (!isdigit(s[i])) {
			b[j++] = s[i];
			continue;
		}

		c = s[i] - '0';
		if (s[i + 1] == 'A' || s[i + 1] == 'B')
			c += (s[++i] == 'A') ? 1 : -1;

		if (c >= 10)
			b[j++] = (c / 10) + '0';
		if (c > 0)
			b[j++] = (c % 10) + '0';
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	potion(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("567", "567");
	test("3A78B51", "47751");
	test("9999B", "9998");
	test("9A123", "10123");
	test("1A2A3A4A", "2345");
	test("9B8B7B6A", "8767");

	return 0;
}
