/*

Watson likes to challenge Sherlock's math ability. He will provide a starting and ending value describing a range of integers. Sherlock must determine the number of square integers within that range, inclusive of the endpoints.

Note: A square integer is an integer which is the square of an integer, e.g.
1, 4, 9, 16, 25

For example, the range is a=24 and b=49, inclusive. There are three square integers in the range: 25, 36, and 49. 

*/

#include <stdio.h>
#include <math.h>

void
swap(unsigned *a, unsigned *b)
{
	unsigned c;

	c = *a;
	*a = *b;
	*b = c;
}

int
count(unsigned a, unsigned b)
{
	if (b < a)
		swap(&a, &b);
	return floor(sqrt(b) - ceil(sqrt(a))) + 1;
}

int
main(void)
{
	printf("%d\n", count(24, 49));
	printf("%d\n", count(3, 9));
	printf("%d\n", count(17, 24));
	printf("%d\n", count(0, 100));
	return 0;
}
