/*

Suppose that you add all of the page numbers in a book. If the total is 21, the book would have only 6 pages because 1 + 2 + 3 + 4 + 5 + 6 = 21.
If I had said the total is 25, that would be impossible because the next number in the series is 28 (21 + 7).

Create a function that has as it's argument the sum of all the page numbers and returns true if it is a valid number and false if it is not.

Can you devise a solution that is more efficient than simply adding consecutive integers as I did above?
Examples

pagesInBook(5) ➞ false

pagesInBook(4005) ➞ true

pagesInBook(9453) ➞ true

*/

#include <assert.h>
#include <math.h>

int
pagesinbook(unsigned n)
{
	double x, f;

	x = (-1 + sqrt(1 + 8 * n)) / 2;
	f = fmod(x, 1);
	return f == 0;
}

int
main(void)
{
	assert(pagesinbook(5) == 0);
	assert(pagesinbook(4005) == 1);
	assert(pagesinbook(9453) == 1);
	assert(pagesinbook(9474) == 0);
	assert(pagesinbook(125250) == 1);
	assert(pagesinbook(920046) == 1);

	return 0;
}
