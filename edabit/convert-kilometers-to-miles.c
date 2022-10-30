/*

In this challenge, you have to implement a function that returns the given distance kilometers converted into miles.
You have to round the result up to the fifth decimal digit.

*/

#include <stdio.h>

double
kmtomiles(double km)
{
	return km * 0.621371;
}

int
main(void)
{
	printf("%.5f\n", kmtomiles(2));
	printf("%.5f\n", kmtomiles(6));
	printf("%.5f\n", kmtomiles(8));
	return 0;
}
