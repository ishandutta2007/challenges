/*

Given a strictly positive integer n, follow these steps:

Create an array A with n 1s.
If A only has one element, terminate. Otherwise, starting from the first element, replace each pair of A with its sum, leaving the last element as is if A's length is odd, and repeat this step.
The output should contain A's state after each step in order from the first step to the last. Usage of standard loopholes is forbidden. This is a code-golf challenge, so the solution with the fewest bytes in each language wins.

Test cases
Each line in the output of these examples is a state. You can output via any reasonable format.

Input: 1

[1]

Input: 4

[1, 1, 1, 1]
[2, 2]
[4]

Input: 13

[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
[2, 2, 2, 2, 2, 2, 1]
[4, 4, 4, 1]
[8, 5]
[13]

Input: 15

[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
[2, 2, 2, 2, 2, 2, 2, 1]
[4, 4, 4, 3]
[8, 7]
[15]

*/

#include <stdio.h>

void
print(int *a, size_t n)
{
	size_t i;

	printf("[");
	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i + 1 < n)
			printf(", ");
	}
	printf("]\n");
}

void
pairsum(int *a, size_t n, size_t m)
{
	size_t i, j;

	for (i = j = 0; i < n; i++) {
		if (j + 1 >= m)
			a[i] = a[j];
		else
			a[i] = a[j] + a[j + 1];
		j += 2;
	}
}

void
gen(int *a, size_t n)
{
	size_t i, m;

	if (n == 0)
		return;

	for (i = 0; i < n; i++)
		a[i] = 1;

	m = n;
	for (;;) {
		print(a, n);

		if (n <= 1)
			break;

		m = n;
		n = (n >> 1) + (n & 1);
		pairsum(a, n, m);
	}
	printf("\n");
}

void
test(size_t n)
{
	int a[128];

	gen(a, n);
}

int
main(void)
{
	test(1);
	test(4);
	test(13);
	test(15);

	return 0;
}
