/*

Introduction
We all know and love our Fibonacci sequence and have seen a myriad of challenge on it here already. However, we're still lacking a very simple case which this answer is going to provide: Reversed fibonacci! So given F_n your job is to find n.

Specification
Input
Your input will be a non-negative integer, which is guaranteed to be part of the fibonacci sequence.

Output
The output must be a non-negative integer as well.

What to do?
The introduction already said: Given a fibonacci number, output its index. Fiboancci number hereby is defined as F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2) and you're given F(n) and must return n.

Potential Corner Cases
0 is a valid in- and output.
If given "1" as input you may either output "1" or "2", as you prefer.
You may always assume that your input actually is a fibonacci number.
You may assume that the input is representable as a 32-bit signed integer.

Who wins?
This is code-golf so the shortest answer in bytes wins!
Standard rules apply of course.

Test-cases
0 -> 0
2 -> 3
3 -> 4
5 -> 5
8 -> 6
13 -> 7
1836311903 -> 46

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

int
fibinv(uvlong n)
{
	uvlong a, b, c;
	int i;

	a = 0;
	b = 1;
	for (i = 0; a < n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return (a == n) ? i : -1;
}

int
main(void)
{
	assert(fibinv(0) == 0);
	assert(fibinv(2) == 3);
	assert(fibinv(3) == 4);
	assert(fibinv(5) == 5);
	assert(fibinv(8) == 6);
	assert(fibinv(13) == 7);
	assert(fibinv(1836311903ULL) == 46);

	return 0;
}
