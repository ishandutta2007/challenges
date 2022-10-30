/*

Create a function that takes a number n as an argument and checks whether the given number can be expressed as a sum of two or more consecutive positive numbers.

Examples

consecutiveSum(9) ➞ true
// 9 can be expressed as a sum of (2 + 3 + 4) or (4 + 5).

consecutiveSum(10) ➞ true
// 10 can be expressed as a sum of 1 + 2 + 3 + 4.

consecutiveSum(64) ➞ false

Notes

N/A

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef unsigned long long uvlong;

// https://en.wikipedia.org/wiki/Polite_number
bool
consum(uvlong n)
{
	return (n & (n - 1)) != 0;
}

int
main(void)
{
	assert(consum(9ull) == true);
	assert(consum(10ull) == true);
	assert(consum(64ull) == false);
	assert(consum(69ull) == true);
	assert(consum(8ull) == false);
	assert(consum(57ull) == true);
	assert(consum(6ull) == true);
	assert(consum(13ull) == true);
	assert(consum(16ull) == false);
	assert(consum(91ull) == true);
	assert(consum(75ull) == true);
	assert(consum(38ull) == true);
	assert(consum(25ull) == true);
	assert(consum(32ull) == false);
	assert(consum(65ull) == true);
	assert(consum(13ull) == true);
	assert(consum(16ull) == false);
	assert(consum(99ull) == true);
	assert(consum(522ull) == true);
	assert(consum(974ull) == true);
	assert(consum(755ull) == true);
	assert(consum(512ull) == false);
	assert(consum(739ull) == true);
	assert(consum(1006ull) == true);
	assert(consum(838ull) == true);
	assert(consum(1092ull) == true);
	assert(consum(727ull) == true);
	assert(consum(648ull) == true);
	assert(consum(1024ull) == false);
	assert(consum(851ull) == true);
	assert(consum(541ull) == true);
	assert(consum(1011ull) == true);
	assert(consum(822ull) == true);
	assert(consum(382131ull) == true);
	assert(consum(118070ull) == true);
	assert(consum(17209ull) == true);
	assert(consum(32768ull) == false);
	assert(consum(161997ull) == true);
	assert(consum(400779ull) == true);
	assert(consum(198331ull) == true);
	assert(consum(325482ull) == true);
	assert(consum(88441ull) == true);
	assert(consum(648ull) == true);
	assert(consum(65536ull) == false);
	assert(consum(323744ull) == true);
	assert(consum(183540ull) == true);
	assert(consum(65271ull) == true);
	assert(consum(5263987ull) == true);

	return 0;
}
