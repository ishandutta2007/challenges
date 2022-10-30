/*
HackerLand University has the following grading policy:

Every student receives a grade in the inclusive range from 0 to 100.
Any grade less than 40 is a failing grade. 

Sam is a professor at the university and likes to round each student's grade according to these rules:

If the difference between the grade and the next multiple of 5 is less than 3, round up to the next multiple of 5.
If the value of grade is less than 38, no rounding occurs as the result will still be a failing grade.

For example, grade=84 will be rounded to 85 but grade=29 will not be rounded because the rounding would result in a number that is less than 40.

Given the initial value of grade for each of Sam's n students, write code to automate the rounding process.

*/

#include <stdio.h>

int
grade(int g)
{
	int n;

	if (g >= 38) {
		n = g % 5;
		if (n > 2)
			g += 5 - n;
	}
	return g;
}

int
main(void)
{
	printf("%d\n", grade(84));
	printf("%d\n", grade(29));
	printf("%d\n", grade(73));
	printf("%d\n", grade(67));
	printf("%d\n", grade(38));
	printf("%d\n", grade(33));
	return 0;
}
