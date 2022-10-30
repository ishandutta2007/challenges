/*
Brie’s Drawing teacher asks her class to open their books to a page number. 
Brie can either start turning pages from the front of the book or from the back of the book. 
She always turn pages one at a time. When she opens the book, page 1 is always on the right side:

When she flips page 1, she sees pages 2 and 3. Each page except the last page will always be printed on both sides.
The last page may only be printed on the front, given the length of the book. If the book is n pages long, and she wants to turn to page p, 
what is the minimum number of pages she will turn? She can start at the beginning or the end of the book.

Given n and p, find and print the minimum number of pages Brie must turn in order to arrive at page p.
*/

#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
pagecount(int n, int p)
{
	int a, b;

	if (n <= 0 || p <= 0 || p > n)
		return -1;

	a = p / 2;
	b = (n - p) / 2;
	return min(a, b);
}

int
main(void)
{
	printf("%d\n", pagecount(6, 2));
	printf("%d\n", pagecount(5, 4));
	printf("%d\n", pagecount(5, 3));
	printf("%d\n", pagecount(6, 6));
	printf("%d\n", pagecount(6, 3));
	printf("%d\n", pagecount(6, 4));
	printf("%d\n", pagecount(999, 100));
	return 0;
}
