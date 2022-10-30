/*

Background

The systematic chemical symbol is defined as such for 118<n<1000:

The first letter corresponds to the first digit, capitalized.
The second letter corresponds to the second digit.
The third letter corresponds to the third digit.
This can be generalized for all n>0:

For each digit, get the corresponding letter.
Capitalize the first character.

Task

Write a function or full program that takes an integer or a list of digits n>0 and returns or prints the corresponding systematic chemical symbol.

Digit | Letter
--------------
0     | n
1     | u
2     | b
3     | t
4     | q
5     | p
6     | h
7     | s
8     | o
9     | e

This is code-golf, so shortest code wins.

Test Cases
In - Out
----------
119 - Uue
120 - Ubn
123 - Ubt
999 - Eee
6859 - Hope
1 - U
92 - Eb
987654321 - Eoshpqtbu
1010101 - Unununu

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef unsigned long long uvlong;

void
swapc(char *a, char *b)
{
	char t;

	t = *a;
	*a = *b;
	*b = t;
}

void
rev(char *b, size_t n)
{
	size_t i;

	for (i = 0; i < n / 2; i++)
		swapc(b + i, b + n - i - 1);
}

char *
symbol(uvlong n, char *b)
{
	static const char map[] = "nubtqphsoe";
	size_t i;

	i = 0;
	do {
		b[i++] = map[n % 10];
		n /= 10;
	} while (n);
	b[i] = '\0';

	rev(b, i);
	b[0] = toupper(b[0]);

	return b;
}

void
test(unsigned n, const char *r)
{
	char b[128];

	symbol(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(119, "Uue");
	test(120, "Ubn");
	test(123, "Ubt");
	test(999, "Eee");
	test(6859, "Hope");
	test(1, "U");
	test(92, "Eb");
	test(987654321ULL, "Eoshpqtbu");
	test(1010101ULL, "Unununu");

	return 0;
}
