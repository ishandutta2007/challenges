/*

Create a function that takes the number of daily average recovered cases recovers, daily average newCases, current activeCases, and returns the number of days it will take to reach zero cases.

Examples

endCorona(4000, 2000, 77000) ➞ 39

endCorona(3000, 2000, 50699) ➞ 51

endCorona(30000, 25000, 390205) ➞ 79

Notes

    The number of people who recover per day recovers will always be greater than daily newCases.
    Be conservative and round up the number of days needed.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long long vlong;

vlong
endcorona(vlong r, vlong n, vlong s)
{
	return ceil(s * 1.0 / (r - n));
}

int
main(void)
{
	assert(endcorona(4000LL, 2000LL, 77000LL) == 39LL);
	assert(endcorona(3000LL, 2000LL, 50699LL) == 51LL);
	assert(endcorona(30000LL, 25000LL, 390205LL) == 79LL);
	assert(endcorona(260000LL, 255000LL, 20511691LL) == 4103LL);

	return 0;
}
