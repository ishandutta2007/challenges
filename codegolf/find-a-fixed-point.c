/*

Given an integer x1 and some black box function f:Z→Z find a fixed point of f in the sequence defined by xk+1:=f(xk).

Details

    A value x

is said to be a fixed point of f if x=f(x).

For instance if f(x)=round(x/π)
and we have a starting point x1=10 then we get x2=f(x1)=f(10)=3, then x3=f(x2)=f(3)=1, then x4=f(x3)=f(1)=0, and finally x5=f(x4)=f(0)=0 which means the submission should return 0.

    You can assume that the generated sequence actually contains a fixed point.
    You can use the native type for integers in place of Z.

    You can use any language for which there are defaults for black box functions input in the standard IO meta post. If there are no such default for your language feel free to add one in the sense of the definition of black box functions, and make sure to link your proposals in that definition. Also don't forget to vote on them.

Examples

f(x) = floor(sqrt(abs(x)))
0 -> 0,  all other numbers -> 1

f(x) = c(c(c(x))) where c(x) = x/2 if x is even; 3*x+1 otherwise
all positive numbers should result in 1,2 or 4 (Collatz conjecture)

f(x) = -42
all numbers -> -42

f(x) = 2 - x
1 -> 1

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
fixedpoint(int x, int (*f)(int))
{
	int y;

	for (;;) {
		y = f(x);
		if (y == x)
			break;
		x = y;
	}
	return y;
}

int
f1(int x)
{
	return sqrt(abs(x));
}

int
f2(int x)
{
	(void)x;
	return -42;
}

int
f3(int x)
{
	return 2 - x;
}

int
f4(int x)
{
	return x / 2;
}

int
main(void)
{
	printf("%d\n", fixedpoint(12, f1));
	printf("%d\n", fixedpoint(45, f2));
	printf("%d\n", fixedpoint(1, f3));
	printf("%d\n", fixedpoint(24, f4));
	return 0;
}
