/*

In a company an emplopyee is paid as under: If his basic salary is less than Rs. 1500, then HRA = 10% of base salary and DA = 90% of basic salary.
If his salary is either equal to or above Rs. 1500, then HRA = Rs. 500 and DA = 98% of basic salary. If the Employee's salary is input, write a program to find his gross salary.

NOTE: Gross Salary = Basic Salary + HRA + DA 

*/
#include <stdio.h>

double
gross(double b)
{
	double hra, da;

	if (b < 1500) {
		hra = .1 * b;
		da = .9 * b;
	} else {
		hra = 500;
		da = .98 * b;
	}
	return b + hra + da;
}

int
main(void)
{
	printf("%.2lf\n", gross(1203));
	printf("%.2lf\n", gross(10042));
	printf("%.2lf\n", gross(1312));
	return 0;
}
