/*

Create a function that produces a random number that contains all numbers from one to five, without any duplicates.
Examples

12345

21345

51234

Notes

N/A

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swapu(unsigned *x, unsigned *y)
{
	unsigned t;

	t = *y;
	*y = *x;
	*x = t;
}

// https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
void
shuffle(unsigned *a, size_t n)
{
	size_t i, j;

	if (n < 2)
		return;

	if (n < 3) {
		swapu(&a[0], &a[1]);
		return;
	}

	for (i = 0; i < n - 2; i++) {
		j = i + (rand() % (n - i));
		swapu(&a[i], &a[j]);
	}
}

unsigned
digits(unsigned *a, size_t n)
{
	size_t i;
	unsigned r;

	r = 0;
	for (i = 0; i < n; i++)
		r = (r * 10) + a[i];
	return r;
}

unsigned
numbers(void)
{
	unsigned a[] = {1, 2, 3, 4, 5};

	shuffle(a, nelem(a));
	return digits(a, nelem(a));
}

int
main(void)
{
	unsigned i;

	srand(time(NULL));
	for (i = 0; i < 120; i++)
		printf("%u\n", numbers());

	return 0;
}
