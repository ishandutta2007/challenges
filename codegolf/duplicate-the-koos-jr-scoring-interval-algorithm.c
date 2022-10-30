/*

Inspired from a real problem; we were looking at this table and said "Hey, now that's a good codegolf problem."

The KOOS Jr. scores converts from a raw number to a percentile score given this table:

Raw summed score  Interval score
(0-28)            (0 to 100 scale)
 0                100.000
 1                 91.975
 2                 84.600
 3                 79.914
 4                 76.332
 5                 73.342
 6                 70.704
 7                 68.284
 8                 65.994
 9                 63.776
10                 61.583
11                 59.381
12                 57.140
13                 54.840
14                 52.465
15                 50.012
16                 47.487
17                 44.905
18                 42.281
19                 39.625
20                 36.931
21                 34.174
22                 31.307
23                 28.251
24                 24.875
25                 20.941
26                 15.939
27                  8.291
28                  0.000

Provide a program, function, expression, or source file generator* that given the input raw number returns the interval score number.
You may accept your input as a string or number and may produce your output as a string or number. Trailing zeros after the decimal point may be included or omitted.
You may not however use scaled integers: 1 must really return 91.975 not 91975.

*source file generator must output a valid source file for some language you specify; just outputting the table is not allowed.

*/

#include <assert.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
score(unsigned n)
{
	static const double tab[] = {
	    100.000,
	    91.975,
	    84.600,
	    79.914,
	    76.332,
	    73.342,
	    70.704,
	    68.284,
	    65.994,
	    63.776,
	    61.583,
	    59.381,
	    57.140,
	    54.840,
	    52.465,
	    50.012,
	    47.487,
	    44.905,
	    42.281,
	    39.625,
	    36.931,
	    34.174,
	    31.307,
	    28.251,
	    24.875,
	    20.941,
	    15.939,
	    8.291,
	    0.000,
	};

	if (n < nelem(tab))
		return tab[n];
	return -1;
}

int
main(void)
{
	assert(score(1) == 91.975);

	return 0;
}
