/*

While purchasing certain items, a discount of 10% is offered if the quantity purchased is more than 1000.
If the quantity and price per item are input, write a program to calculate the total expenses. 

*/

#include <stdio.h>

double
cost(int q, int p)
{
	if (q < 0 || p < 0)
		return 0;
	if (q < 1000)
		return q * p;
	return .9 * q * p;
}

int
main(void)
{
	printf("%lf\n", cost(100, 120));
	printf("%lf\n", cost(10, 20));
	printf("%lf\n", cost(1200, 20));
	return 0;
}
