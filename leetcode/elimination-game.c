/*

There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.

Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

Find the last number that remains starting with a list of length n.

Example:

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6

*/

#include <stdio.h>

// hacker's delight
unsigned
hibit(unsigned n)
{
	n |= (n >> 1);
	n |= (n >> 2);
	n |= (n >> 4);
	n |= (n >> 8);
	n |= (n >> 16);
	return n - (n >> 1);
}

// https://en.wikipedia.org/wiki/Josephus_problem#k.3D2
unsigned
lastremain(unsigned n)
{
	if (n == 0)
		return 0;
	return ((hibit(n) - 1) & (n | 0x55555555UL)) + 1;
}

unsigned
lastremainr(unsigned n)
{
	if (n <= 1)
		return n;
	return 2 * (1 + n / 2 - lastremainr(n / 2));
}

int
main(void)
{
	unsigned i;

	for (i = 0; i <= 1024; i++)
		printf("%u %u %u\n", i, lastremain(i), lastremainr(i));
	return 0;
}
