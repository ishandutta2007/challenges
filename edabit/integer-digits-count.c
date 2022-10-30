/*

Create a function that counts the integer's number of digits.
Examples

count(318) ➞ 3
 
count(-92563) ➞ 5
 
count(4666) ➞ 4

count(-314890) ➞ 6

count(654321) ➞ 6

count(638476) ➞ 6

Notes

    For an added challenge, try to solve this without using strings.
    Optionally, you can solve this via a recursive approach.
    A recursive version of this challenge can be found via this link.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

long
count(long n)
{
	long c;

	c = 0;
	do {
		c++;
		n /= 10;
	} while (n);
	return c;
}

int
main(void)
{
	static const long itab[] = {
	    0L,
	    318L,
	    -92563L,
	    4666L,
	    -314890L,
	    654321L,
	    638476L,
	    12345L,
	    1289396L,
	    -1232323L,
	    12839393L,
	    -231273683L,
	};
	static const long rtab[] = {
	    1,
	    3,
	    5,
	    4,
	    6,
	    6,
	    6,
	    5,
	    7,
	    7,
	    8,
	    9,
	};

	size_t i;

	for (i = 0; i < nelem(itab); i++)
		assert(count(itab[i]) == rtab[i]);

	return 0;
}
