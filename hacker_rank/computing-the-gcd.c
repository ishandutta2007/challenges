// In this challenge, we learn how to compute GCD using
// the Euclidean algorithm.

#include <stdio.h>

int
gcd(int a, int b)
{
	int t;
	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int
main(void)
{
	printf("%d\n", gcd(1, 5));
	printf("%d\n", gcd(10, 100));
	printf("%d\n", gcd(22, 131));
	printf("%d\n", gcd(12, 18));
	printf("%d\n", gcd(-4, 14));
	printf("%d\n", gcd(9, 28));
	printf("%d\n", gcd(42, 56));
	printf("%d\n", gcd(8, 12));
	printf("%d\n", gcd(48, 180));
	return 0;
}
