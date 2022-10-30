/*

Machine epsilon is an important floating point number to know when doing numerical calculations. One way to understand it is when this relation

1 + machine_epsilon > 1

does not hold. One (iterative) way to extract it is executing a small program like the one above:

10 EPS=1
20 EPS=EPS/2
30 EPS1 = 1+EPS
40 IF EPS1 > 1 GOTO 20
50 PRINT EPS

But there may be more ways. Write the shortest code to extract the machine epsilon of your computer. NOTE: epsilon should be a non-zero value :)

*/

#include <stdio.h>

double
epsilon(void)
{
	double e, p;

	e = 1;
	do {
		e /= 2;
		p = 1 + e;
	} while (p > 1);
	return e;
}

int
main(void)
{
	printf("%.8g\n", epsilon());
	return 0;
}
