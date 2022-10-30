/*

Create a function that takes a number and returns an array with the digits of the number in reverse order.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

unsigned *
revarr(unsigned long x, size_t *l)
{
	char b[sizeof(x) * CHAR_BIT];
	unsigned *p;
	int i, n;

	*l = 0;
	n = snprintf(b, sizeof(b), "%lu", x);
	p = calloc(n, sizeof(*p));
	if (!p)
		return NULL;

	*l = n;
	for (i = n - 1; i >= 0; i--)
		p[n - i - 1] = b[i] - '0';

	return p;
}

void
print(unsigned *p, size_t n)
{
	size_t i;

	printf("[");
	for (i = 0; i < n; i++) {
		printf("%u", p[i]);
		if (i + 1 < n)
			printf(", ");
	}
	printf("]\n");
}

void
test(unsigned long x)
{
	unsigned *p;
	size_t l;

	p = revarr(x, &l);
	if (p) {
		print(p, l);
		free(p);
	}
}

int
main(void)
{
	test(1485979ul);
	test(623478ul);
	test(12345ul);
	test(202069ul);
	test(0ul);

	return 0;
}
