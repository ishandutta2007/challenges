/*

Once a water balloon pops, is soaks the area around it. The ground gets drier the further away you travel from the balloon.

The effect of a water balloon popping can be modeled using an array. Create a function that takes an array which takes the pre-pop state and returns the state after the balloon is popped.
The pre-pop state will contain at most a single balloon, whose size is represented by the only non-zero element.

Notes

    Length of input array is always odd.
    The input array will always be the exact length it takes for there to be exactly one border zero.
    If the input array consists only of zeroes, return the same array.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
pop(unsigned *x, unsigned *y, size_t n)
{
	size_t i, c;
	unsigned j;

	if ((n & 1) == 0)
		return -1;

	memset(y, 0, sizeof(*y) * n);
	for (i = c = 0; i < n; i++) {
		c += !!x[i];
		for (j = 0; j < x[i]; j++) {
			if (j <= i)
				y[i - j] = x[i] - j;
			if (n - j > i)
				y[i + j] = x[i] - j;
		}
	}

	return (c < 2) ? 0 : -1;
}

void
print(unsigned *a, size_t n)
{
	size_t i;

	printf("[");
	for (i = 0; i < n; i++) {
		printf("%u", a[i]);
		if (i + 1 < n)
			printf(", ");
	}
	printf("]");
}

void
test(unsigned *x, unsigned *y, size_t n)
{
	pop(x, y, n);
	print(x, n);
	printf(" -> ");
	print(y, n);
	printf("\n");
}

int
main(void)
{
	unsigned y[80];
	unsigned x1[] = {0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0};
	unsigned x2[] = {0, 0, 0, 0, 4, 0, 0, 0, 0};
	unsigned x3[] = {0, 0, 0, 3, 0, 0, 0};
	unsigned x4[] = {0, 0, 2, 0, 0};
	unsigned x5[] = {0, 1, 0};
	unsigned x6[] = {0};

	test(x1, y, nelem(x1));
	test(x2, y, nelem(x2));
	test(x3, y, nelem(x3));
	test(x4, y, nelem(x4));
	test(x5, y, nelem(x5));
	test(x6, y, nelem(x6));

	return 0;
}
