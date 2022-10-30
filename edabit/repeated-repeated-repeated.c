/*

This challenge concerns strings such as:

"repeatedrepeatedrepeated"

... that are obtained by repeating a smaller string, which in this case is the string "repeated".

On a related note, since the string above is made of 3 repetitions, one way to produce this string is via the code "repeated".repeat(3).

Write a function that, given a string, either:

    Returns false if the string isn't made by repeating a smaller string or ...
    Returns the number of repetitions if the string repeats a smaller string.

Examples

isRepeated("repeatedrepeatedrepeated") ➞ 3

isRepeated("overintellectualizations") ➞ False

isRepeated("nononononononononononono") ➞ 12

isRepeated("moremoremoremoremoremore") ➞ 6

isRepeated(",,,,,,,,,,,,,,,,,,,,,,,,") ➞ 24

Notes

To keep things a little simpler, all strings in the tests will have length exactly 24, just as in all the examples above. In particular, the answers will always be divisors of 24.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
repeated(const char *s)
{
	size_t i, j, k, n;

	n = strlen(s);
	for (i = 1; i < n; i++) {
		if (n % i)
			continue;

		k = n / i;
		for (j = 1; j < k; j++) {
			if (strncmp(s, s + j * i, i))
				break;
		}
		if (j == k)
			return k;
	}
	return 0;
}

char *
generate(const char *s, char *b, size_t t)
{
	size_t i, l;

	b[0] = '\0';
	for (i = l = 0; i < t; i++)
		l += sprintf(b + l, "%s", s);
	return b;
}

void
test(const char *s, size_t t, size_t r)
{
	char b[128];
	size_t i;

	generate(s, b, t);
	i = repeated(b);
	printf("%s -> %zu %zu\n", b, i, r);
	assert(i == r);
}

int
main(void)
{
	test("repeated", 3, 3);
	test("repeat", 4, 4);
	test("no", 12, 12);
	test("more", 6, 6);
	test("puns", 6, 6);
	test(",", 24, 24);
	test("please", 4, 4);
	test("stop", 6, 6);
	test("now", 8, 8);
	test("overintellectualizations", 1, 0);
	test("intercomprehensibilities", 1, 0);
	test("microspectrophotometries", 1, 0);
	test("accomplished", 2, 2);
	test("symmetry", 1, 0);
	test("isospin", 13, 13);

	return 0;
}
