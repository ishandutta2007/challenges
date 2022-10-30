/*

The teacher has sent an e-mail to her students with the following task: “Write a program that will determine and output the value of X if given the statement:

X=number^pow11+number^pow22+…+number^powNN and it holds that number1, number2 to numberN are integers, and pow1, pow2 to powN are one-digit integers.”

Unfortunately, when the teacher downloaded the task to her computer, the text formatting was lost so the task transformed into a sum of N integers:

X=P1+P2+…+PN

For example, without text formatting, the original task in the form of X=21^2+125^3 became a task in the form of X=212+1253.
Help the teacher by writing a program that will, for given N integers from P1 to PN determine and output the value of X from the original task.

Input

The first line of input contains the integer N (1≤N≤10), the number of the addends from the task. Each of the following N lines contains the integer Pi (10≤Pi≤9999, i=1,…,N) from the task.

Output

The first and only line of output must contain the value of X
(X≤1000000000) from the original task.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
pot(uvlong *a, size_t n)
{
	uvlong r;
	size_t i;

	r = 0;
	for (i = 0; i < n; i++)
		r += pow(a[i] / 10, a[i] % 10);
	return r;
}

int
main(void)
{
	uvlong a1[] = {212, 1253};
	uvlong a2[] = {23, 17, 43, 52, 22};
	uvlong a3[] = {213, 102, 45};

	assert(pot(a1, nelem(a1)) == 1953566ull);
	assert(pot(a2, nelem(a2)) == 102ull);
	assert(pot(a3, nelem(a3)) == 10385ull);

	return 0;
}
