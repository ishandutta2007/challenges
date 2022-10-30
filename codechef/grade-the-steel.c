/*

A certain grade of steel is graded according to the following conditions.
Hardness must be greater than 50.
Carbon content must be less than 0.7.
Tensile strength must be greater than 5600.


The grades are as follows:
Grade is 10 if all three conditions are met.
Grade is 9 if conditions (i) and (ii) are met.
Grade is 8 if conditions (ii) and (iii) are met.
Grade is 7 if conditions (i) and (iii) are met.
Garde is 6 if only one condition is met.
Grade is 5 if none of three conditions are met.

Write a program, if the user gives values of hardness, carbon content and tensile strength of the steel under consideration and display the grade of the steel. 

*/
#include <stdio.h>

int
grade(double h, double c, double t)
{
	double H, C, T;

	H = 50;
	C = 0.7;
	T = 5600;
	if (h > H && c < C && t > T)
		return 10;
	if (h > H && c < C && !(t > T))
		return 9;
	if (!(h > H) && c < C && t > T)
		return 8;
	if (h > H && !(c < C) && t > T)
		return 7;
	if (h > H || c < C || t > T)
		return 6;
	return 5;
}

int
main(void)
{
	printf("%d\n", grade(53, 0.6, 5602));
	printf("%d\n", grade(45, 0, 4500));
	printf("%d\n", grade(0, 0, 0));
	printf("%d\n", grade(20, 1.2, 5));
	return 0;
}
