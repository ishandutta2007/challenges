/*

Write a program Bits.java that takes an integer command-line argument n and uses a while loop to compute the number of times
you need to divide n by 2 until it is strictly less than 1. Print the error message “Illegal input” if n is negative.

This program computes the number of bits in the binary representation of n, which also equals 1+floor(log2n) when n is positive. This quantity arises in information theory and the analysis of algorithms.

Examples:

> java-introcs Bits 0
0

> java-introcs Bits 1
1

> java-introcs Bits 2
2

> java-introcs Bits 4
3
> java-introcs Bits 8
4

> java-introcs Bits 16
5

> java-introcs Bits 1000
10

> java-introcs Bits -23
Illegal input

*/

#include <stdio.h>
#include <errno.h>
#include <inttypes.h>

int
bits(uintmax_t n)
{
	int b;

	for (b = 0; n; n >>= 1)
		b++;
	return b;
}

int
main(int argc, char *argv[])
{
	intmax_t v;
	int i;

	if (argc < 2) {
		fprintf(stderr, "usage: num ...\n");
		return 1;
	}

	for (i = 1; i < argc; i++) {
		v = strtoimax(argv[i], NULL, 10);
		if (v < 0) {
			fprintf(stderr, "illegal input: %s\n", argv[i]);
			continue;
		}
		printf("%d\n", bits(v));
	}

	return 0;
}
