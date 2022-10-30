/*

You are given four integers: N, S, P, Q.
You will use them in order to create the sequence a with the following pseudo-code.

a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31)

Your task is to calculate the number of distinct integers in the sequence

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

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

int64_t
seq1(uint32_t n, uint32_t s, uint32_t p, uint32_t q)
{
	const uint32_t m = 1UL << 31;

	Bits *b;
	uint32_t a;
	int64_t c;

	if (n == 0)
		return 0;

	b = newbits(m / 64);
	if (b == NULL)
		return -1;

	a = s % m;
	for (c = 1; c < n; c++) {
		if (setbit(b, a) == 0)
			break;
		a = (a * p + q) % m;
	}

	free(b);
	return c;
}

int
main(void)
{
	printf("%" PRId64 "\n", seq1(3, 1, 1, 1));
	printf("%" PRId64 "\n", seq1(10000, 21, 5, 24));
	printf("%" PRId64 "\n", seq1(50000, 22421, 54465, 2422124));
	printf("%" PRId64 "\n", seq1(1UL << 30, 22, 4465, 81124));
	printf("%" PRId64 "\n", seq1(1UL << 20, 3, 45, 24));
	return 0;
}
