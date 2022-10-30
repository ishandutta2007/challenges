/*

Description:

A powerplant for the city of Redmond goes offline every third day because of local demands.
Ontop of this, the powerplant has to go offline for maintenance every 100 days.
Keeping things complicated, on every 14th day, the powerplant is turned off for refueling.
Your goal is to write a function which returns the number of days the powerplant is operational given a number of days to simulate.

Formal Inputs & Outputs:

Input Description:

Integer days - the number of days we want to simulate the powerplant

Output Description:

Return the number of days the powerplant is operational.

Sample Inputs & Outputs:

The function, given 10, should return 7 (3 days removed because of maintenance every third day).

*/

#include <assert.h>
#include <stdio.h>

int
powerplant(int d)
{
	int i, r;

	if (d < 0)
		d = 0;

	r = d;
	for (i = 1; i <= d; i++) {
		if (i % 3 == 0 || i % 14 == 0 || i % 100 == 0)
			r--;
	}
	return r;
}

int
main(void)
{
	assert(powerplant(3) == 2);
	assert(powerplant(6) == 4);
	assert(powerplant(10) == 7);
	assert(powerplant(5991) == 3675);

	return 0;
}
