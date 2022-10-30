/*

Pooja would like to withdraw X $US from an ATM.
The cash machine will only accept the transaction if X is a multiple of 5,
and Pooja's account balance has enough cash to perform the withdrawal transaction (including bank charges).
For each successful withdrawal the bank charges 0.50 $US.
Calculate Pooja's account balance after an attempted transaction. 

*/

#include <stdio.h>

double
withdraw(int m, double t)
{
	if (m > t - .5)
		return t;
	if (m % 5 != 0)
		return t;
	return t - (m + .5);
}

int
main(void)
{
	printf("%.2lf\n", withdraw(30, 120));
	printf("%.2lf\n", withdraw(42, 120));
	printf("%.2lf\n", withdraw(300, 120));
	printf("%.2lf\n", withdraw(120, 120));
	printf("%.2lf\n", withdraw(115, 120));
	return 0;
}
