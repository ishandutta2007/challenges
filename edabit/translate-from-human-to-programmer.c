/*

Replace the numbers in a string with their binary form.
Examples

replaceNums("I have 2 sheep.") ➞ "I have 10 sheep."

replaceNums("My father was born in 1974.10.25.") ➞ "My father was born in 11110110110.1010.11001."

replaceNums("10hell76o4 boi") ➞ "1010hell1001100o100 boi"

Notes

    There are possibly two or more numbers in a single word (I do not recommend splitting the text at spaces, it surely won't help).
    Anything separates two numbers, even spaces ("2 2" --> "10 10").

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

typedef unsigned long long uvlong;

size_t
writebin(uvlong n, char *b)
{
	char *p, d[sizeof(n) * CHAR_BIT];
	size_t i;

	i = 0;
	do {
		d[i++] = n & 1;
	} while (n >>= 1);

	p = b;
	while (i > 0)
		*p++ = d[--i] + '0';
	return p - b;
}

char *
replacenums(const char *s, char *b)
{
	size_t i, j;
	char *ep;
	uvlong n;

	for (i = j = 0; s[i];) {
		if (!isdigit(s[i])) {
			b[j++] = s[i++];
			continue;
		}
		n = strtoull(s + i, &ep, 10);
		j += writebin(n, b + j);
		i = ep - s;
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	replacenums(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("I have 2 sheep.", "I have 10 sheep.");
	test("I have 2 sheep, and 21 chickens.", "I have 10 sheep, and 10101 chickens.");
	test("100 is my lucky number.", "1100100 is my lucky number.");
	test("My father was born in 1974.10.25.", "My father was born in 11110110110.1010.11001.");
	test("This sentence is10 35filled with ran20dom numbers on7 purpo31se.", "This sentence is1010 100011filled with ran10100dom numbers on111 purpo11111se.");
	test("10hell76o4 boi", "1010hell1001100o100 boi");
	test("2 2", "10 10");

	return 0;
}
