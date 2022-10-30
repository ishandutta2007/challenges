/*

Create a function that takes the age and return the age in days.
Examples

calcAge(65) ➞ 23725

calcAge(0) ➞ 0

calcAge(20) ➞ 7300

Notes

Use 365 days as the length of a year for this challenge.
Ignore leap years and days between last birthday and now.
Expect only positive integer inputs.

*/

#include <assert.h>

unsigned
age2day(unsigned a)
{
	return a * 365;
}

int
main(void)
{
	assert(age2day(65) == 23725);
	assert(age2day(0) == 0);
	assert(age2day(20) == 7300);
	assert(age2day(10) == 3650);
	assert(age2day(73) == 26645);

	return 0;
}
