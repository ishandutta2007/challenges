/*

Write a function that takes a two-digit number and determines if it's the largest of two possible digit swaps.

To illustrate:

largestSwap(27) ➞ false

largestSwap(43) ➞ true

If 27 is our input, we should return false because swapping the digits gives us 72, and 72 > 27. On the other hand, swapping 43 gives us 34, and 43 > 34.

Notes

Numbers with two identical digits (third example) should yield true (you can't do better).

*/

#include <stdio.h>

int
largestswap(int x)
{
	int y;

	if (x <= 9 || x >= 100)
		return -1;

	y = (x % 10) * 10 + x / 10;
	return x >= y;
}

int
main(void)
{
	printf("%d\n", largestswap(27));
	printf("%d\n", largestswap(43));
	printf("%d\n", largestswap(14));
	printf("%d\n", largestswap(53));
	printf("%d\n", largestswap(99));
	return 0;
}
