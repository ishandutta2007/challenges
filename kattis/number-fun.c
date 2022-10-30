/*

Ms. Greene is trying to design a game for her third-grade class to practice their addition, subtraction, multiplication, and division.
She would like for every student in her class to be able to “think mathematically” and determine if any two given numbers can be added, subtracted, multiplied, or divided in any way to produce a third given number.
However, she would like to be able to check her students’ work quickly without having to think about it herself.

Help Ms. Greene by writing a program that inputs two given numbers and determines whether or not it is possible to add, subtract, multiply, or divide those two numbers in any order to produce the third number.
Only one operation may be used to produce the third number.

Input

Each input file will start with a single integer N (1≤N≤10000) denoting the number of test cases. The following N lines will contain sets of 3 numbers a,b,c (1≤a,b,c≤10000).

Output

For each test case, determine whether or not it is possible to produce the third number, c, using the first two numbers, a and b, using addition, subtraction, multiplication, or division.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
check(int a, int b, int c)
{
	if (a + b == c)
		return 1;
	if (a - b == c)
		return 1;
	if (a * b == c)
		return 1;
	if (b && !(a % b) && a / b == c)
		return 1;
	return 0;
}

const char *
satisfy(int a, int b, int c)
{
	if (check(a, b, c) || check(b, a, c))
		return "Possible";
	return "Impossible";
}

void
test(int a, int b, int c, const char *r)
{
	const char *p;

	p = satisfy(a, b, c);
	printf("%d %d %d %s\n", a, b, c, p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test(1, 2, 3, "Possible");
	test(2, 24, 12, "Possible");
	test(5, 3, 1, "Impossible");
	test(9, 16, 7, "Possible");
	test(7, 2, 14, "Possible");
	test(12, 4, 2, "Impossible");
	return 0;
}
