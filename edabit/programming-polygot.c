/*

Create a function that takes a number that represents a person's programming language score, and returns an alphabetised list of programming languages they are proficient in.
Arbitrarily assigned points for each language are listed below:

Language	Points
C#	1
C++	2
Java	4
JavaScript	8
PHP	16
Python	32
Ruby	64
Swift	128

Notes

Easier using bitwise operations.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
polygot(unsigned x, char b[8][16], size_t *n)
{
	static const char *tab[] = {
		"C#",
		"C++",
		"Java",
		"JavaScript",
		"PHP",
		"Python",
		"Ruby",
		"Swift",
	};
	unsigned i;

	*n = 0;
	for (i = 0; i < 8; i++) {
		if (x & (1u << i))
			strcpy(b[(*n)++], tab[i]);
	}
}

void
test(unsigned x)
{
	char b[8][16];
	size_t i, n;

	polygot(x, b, &n);
	printf("[");
	for (i = 0; i < n; i++) {
		printf("%s", b[i]);
		if (i + 1 < n)
			printf(", ");
	}
	printf("]\n");
}

int
main(void)
{
	test(32);
	test(25);
	test(100);
	test(255);
	test(53);
	test(12);
	return 0;
}
