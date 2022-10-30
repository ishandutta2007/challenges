/*

A Smith number is a composite number for which, in a given base (in base 10 by default),
the sum of its digits is equal to the sum of the digits in its prime factorization.
For example, 378 = 2 × 3 × 3 × 3 × 7 is a Smith number since 3 + 7 + 8 = 2 + 3 + 3 + 3 + 7.
In this definition the factors are treated as digits: for example
22 factors to 2 × 11 and yields three digits: 2, 1, 1. Therefore 22 is a Smith number because 2 + 2 = 2 + 1 + 1.

Write a function to see if a number is a smith number

*/

#include <stdio.h>
#include <math.h>

int
sumdigit(int n)
{
	int s;

	for (s = 0; n != 0; n /= 10)
		s += n % 10;
	return s;
}

int
issmith(int n)
{
	int f, a, b, i, m;

	if (n <= 1)
		return 0;

	a = 0;
	m = n;
	f = 0;
	for (i = 2; m != 1; i++) {
		while (m % i == 0) {
			m /= i;
			a += sumdigit(i);
			f++;
		}
	}
	b = sumdigit(n);

	return a == b && f != 1;
}

int
main(void)
{
	int i;
	for (i = 0; i <= 1000; i++) {
		if (issmith(i))
			printf("%d\n", i);
	}
	printf("%d\n", issmith(4937775));
	return 0;
}
