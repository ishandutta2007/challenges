/*

Create a function that takes voltage and current and returns the calculated power.
Examples

circuitPower(230, 10) ➞ 2300

circuitPower(110, 3) ➞ 330

circuitPower(480, 20) ➞ 9600

Notes

Requires basic calculation of electrical circuits (see Resources for info).

*/

#include <assert.h>

int
power(int v, int i)
{
	return v * i;
}

int
main(void)
{
	assert(power(230, 10) == 2300);
	assert(power(480, 20) == 9600);
	assert(power(110, 3) == 330);
	assert(power(13800, 276) == 3808800);

	return 0;
}
