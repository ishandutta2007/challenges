/*

Tom is a very methodic guy that loves geometry and pizza: he loves them so much that, before eating a pizza, he calculates its radius and its height. Now, he wants to know from you the total volume of pizza that he swallowed!

You are given the two parameters that Tom measured:

    radius
    height

He tells you that if you multiply the height for the square of the radius and multiply the result for the mathematical constant π (Pi), you will obtain the total volume of the pizza.
Implement a function that returns the volume of the pizza as a whole number, rounding it to the nearest integer (and rounding up for numbers with .5 as decimal part).

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
volpizza(double r, double h)
{
	return M_PI * r * r * h;
}

int
main(void)
{
	printf("%.0lf\n", volpizza(1, 1));
	printf("%.0lf\n", volpizza(7, 2));
	printf("%.0lf\n", volpizza(10, 2.5));
	printf("%.0lf\n", volpizza(15, 1.3));
	printf("%.0lf\n", volpizza(20, 1));
	printf("%.0lf\n", volpizza(13, 2));
	return 0;
}
