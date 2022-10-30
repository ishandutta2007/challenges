/*

In the image below, squares are either empty or filled with a circle.
**  *..* *....*
**  .**. .*..*.
    .**. ..**..
    *..* ..**..
         .*..*.
         *....*

Create a function that takes a number step (which equals HALF the width of a square) and returns the amount of empty squares.
The image shows the squares with step 1, 2 and 3. The return value is the number of cells not on a diagonal,
which is 0 for the first square, 8 for the second, and 24 for the third.

Notes

    Test input will always be a positive integer.
    The width of the square will always be even.

*/

#include <stdio.h>

// https://oeis.org/A033996
// 8 times triangular numbers: a(n) = 4*n*(n+1)
unsigned
emptysquare(unsigned n)
{
	if (n == 0)
		return 0;
	return 4 * (n - 1) * n;
}

int
main(void)
{
	printf("%u\n", emptysquare(3));
	printf("%u\n", emptysquare(1));
	printf("%u\n", emptysquare(27));
	printf("%u\n", emptysquare(3));
	printf("%u\n", emptysquare(0));
	printf("%u\n", emptysquare(10));
	printf("%u\n", emptysquare(19));
	printf("%u\n", emptysquare(60));
	printf("%u\n", emptysquare(7));
	return 0;
}
