/*

A weighted string is a string of lowercase English letters where each letter has a weight. Character weights are 1 to 26 from a to z as shown below:

We define the following terms:

The weight of a string is the sum of the weights of all the string's characters.
A uniform string consists of a single character repeated zero or more times. For example, ccc and a are uniform strings, but bcb and cd are not.

Given a string s, let U be the set of weights for all possible uniform contiguous substrings of string s.
You have to answer n queries, where each query i consists of a single integer, x[i]. For each query, print Yes on a new line if x[i] in U
otherwise, print No instead.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct Bits Bits;

struct Bits {
	size_t n;
	uint64_t a[];
};

Bits *
newbits(size_t n)
{
	Bits *b;

	b = calloc(1, sizeof(*b) + sizeof(*b->a) * n);
	if (b == NULL)
		return NULL;
	b->n = n;
	return b;
}

int
setbit(Bits *b, uint64_t p)
{
	uint64_t i, j;

	i = p / 64;
	j = p & 63;
	assert(i < b->n);

	if (b->a[i] & (1ULL << j))
		return 0;

	b->a[i] |= (1ULL << j);
	return 1;
}

int
bit(Bits *b, uint64_t p)
{
	uint64_t i, j;

	i = p / 64;
	j = p & 63;
	assert(i < b->n);

	return (b->a[i] & (1ULL << j)) != 0;
}

Bits *
weights(const char *s)
{
	Bits *b;
	size_t i, n;
	int c, w;

	n = strlen(s);
	b = newbits((n * 26 + 63) / 64);
	if (!b)
		return NULL;

	w = 0;
	for (i = 0; s[i]; i++) {
		c = (s[i] & 0xff) - 'a' + 1;
		if (!(1 <= c && c <= 26))
			continue;
		if (i > 0 && s[i - 1] != s[i])
			w = 0;
		w += c;
		setbit(b, w);
	}
	return b;
}

void
query(const char *s, int *q, size_t n)
{
	Bits *b;
	size_t i;

	b = weights(s);
	assert(b);

	for (i = 0; i < n; i++)
		printf("%s\n", (bit(b, q[i])) ? "Yes" : "No");
	printf("\n");
	free(b);
}

int
main(void)
{
	int a[] = {1, 3, 12, 5, 9, 10};
	query("abccddde", a, nelem(a));

	int b[] = {9, 7, 8, 12, 5};
	query("aaabbbbcccddd", b, nelem(b));

	return 0;
}
