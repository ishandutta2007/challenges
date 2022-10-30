/*

The Challenge
Write a program that can calculate how many times and how long a ball will bounce based on a few input variables.

Input
There are three variables that will be passed. You can accept these however you like (user input, function call, etc). The variables are as follows:

height
velocity
"bounciness"
They must be passed in this order.

Height
Height will be expressed as an integer, H, where 10^6 ≥ H ≥ 10. The height is measured in arbitrary units, u, which have no effect on your program's output.

Velocity
The velocity of the ball will be represented by an integer, V, where 10^6 ≥ V ≥ 1. It is expressed as Vu/s (V units per second).

Bounciness
The "bounciness" will be expressed as a decimal, B, where 0.00 ≤ B < 1.00. The maximum precision of B will be the hundredths place (two digits after the decimal point).

Output
You output will be two integers representing:

number of times the ball will bounce before coming to rest, N

how long it takes the ball to complete all of these bounces, T

Calculation
To calculate the number of times the ball will bounce, you would continuously multiply the current height by the "bounciness" until it dipped below 1. Once the result gets below 1, you should round the height down to 0, and stop calculating.

Each time these two are multiplied, the time is incremented by the quotient of the current height and velocity.

Intermediary calculations should have a minimum precision to the ten-thousandths (four digits after the decimal).

Example 1
If the input is:

10 10 0.5
The following table shows the necessary calculations for each bounce:

Height          Next       Height             Bounces
------        -------      ------             -------
10.0000       10.0000    *   0.5    = 5.0000        1
 5.0000        5.0000    *   0.5    = 2.5000        1
 2.5000        2.5000    *   0.5    = 1.2500        1
 1.2500        1.2500    *   0.5    = 0.6250        1

                                              -------
                                Total Bounces:      4

   Time added
----------------
10.0000    /  10   =   1.0000
 5.0000    /  10   =   0.5000
 2.5000    /  10   =   0.2500
 1.2500    /  10   =   0.1250

                       ------
           Total Time: 1.8750
At this point, the computation terminates because the height is less than 1. The time is rounded up to yield 2. These two integers should then either be returned or output as a string in this form:

4 2
Example 2
If the input is:

50 15 0.7
The following table shows the necessary calculations for each bounce:

Height      Next                  Height     Bounces
------     -------                -------    -------
50.0000    50.0000  *   0.7    =  35.0000          1
35.0000    35.0000  *   0.7    =  24.5000          1
24.5000    24.5000  *   0.7    =  17.1500          1
17.1500    17.2500  *   0.7    =  12.0050          1
12.0050    12.0050  *   0.7    =   8.4035          1
 8.4035     8.4035  *   0.7    =   5.8825          1
 5.8825     5.8825  *   0.7    =   4.1177          1
 4.1177     4.1177  *   0.7    =   2.8824          1
 2.8824     2.8824  *   0.7    =   2.0177          1
 2.0177     2.0177  *   0.7    =   1.4124          1
 1.4124     1.4124  *   0.7    =   0.9887          1

                                            --------
                              Total Bounces:      11

Time added
-----------
50.0000    /  15   =     3.3333
35.0000    /  15   =     2.3333
24.5000    /  15   =     1.6333
17.1500    /  15   =     1.1433
12.0050    /  15   =     0.8003
 8.4035    /  15   =     0.5602
 5.8825    /  15   =     0.3922
 4.1177    /  15   =     0.2745
 2.8824    /  15   =     0.1922
 2.0177    /  15   =     0.1345
 1.4124    /  15   =     0.0942

                     ----------
          Total Time:   10.8913
At this point, the computation terminates because the height is less than 1. The time is rounded up to give 11. These two integers should then either be returned or output as a string in this form:

11 11

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

void
dynamics(double h, double v, double b, double *n, double *t)
{
	if (!(0 <= b && b <= 1)) {
		*n = *t = -1;
		return;
	}

	*n = *t = 0;
	for (; h > 1; h *= b) {
		*t += h / v;
		*n += 1;
	}
	*t = ceil(*t);
}

void
test(double h, double v, double b, double rn, double rt)
{
	static const double eps = 1e-4;
	double n, t;

	dynamics(h, v, b, &n, &t);
	printf("%f %f\n", n, t);
	assert(fabs(n - rn) < eps);
	assert(fabs(t - rt) < eps);
}

int
main(void)
{
	test(10, 10, 0.5, 4, 2);
	test(50, 15, 0.7, 11, 11);

	return 0;
}
