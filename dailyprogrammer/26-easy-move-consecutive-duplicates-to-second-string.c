/*

you have a string "ddaaiillyypprrooggrraammeerr". We want to remove all the consecutive duplicates and put them in a separate string, which yields two separate instances of the string "dailyprogramer".

use this list for testing:

input: "balloons"

expected output: "balons" "lo"

input: "ddaaiillyypprrooggrraammeerr"

expected output: "dailyprogramer" "dailyprogramer"

input: "aabbccddeded"

expected output: "abcdeded" "abcd"

input: "flabby aapples"

expected output: "flaby aples" "bap"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
movedup(const char *s, char *p, char *q)
{
	size_t i, j, k;

	for (i = 0; s[i]; i = j) {
		j = i + 1;
		while (s[j] == s[i])
			j++;

		*p++ = s[i];
		for (k = 1; k < j - i; k++)
			*q++ = s[i];
	}
	*p = *q = '\0';
}

void
test(const char *s, const char *rp, const char *rq)
{
	char p[128], q[128];

	movedup(s, p, q);
	printf("%s %s\n", p, q);
	assert(!strcmp(p, rp));
	assert(!strcmp(q, rq));
}

int
main(void)
{
	test("balloons", "balons", "lo");
	test("ddaaiillyypprrooggrraammeerr", "dailyprogramer", "dailyprogramer");
	test("aabbccddeded", "abcdeded", "abcd");
	test("flabby aapples", "flaby aples", "bap");
	test("aaaa", "a", "aaa");

	return 0;
}
