/*

A vehicle needs 10 times the amount of fuel than the distance it travels.
However, it must always carry a minimum of 100 fuel before setting off.

Create a function which calculates the amount of fuel it needs, given the distance.

Examples

calculateFuel(15) ➞ 150

calculateFuel(23.5) ➞ 235

calculateFuel(3) ➞ 100

Notes

    Distance will be a number greater than zero.
    Return 100 if the calculated fuel turns out to be less than 100.

*/

#include <assert.h>
#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

double
fuel(double d)
{
	return max(d * 10, 100);
}

int
main(void)
{
	assert(fuel(15) == 150);
	assert(fuel(23) == 230);
	assert(fuel(10) == 100);
	assert(fuel(3) == 100);
	assert(fuel(23.5) == 235);
	assert(fuel(3.14) == 100);
	assert(fuel(9.99999) == 100);
	assert(fuel(822315322.0) == 8223153220.0);
	assert(fuel(12345.6789) == 123456.789);
	assert(fuel(31.41) == 314.1);
	assert(fuel(54) == 540);
	assert(fuel(46.6) == 466);

	return 0;
}
