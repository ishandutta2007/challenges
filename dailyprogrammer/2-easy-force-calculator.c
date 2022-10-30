/*

Hello, coders! An important part of programming is being able to apply your programs, so your challenge for today is to create a calculator application that has use in your life.
It might be an interest calculator, or it might be something that you can use in the classroom. For example, if you were in physics class, you might want to make a F = M * A calc.

EXTRA CREDIT: make the calculator have multiple functions! Not only should it be able to calculate F = M * A, but also A = F/M, and M = F/A!

*/

#include <stdio.h>

double
force(double mass, double acceleration)
{
	return mass * acceleration;
}

int
main(void)
{
	printf("%f\n", force(1, 9.8));

	return 0;
}
