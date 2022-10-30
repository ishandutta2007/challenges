/*

Vishal loves running. He often visits his favourite Nehru Park and runs for very long distances.
On one such visit he found that the number of girls in the park was unusually high. Now he wants to use this as an opportunity to impress a large number of girls with his awesome speed.

The track on which he runs is an N kilometres long straight path. There are ai girls standing within the ith kilometre of this path.
A girl will be impressed only if Vishal is running at his maximum speed when he passes by her.
But he can run at his best speed only for a single continuous stretch of K kilometres. Now Vishal wants to know what is the maximum number of girls that he can impress.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

unsigned
run(unsigned *a, size_t n, size_t k)
{
	unsigned m, r;
	size_t i;

	m = r = 0;
	for (i = 0; i < n; i++) {
		if (i >= k)
			r -= a[i - k];
		r += a[i];
		m = max(m, r);
	}
	return m;
}

int
main(void)
{
	unsigned a[] = {2, 4, 8, 1, 2, 1, 8};
	printf("%u\n", run(a, nelem(a), 2));
	printf("%u\n", run(a, nelem(a), 4));
	printf("%u\n", run(a, nelem(a), 1));

	unsigned b[] = {134};
	printf("%u\n", run(b, nelem(b), 0));
	printf("%u\n", run(b, nelem(b), 20));

	return 0;
}
