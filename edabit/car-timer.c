/*

A built-in timer inside your car can count the length of your ride in minutes and you have started your ride at 00:00.

Given the number of minutes $n at the end of the ride, calculate the current time.
Return the sum of digits that the digital timer in the format hh:mm will show at the end of the ride.

Examples

carTimer(240) ➞ 4
// 240 minutes have passed since 00:00, the current time is 04:00
// Digits sum up is 0 + 4 + 0 + 0 = 4

carTimer(808) ➞ 14

carTimer(14) ➞ 5

*/

#include <assert.h>
#include <stdio.h>

unsigned
cartime(unsigned n)
{
	unsigned h, m;

	h = n / 60;
	m = n % 60;
	return (h / 10) + (m / 10) + (h % 10) + (m % 10);
}

int
main(void)
{
	assert(cartime(240) == 4);
	assert(cartime(808) == 14);
	assert(cartime(1439) == 19);
	assert(cartime(0) == 0);
	assert(cartime(23) == 5);
	assert(cartime(8) == 8);

	return 0;
}
