/*

Fat is a very popular kid, but unfortunately his grades are not directly proportional to his amount of friends.
Orial, one of Fat’s friends, was determined to help Fat and decided to call you to make a program.
Currently, the total average grade of Fat is N, and he has already attended A disciplines.
Fat wishes to achieve the total average grade of M by the time he has attended B more disciplines.
Help Orial to make a program that helps Fat estimate the average grade he should score on the next B disciplines so that he achieves the total average grade of M.
The grading system is such that it’s impossible to score a grade lower than 0 or bigger than 10.

Input
The first line contains T (T ≤ 10^5) — the number of test cases, after this line T test cases follows.
Each test case is arranged in a line containing the numbers N, M, A and B (0 ≤ N, M ≤ 10; 1 ≤ A, B ≤ 100) in a single line —
Fat’s current total average grade, desired total average grade, amount of disciplines he has attended and amount of disciplines he will attend, correspondingly.
N and M are real numbers, and A and B are integers.

Output
For each test case print a line containing ‘Case #X: Y ’, where X is the case number, starting at 1, and Y is either a floating point number,
which is the average grade that Fat should score from now on to obtain the desired total average grade, or ‘Impossible’ if it’s impossible to obtain such an average grade.
In the case where it’s possible to achieve the goal, Y should be rounded up to 2 digits after the decimal point.
The input will be in a way that errors up to 10−3 will still give the correct answer.

Sample Input
3
7 8 1 1
7 9 5 2
9.05 9.20 28 20

Sample Output
Case #1: 9.00
Case #2: Impossible
Case #3: 9.41

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
grade(double n, double m, double a, double b)
{
	double r;

	r = ((m * (a + b)) - (n * a)) / b;
	if (r < 0 || r > 10)
		r = -1;
	return r;
}

void
test(double n, double m, double a, double b, double r)
{
	double p;

	p = grade(n, m, a, b);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-2);
}

int
main(void)
{
	test(7, 8, 1, 1, 9);
	test(7, 9, 5, 2, -1);
	test(9.05, 9.20, 28, 20, 9.41);

	return 0;
}
