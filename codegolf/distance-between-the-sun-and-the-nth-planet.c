/*

Challenge
Predict the distance between the Sun and the nth planet when using any formula that gives the same result as the Titius–Bode law: d=(3*2^n+4)/10.

BUT WAIT... there is one restriction:

Your source code can not include any of the Titius–Bode law's digits
So, your program can not contain the characters 0, 1, 2, 3, or 4
Input
n a non-negative integer value:

For Mercury n is -∞ no need to handle this case.
n=0 for Venus
n=1 for Earth
n=2 for Mars, and so on ...

Output
Distance in astronomical unit between the Sun and the nth planet (decimal with at least one decimal place).

Titius–Bode law
Distance in astronomical unit between the Sun and the nth planet is estimated by d=(3*2^n+4)/10.

Example
0          --> 0.7
1          --> 1.0 or 1
11         --> 614.8

Rules
The input and output can be given in any convenient format.
No need to handle invalid input values
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
If possible, please include a link to an online testing environment so other people can try out your code!
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

#include <stdio.h>
#include <math.h>

double
distance(double n)
{
	return ((3 * pow(2, n)) + 4) / 10;
}

int
main(void)
{
	int i;

	for (i = 0; i <= 11; i++)
		printf("%d %.2f\n", i, distance(i));

	return 0;
}
