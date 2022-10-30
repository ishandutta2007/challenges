/*

Consider the sequence:

0,1,1,2,1,3,2,3,1,4,3,5,2,5,3,4,1,5,4,7,3,8,5,7,2,7,5,8,3,7,4,5,1,6,5,9,4...

This sequence is defined recursively by the formula:

f(2n) = f(n)
f(2n+1) = f(n) + f(n+1)
with the initial values f(0) = 0 and f(1) = 1

In 1982, Dijkstra called this sequence fusc because it possesses a curious obfuscated property: if the sum of two indices, n and m, is a power of 2, then f(n) and f(m) are coprime.

The sequence of the ratios of two consecutive elements un = f(n) / f(n+1) runs through all nonnegative rational numbers (in reduced form) just once!

0, 1,1/2, 2, 1/3, 3/2, 2/3, 3,1/4, 4/3, 3/5, 5/2, 2/5, 5/3, 3/4, 4, ...

Moreover, if the terms are written as an array:

1

1,2

1,3,2,3

1,4,3,5,2,5,3,4

1,5,4,7,3,8,5,7,2,7,5,8,3,7,4,5

1,6,5,9,4,11,7,10,3,11,8,13,5,12,7,9,2,9,7,12,5,13,8,11,3,10,7,11,4,9,5,6

then the sum of the k-th row is 3k-1, each columns is an arithmetic progression, and the steps are nothing but the original sequence!

In this problem, given n, you have to find max{f(i); 0<=i<=n)}

Input
One single line contains n (0<=n<=1015)

Output
One single line contains max{f(i); 0<=i<=n)}

Example
Input:
10

Output:
4

*/

#include <assert.h>
#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int
fusc(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	if (!(n & 1))
		return fusc(n / 2);
	return fusc(n / 2) + fusc((n / 2) + 1);
}

int
maxfusc(int n)
{
	int i, m;

	m = 0;
	for (i = 0; i < n; i++)
		m = max(m, fusc(i));
	return m;
}

int
main(void)
{
	assert(maxfusc(10) == 4);

	return 0;
}
