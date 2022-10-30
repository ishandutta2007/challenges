/*

An unspeakable number is a number which is divisible by seven or has seven as one of its digits. A children game is to count skipping unspeakable numbers

1 2 3 4 5 6 ( ) 8 9 10 11 12 13 ( ) 15 16 ( ) 18 ...
Cantor's version of the game is the sequence defined by recursively filling in the sequence "1 2 3 4 5 6 ( ) 8..." into the gaps ( ) above.

1 2 3 4 5 6 1 8 9 10 11 12 13 2 15 16 3 18 19 20 4 22 23 24 25 26 5 6 29 30 31 32 33 34 1 36 8 38 ...

Print/output at least the first 7^7 numbers of Cantor's unspeakable number game...

While the definition is given recursively, you are not obliged to use recursion in the code.

This is code-golf, so the program with the shortest byte count wins!

Note: The sum of numbers in 1 to 7^7 is 203511962727. The last 10 numbers in that range are 823534 823535 221563 108068 823538 823539 823540 823541 823542 221565.

Pastebin dump of first 1000 iterates: http://pastebin.com/Ksiu9Svf

*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long uvlong;

int
has7(uvlong n)
{
	if (n && n % 7 == 0)
		return 1;

	while (n > 0) {
		if (n % 10 == 7)
			return 1;

		n /= 10;
	}

	return 0;
}

// https://oeis.org/A328018
void
output(uvlong n)
{
	uvlong *a, i, k, s;

	a = calloc(n + 1, sizeof(*a));
	if (!a)
		return;

	s = 0;
	for (i = k = 1; i <= n; i++) {
		a[i] = i;
		if (has7(i))
			a[i] = a[k++];
		s += a[i];

		printf("%llu\n", a[i]);
	}
	printf("Total %llu\n", s);

	free(a);
}

int
main(void)
{
	output(823543);

	return 0;
}
