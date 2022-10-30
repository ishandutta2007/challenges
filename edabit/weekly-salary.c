/*

Write a function that takes a list of hours and returns the total weekly salary.

    The input list hours is listed sequentially, ordered from Monday to Sunday.
    A worker earns $10 an hour for the first 8 hours.
    For every overtime hour, he earns $15.
    On weekends, the employer pays double the usual rate, regardless how many hours were worked previously that week.
    For instance, 10 hours worked on a weekday would pay 80+30 = $110, but on a weekend it would pay 160+60 = $220.

Examples

WeeklySalary([8, 8, 8, 8, 8, 0, 0]) ➞ 400

WeeklySalary([10, 10, 10, 0, 8, 0, 0]) ➞ 410

WeeklySalary([0, 0, 0, 0, 0, 12, 0]) ➞ 280

Notes

Every element in the array is greater than or equal to 0.

*/

#include <assert.h>
#include <stdio.h>

unsigned
salary(unsigned w[7])
{
	unsigned s, r, o, h;
	int i;

	s = 0;
	for (i = 0; i < 7; i++) {
		r = (i < 5) ? 10 : 20;
		o = (i < 5) ? 15 : 30;
		h = (w[i] <= 8) ? w[i] : 8;
		s += (h * r) + (w[i] - h) * o;
	}

	return s;
}

int
main(void)
{
	unsigned w1[] = {8, 8, 8, 8, 8, 0, 0};
	unsigned w2[] = {10, 10, 10, 0, 8, 0, 0};
	unsigned w3[] = {0, 0, 0, 0, 0, 12, 0};
	unsigned w4[] = {8, 8, 8, 8, 8, 8, 0};
	unsigned w5[] = {8, 8, 8, 8, 8, 8, 8};
	unsigned w6[] = {0, 0, 0, 0, 0, 0, 0};
	unsigned w7[] = {1, 1, 1, 2, 5, 0, 0};
	unsigned w8[] = {0, 0, 0, 0, 0, 16, 0};
	unsigned w9[] = {10, 10, 10, 10, 10, 10, 10};
	unsigned w10[] = {0, 12, 0, 12, 0, 8, 8};

	assert(salary(w1) == 400);
	assert(salary(w2) == 410);
	assert(salary(w3) == 280);
	assert(salary(w4) == 560);
	assert(salary(w5) == 720);
	assert(salary(w6) == 0);
	assert(salary(w7) == 100);
	assert(salary(w8) == 400);
	assert(salary(w9) == 990);
	assert(salary(w10) == 600);

	return 0;
}
