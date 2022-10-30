/*
HackerLand University has the following grading policy:

Every student receives a  in the inclusive range from 0 to 100
Any grade less than 40 is a failing grade.
Sam is a professor at the university and likes to round each student's grade according to these rules:

If the difference between the grade and the next multiple of 5 is less than 3, round grade up to the next multiple of 5.
If the value of grade is less than 38, no rounding occurs as the result will still be a failing grade.
For example, 84 will be rounded to 85 but 29 will not be rounded because the rounding would result in a number that is less than 40.

Given the initial value of grade for each of Sam's students, write code to automate the rounding process.
*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
clamp(int x, int a, int b)
{
	if (x < a)
		x = a;
	if (x > b)
		x = b;
	return x;
}

int *
grade(int *a, size_t n)
{
	int *p, r, v;
	size_t i;

	p = malloc(n);
	if (p == NULL)
		return NULL;

	for (i = 0; i < n; i++) {
		v = clamp(a[i], 0, 100);

		p[i] = v;
		if (v < 38)
			continue;

		r = 5 * (v / 5 + 1);
		if (r - v < 3)
			p[i] = r;
	}

	return p;
}

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int
main(void)
{
	int a[] = {84, 29, 73, 67, 38, 33};
	int *p;

	p = grade(a, nelem(a));
	print(p, nelem(a));
	free(p);
	return 0;
}
