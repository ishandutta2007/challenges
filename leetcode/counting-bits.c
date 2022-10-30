/*

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Follow up:

    It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
    Space complexity should be O(n).
    Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

*/

#include <stdio.h>
#include <stdlib.h>

unsigned *
countbits(unsigned n)
{
	unsigned i, *p;

	p = calloc(n + 1, sizeof(*p));
	if (!p)
		return NULL;

	for (i = 1; i <= n; i++)
		p[i] = p[i >> 1] + (i & 1);

	return p;
}

void
test(unsigned n)
{
	unsigned i, *p;

	p = countbits(n);
	if (!p)
		return;

	printf("[");
	for (i = 0; i <= n; i++) {
		printf("%u", p[i]);
		if (i + 1 < n + 1)
			printf(", ");
	}
	printf("]\n");

	free(p);
}

int
main(void)
{
	test(2);
	test(5);
	test(1000);
	return 0;
}
