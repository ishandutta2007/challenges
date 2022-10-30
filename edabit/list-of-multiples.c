/*

Create a function that takes two numbers as arguments (num, length) and returns a list of multiples of num up to length.

Notes

Notice that num is also included in the returned list.

*/

#include <stdio.h>
#include <stdlib.h>

int *
listofmultiples(int x, size_t n)
{
	size_t i;
	int *p, v;

	p = calloc(n, sizeof(*p));
	if (!p)
		return NULL;

	v = x;
	for (i = 0; i < n; i++) {
		p[i] = x;
		x += v;
	}

	return p;
}

void
test(int x, size_t n)
{
	size_t i;
	int *p;

	p = listofmultiples(x, n);
	if (!p)
		return;

	printf("[");
	for (i = 0; i < n; i++) {
		printf("%d", p[i]);
		if (i + 1 < n)
			printf(", ");
	}
	printf("]\n");

	free(p);
}

int
main(void)
{
	test(7, 5);
	test(12, 10);
	test(17, 7);
	test(630, 14);
	test(140, 3);
	test(7, 8);
	test(11, 21);
	test(17, 6);
	return 0;
}
