/*

Given a sequence of 2*k characters, please print every second character from the first half of the sequence. Start printing with the first character.

Input
In the first line of input your are given the positive integer t (1<=t<=100) - the number of test cases. In the each of the next t lines, you are given a sequence of 2*k (1<=k<=100) characters.

Output
For each of the test cases please please print every second character from the first half of a given sequence (the first character should appear).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
half2(const char *s, char *b)
{
	size_t i, j, n;

	n = strlen(s);
	for (i = j = 0; i < n / 2; i += 2)
		b[j++] = s[i];
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	half2(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("your", "y");
	test("progress", "po");
	test("is", "i");
	test("noticeable", "ntc");

	return 0;
}
