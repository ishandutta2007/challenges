/*

In this problem, you need to print the pattern of the following form containing the numbers from 1 to n.

                            4 4 4 4 4 4 4  
                            4 3 3 3 3 3 4   
                            4 3 2 2 2 3 4   
                            4 3 2 1 2 3 4   
                            4 3 2 2 2 3 4   
                            4 3 3 3 3 3 4   
                            4 4 4 4 4 4 4   

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

void
approx_print(int n)
{
	int c, i, j, s;
	double x, y, r, r1, r2;

	s = 2 * n - 1;
	c = s / 2;
	for (i = 0; i < s; i++) {
		for (j = 0; j < s; j++) {
			x = c - i;
			y = c - j;

			// does not work on higher n
			// to do this right, need to figure out relationship between n
			// and the division constant
			x /= 1.45;
			y /= 1.45;

			r1 = hypot(max(x, y), max(x, y));
			r2 = hypot(min(x, y), min(x, y));
			r = max(r1, r2) + 1;
			printf("%.0f ", r);
		}
		printf("\n");
	}
	printf("\n");
}

void
print(int n)
{
	int i, j, s, m;

	s = 2 * n - 1;
	for (i = 0; i < s; i++) {
		for (j = 0; j < s; j++) {
			m = min(i, j);
			m = min(m, s - i - 1);
			m = min(m, s - j - 1);
			printf("%d ", n - m);
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	print(2);
	print(4);
	print(5);
	print(10);
	print(20);
	approx_print(2);
	approx_print(4);
	approx_print(5);
	approx_print(10);
	approx_print(20);
	return 0;
}
