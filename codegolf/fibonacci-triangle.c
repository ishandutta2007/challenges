/*

Given an integer n, output the following ASCII art to n rows:

1+1=2
  1+2=3
    2+3=5
      3+5=8
        5+8=13

Essentially, the first row is 1+1=2 and the nth row (1-indexed) is fn+fn+1=fn+2 where f is the Fibonacci sequence, padded so the numbers line up with the previous row.

You may instead output it infinitely. You may output a list of lines.

This is code-golf, shortest wins!

Testcase

The output for 20 should be:

1+1=2
  1+2=3
    2+3=5
      3+5=8
        5+8=13
          8+13=21
            13+21=34
               21+34=55
                  34+55=89
                     55+89=144
                        89+144=233
                           144+233=377
                               233+377=610
                                   377+610=987
                                       610+987=1597
                                           987+1597=2584
                                               1597+2584=4181
                                                    2584+4181=6765
                                                         4181+6765=10946
                                                              6765+10946=17711

*/

#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
spaces(uvlong n)
{
	uvlong s;

	if (n == 0)
		return 2;

	for (s = 1; n; n /= 10)
		s++;
	return s;
}

void
trifib(uvlong n)
{
	uvlong a, b, c;
	uvlong i, j, p;

	printf("N=%llu\n", n);
	a = b = 1;
	for (i = p = 0; i < n; i++) {
		c = a + b;

		for (j = 0; j < p; j++)
			printf(" ");
		printf("%llu+%llu=%llu\n", a, b, c);
		p += spaces(a);

		a = b;
		b = c;
	}
	printf("\n");
}

int
main(void)
{
	trifib(20);
	trifib(32);

	return 0;
}
