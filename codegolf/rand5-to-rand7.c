/*

You are provided with a function Rand5(). This function returns perfectly random (equal distribution) integers between 1 and 5.

Provide the function Rand7(), which uses Rand5() to produce perfectly random integers between 1 and 7.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned long long uvlong;

// https://stackoverflow.com/questions/10984974/why-do-people-say-there-is-modulo-bias-when-using-a-random-number-generator
unsigned
randn(unsigned n)
{
	unsigned r;

	if (n == 0)
		return 0;

	do {
		r = rand();
	} while (r >= (RAND_MAX - (RAND_MAX % n)));

	return (r % n) + 1;
}

unsigned
rand5(void)
{
	return randn(5);
}

unsigned
rand7(void)
{
	unsigned i, r;

	for (i = 0; i < 7; i++)
		r += rand5();
	return (r % 7) + 1;
}

void
test(uvlong n)
{
	uvlong a[10], b[10];
	uvlong i;

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (i = 0; i < n; i++) {
		a[rand5()]++;
		b[rand7()]++;
	}
	printf("%llu runs\n", n);
	printf("%12s %12s %12s\n", "n", "rand5", "rand7");
	for (i = 0; i < 10; i++)
		printf("%12llu\t%.12lf\t%.12lf\n", i, a[i] * 1.0 / n, b[i] * 1.0 / n);
	printf("\n");
}

int
main(void)
{
	srand(time(NULL));

	test(100000ull);
	test(1000000ull);
	test(10000000ull);

	return 0;
}
