/*

I'm writing a program that takes a number from input (call it x), loops from 0 to (x - 1) (let's call our iterator y) and prints y^x+x for each y.

After the loop, it then prints "SUM: N" (without a newline) where the N is the sum of the all of the previously printed values.

How can I make the code I already have shorter?

Code (Python 3, 98 bytes):

E=print
A=int(input())
B=[]
for D in range(A):C=D**A+A;B.append(C);E(C)
E(end='SUM: '+str(sum(B)))

*/

#include <stdio.h>
#include <math.h>

typedef unsigned long long uvlong;

void
seq(uvlong n)
{
	uvlong a, b, i;

	a = b = 0;
	for (i = 0; i < n; i++) {
		a = pow(i, n) + n;
		b += a;
		printf("%llu\n", a);
	}
	printf("SUM: %llu\n", b);
}

int
main(void)
{
	seq(10);
	return 0;
}
