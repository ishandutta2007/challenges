/*

Per 6 coffee cups I buy, I get a 7th cup free. In total, I get 7 cups.
Create a function that takes n cups bought and return as an integer the total number of cups I would get.
Examples

totalCups(6) ➞ 7

totalCups(12) ➞ 14

totalCups(213) ➞ 248

Notes

    Number of cups I bought + number of cups I got for free.
    Only valid inputs will be given.

*/

#include <assert.h>

unsigned
totalcups(unsigned n)
{
	return n + n / 6;
}

int
main(void)
{
	assert(totalcups(6) == 7);
	assert(totalcups(3) == 3);
	assert(totalcups(7) == 8);
	assert(totalcups(12) == 14);
	assert(totalcups(213) == 248);
	assert(totalcups(16) == 18);

	return 0;
}
