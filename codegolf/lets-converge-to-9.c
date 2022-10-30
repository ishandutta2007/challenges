/*

Given an integer n > 2, print or return the smallest non-negative integer k such that a(n, k) = 9, where a(n, k) is defined by:

a(n, 0) = n
a(n, k+1) =
a(n, k) / 2 + 1 if a(n, k) is even
the sum of the digits of a(n, k)² (in base 10) if a(n, k) is odd
Examples
For n = 5, the expected output is k = 4:

a(5, 0) = 5
a(5, 1) = 7  (5² = 25 and 2 + 5 = 7)
a(5, 2) = 13 (7² = 49 and 4 + 9 = 13)
a(5, 3) = 16 (13² = 169 and 1 + 6 + 9 = 16)
a(5, 4) = 9  (16 / 2 + 1)
For n = 40, the expected output is k = 2:

a(40, 0) = 40
a(40, 1) = 21 (40 / 2 + 1)
a(40, 2) = 9  (21² = 441 and 4 + 4 + 1 = 9)

Clarifications and rules
The input is guaranteed to be greater than 2.
Your program should theoretically work for any value of n. (In practice, it may be limited by the maximum integer size supported by your language.)
k may be either 0-indexed or 1-indexed. Please state it in your answer.
This is code-golf, so the shortest answer in bytes wins!
First values
Below are the first values from n = 3 to n = 422, with k 0-indexed. (For 1-indexing, just add 1 to these values.)

 1  2  4  3  3  5  0  4  3  4  2  6  1  1  6  5  5  4  1  5  2  3  3  7  6  2  3  2  2  7
 6  6  5  6  6  5  1  2  2  6  6  3  1  4  3  4  4  8  1  7  6  3  5  4  6  3  2  3  3  8
 7  7  3  7  4  6  6  7  5  7  6  6  6  2  4  3  3  3  6  7  3  7  2  4  7  2  6  5  6  4
 7  5  2  5  6  9  6  2  3  8  2  7  1  4  6  6  6  5  1  7  4  4  3  3  7  4  3  4  2  9
 6  8  6  8  6  4  6  8  2  5  3  7  6  7  3  8  2  6  7  8  6  7  5  7  6  7  4  3  3  5
 6  4  3  4  4  4  6  7  6  8  3  4  6  8  7  3  6  5  6  8  3  3  2  7  6  6  5  7  6  5
 7  8  2  6  3  3  6  6  6  7  4 10  6  7  3  3  6  4  1  9  2  3  3  8  7  2  6  5  2  7
 7  7  6  7  3  6  7  2  4  8  3  5  6  5  6  4  2  4  6  8  3  5  6  4  7  5  2  3  6 10
 7  7  3  9  2  7  1  9  5  7  6  5  6  7  4  9  6  3  6  6  3  4  2  8  7  7  6  8  6  4
 7  9  4  3  3  7  7  8  3  9  4  7  6  8  3  6  6  8  7  7  7  8  6  5  7  4  6  4  2  6
 7  7  6  5  3  4  7  5  4  5  3  5  7  7  6  8  2  7  1  9  6  4  6  5  7  7  2  9  6  8
 7  4  3  7  4  6  6  7  6  9  3  4  6  4  2  3  3  8  1  7  6  7  2  6  7  8  3  7  5  6
 7  8  2  9  3  3  6  7  6  4  4  4  6  7  6  7  6  7  6  8  7  5  6 11  7  7  3  8  4  4
 7  4  6  7  3  5  6  2  2 10  6  3  6  4  3  4  4  9  7  8  3  3  6  7  7  6  4  3  6  8

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

int
digitsum(int v)
{
	int r;

	for (r = 0; v; v /= 10)
		r += v % 10;
	return r;
}

int
con9(int n, int k)
{
	int r, v;

	if (k <= 0)
		return n;

	v = con9(n, k - 1);
	if (v & 1)
		r = digitsum(v * v);
	else
		r = (v / 2) + 1;
	return r;
}

int
scon9(int n)
{
	int i;

	for (i = 0; i < INT_MAX; i++) {
		if (con9(n, i) == 9)
			return i;
	}
	return -1;
}

int
main(void)
{
	assert(scon9(5) == 4);
	assert(scon9(40) == 2);
	assert(scon9(422) == 8);

	return 0;
}
