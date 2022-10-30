/*

The skip-pure numbers are defined with this rule:

A(0) = 1
A(1) = 1
A(n) = the smallest positive number not in the sequence such that A(x) + A(x-2) for any x never appears
For example, the term A(2) is 2, because 1 has already appeared. The term A(3) is 4, as A(2) + A(0) = 3 and 3 is disallowed by the third line of the rule.

Given a number n, your program should output the nth skip-pure number, using zero-based indexing (such that A(0) is defined).

Output can be in any format (strings, ints, lists, arrays, etc.), but the number itself must be outputted in base 10.

Trailing output (newlines, etc.) is allowed but only if your language has to output it. If you can work around trailing output, solve it with the workaround.

Here are test cases, shown in the format input = output:

0 = 1
1 = 1
2 = 2
3 = 4
4 = 6
5 = 7
6 = 9
7 = 10
8 = 12
9 = 13
I created this sequence myself and am probably the first person to talk about it, so there is no OEIS link.

This is a code-golf, so the shortest program that does all of the above (measured in bytes) wins. Have fun.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

@Arnauld

Apart from the first 2 terms, this is the complement of
https://oeis.org/A022433

The only edge case is a(0) = 1, for n >= 1

a(n) = floor(3*n / 2) - 1 if floor(log2(n)) is odd and n%4 == 2
       floor(3*n / 2) otherwise

*/

int
skippure(int n)
{
	int r, v;

	if (n < 0)
		return 0;

	if (n == 0)
		return 1;

	r = (3 * n) / 2;
	v = log2(n);
	if ((v & 1) && (n % 4 == 2))
		r--;

	return r;
}

int
main(void)
{
	static const int tab[] = {
	    1,
	    1,
	    2,
	    4,
	    6,
	    7,
	    9,
	    10,
	    12,
	    13,
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(skippure(i) == tab[i]);

	return 0;
}
