/*

Kepler’s Law states that the planets move around the sun in elliptical orbits with the sun at one focus. Kepler's 3rd law is The Law of Periods, according to which:

The square of the time period of the planet is directly proportional to the cube of the semimajor axis of its orbit.
You are given the Time periods (T1,T2) and Semimajor Axes (R1,R2) of two planets orbiting the same star.

Please determine if the Law of Periods is satisfied or not, i.e, if the constant of proportionality of both planets is the same.

Print "Yes" (without quotes) if the law is satisfied, else print "No".

Input Format

The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
Each test case consists a single line of input, containing four space-separated integers T1,T2,R1,R2.

Output Format

For each test case, output a single line containing one string — "Yes" or "No" (without quotes); the answer to the problem.

You may print each character of the answer in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤10^4
1≤T1,T2≤10
1≤R1,R2≤10

*/

#include <assert.h>
#include <stdbool.h>

bool
periods(int t1, int t2, int r1, int r2)
{
	return (t1 * t1) * (r2 * r2 * r2) == (t2 * t2) * (r1 * r1 * r1);
}

int
main(void)
{
	assert(periods(1, 1, 1, 1) == true);
	assert(periods(1, 2, 3, 4) == false);
	assert(periods(1, 8, 2, 8) == true);

	return 0;
}
