/*
Output some form of these numbers: 137, 1315, 73, 136, 255, 1384, 16385, one per line in the listed order.

The first two lines of the CORRECT output file are:

137=2(2(2)+2+2(0))+2(2+2(0))+2(0)
1315=2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)

The correct output file should contain 7 lines.
*/
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
decomposerec(unsigned int n)
{
	static const int bits = sizeof(unsigned int) * CHAR_BIT;
	unsigned char b[bits];
	int i, j, c;

	if (n == 0) {
		printf("0");
		return;
	}

	for (i = j = 0; i < bits; i++) {
		if (n & (1u << i))
			b[j++] = i;
	}
	c = 0;
	for (i = j - 1; i >= 0; i--) {
		if (c++ > 0)
			printf("+");

		printf("2");
		if (b[i] != 1) {
			printf("(");
			decomposerec(b[i]);
			printf(")");
		}
	}
}

void
decompose(unsigned int n)
{
	printf("%u=", n);
	decomposerec(n);
	printf("\n");
}

int
main(void)
{
	size_t i;
	unsigned int a[] = {137, 1315, 73, 136, 255, 1384, 16385};
	for (i = 0; i < nelem(a); i++)
		decompose(a[i]);
	return 0;
}
