/*

Bill and Ted are taking a road trip. But the odometer in their car is broken, so they don’t know how many miles they have driven.
Fortunately, Bill has a working stopwatch, so they can record their speed and the total time they have driven.
Unfortunately, their record keeping strategy is a little odd, so they need help computing the total distance driven. You are to write a program to do this computation.

For example, if their log shows

Speed in miles per hour | Total elapsed time in hours
20 2
30 6
10 7

this means they drove 2 hours at 20 miles per hour, then 6−2=4 hours at 30 miles per hour, then 7−6=1 hour at 10 miles per hour. The distance driven is then 2⋅20+4⋅30+1⋅10=40+120+10=170 miles.
Note that the total elapsed time is always since the beginning of the trip, not since the previous entry in their log.


Input

The input consists of one or more data sets (at most 10).
Each set starts with a line containing an integer n, 1≤n≤10, followed by n pairs of values, one pair per line.
The first value in a pair, s, is the speed in miles per hour and the second value, t, is the total elapsed time.
Both s and t are integers, 1≤s≤90 and 1≤t≤12. The values for t are always in strictly increasing order. A value of −1 for n signals the end of the input.

Output

For each input set, print the distance driven, followed by a space, followed by the word “miles”.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
distance(unsigned a[][2], size_t n)
{
	size_t i;
	unsigned r;

	if (n == 0)
		return 0;

	r = a[0][0] * a[0][1];
	for (i = 1; i < n; i++)
		r += a[i][0] * (a[i][1] - a[i - 1][1]);
	return r;
}

int
main(void)
{
	unsigned a1[][2] = {
	    {20, 2},
	    {30, 6},
	    {10, 7},
	};
	unsigned a2[][2] = {
	    {60, 1},
	    {30, 5},
	};
	unsigned a3[][2] = {
	    {15, 1},
	    {25, 2},
	    {30, 3},
	    {10, 5},
	};

	assert(distance(a1, nelem(a1)) == 170);
	assert(distance(a2, nelem(a2)) == 180);
	assert(distance(a3, nelem(a3)) == 90);

	return 0;
}
