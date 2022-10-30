/*

"Usain Bolt makes a new world record completing 100 m in 9.58 seconds".

This news headline has been echoing in Chef's mind since 2009 when he started his career in sprinting. This time in the 2021 Tokyo Olympics he is determined to make a new world record.

There are mainly 3 important factors that result in the variation in speed during practice and during competition.

The first factor is a difference in track material which results in variation in the speed at competition with respect to practice by a factor of k1.

The second factor is wind speed which results in variation in the speed at competition with respect to practice by a factor of k2.

The final factor is the maximum speed achieved during practice. If the maximum speed during practice is v m/s then in competition it will be k3∗v m/s.

Given Chef's max speed v during practice and the factors k1,k2,k3, find whether he will be able to create a new world record, i.e, can he complete 100 m in less than 9.58 seconds?

Note: The final time displayed by the Olympics clock is showing after rounding the original time to 2 places of decimal and is the only measure of runners performance.

Input:

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, four floats k1,k2,k3,v.

Output:

Output in a single line, the answer, which should be "YES" if it's possible for Chef to create a new world record and "NO" if not.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤10^5
0<k1,k2<2
0<k3≤1
9<v<11
k1,k2,k3 contain 1 digit after decimal.
v contains 2 digits after decimal.

*/

#include <assert.h>
#include <stdbool.h>
#include <math.h>

bool
breaker(double k1, double k2, double k3, double v)
{
	double s, t;

	s = k1 * k2 * k3 * v;
	t = 100.0 / s;
	t = round(100.0 * t) / 100.0;
	return t < 9.58;
}

int
main(void)
{
	assert(breaker(1.0, 1.0, 1.0, 10.45) == true);
	assert(breaker(1.0, 1.0, 1.0, 10.44) == false);
	assert(breaker(1.0, 1.0, 0.9, 10.44) == false);

	return 0;
}
