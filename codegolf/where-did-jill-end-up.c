/*

Jill lives in the (magnetic) north pole. One day, Jill decided to go for a walk, travelling in the four directions (north, east, west, south) for some lengths, with the help of a compass.
Your task is to find whether Jill ended up where Jill lives, i.e. the magnetic north pole.

Only south is defined at the north pole. Walking north or south changes the latitude, while walking east or west changes the longitude.
The longitude is not defined at the north pole.
As a result, Jill would have ended up at the north pole if and only if the distances Jill walked to the south sum up to be equal to the sum of the distances Jill walked to the north, and the distance Jill walked east and west do not matter.

Input
A list of pairs of (direction, amount). The input shall be valid. The amounts will be integers. Acceptable formats include:

"N200"
"200N"
200i (complex number)
(0, 200) (0123 for NESW)
(200,0) (the above reversed)
Output
Two consistent values, one for the case that Jill did end up in the magnetic north pole, and one for the case that Jill did not.

Testcases
Truthy inputs:

S100, E50, N50, W50, N50
S10, E1000, S30, W400, S10, W10, N50
S30, N30
S10, E50, E50, N10
Falsey inputs:

S100
S10, E314, N5
S300, W135, S10, E35, N290
Scoring
This is code-golf. Shortest answer in bytes wins. Standard loopholes apply.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
northpole(const char **s, size_t n)
{
	int sgn, y;
	size_t i;

	y = 0;
	for (i = 0; i < n; i++) {
		switch (s[i][0]) {
		case 'N':
			sgn = 1;
			break;
		case 'S':
			sgn = -1;
			break;
		default:
			continue;
		}

		y += sgn * atoi(s[i] + 1);
	}

	return y == 0;
}

int
main(void)
{
	static const char *s1[] = {
	    "S100",
	    "E50",
	    "N50",
	    "W50",
	    "N50",
	};
	static const char *s2[] = {
	    "S10",
	    "E1000",
	    "S30",
	    "W400",
	    "S10",
	    "W10",
	    "N50",
	};
	static const char *s3[] = {
	    "S30",
	    "N30",
	};
	static const char *s4[] = {
	    "S10",
	    "E50",
	    "E50",
	    "N10",
	};

	static const char *s5[] = {
	    "S100",
	};
	static const char *s6[] = {
	    "S10",
	    "E314",
	    "N5",
	};
	static const char *s7[] = {
	    "S300",
	    "W135",
	    "S10",
	    "E35",
	    "N290",
	};

	assert(northpole(s1, nelem(s1)) == true);
	assert(northpole(s2, nelem(s2)) == true);
	assert(northpole(s3, nelem(s3)) == true);
	assert(northpole(s4, nelem(s4)) == true);

	assert(northpole(s5, nelem(s5)) == false);
	assert(northpole(s6, nelem(s6)) == false);
	assert(northpole(s7, nelem(s7)) == false);

	return 0;
}
