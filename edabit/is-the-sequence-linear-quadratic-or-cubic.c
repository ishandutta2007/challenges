/*

Create a function that determines if a given sequence is linear, quadratic or cubic.
The input will be an array of numbers of varying lengths.
The function should return "Linear", "Quadratic" or "Cubic".

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
classify(int *x, size_t n, int *t)
{
	static const char *tab[] = {"Linear", "Quadratic", "Cubic"};

	size_t i, j;

	if (n < 2)
		return "Unknown";
	if (n == 2)
		return "Linear";

	for (i = 0; i < nelem(tab) && n > 1; i++, n--) {
		for (j = 0; j < n - 1; j++) {
			if (i == 0)
				t[j] = x[j + 1] - x[j];
			else
				t[j] = t[j + 1] - t[j];
		}

		for (j = 0; j < n - 2; j++) {
			if (t[j] != t[j + 1])
				break;
		}
		if (j == n - 2)
			return tab[i];
	}

	return "Unknown";
}

int
main(void)
{
	int t[64];
	int x1[] = {1, 2, 3, 4, 5};
	int x2[] = {2, 1, 0, -1, -2};
	int x3[] = {3, 6, 10, 15, 21};
	int x4[] = {4, 9, 16, 25, 36};
	int x5[] = {7, 17, 31, 49, 71};
	int x6[] = {2, 10, 26, 50, 82};
	int x7[] = {-6, -4, 10, 42, 98, 184};
	int x8[] = {17, 59, 143, 287, 509, 827};
	int x9[] = {4, 14, 40, 88, 164};
	int x10[] = {1003, 424, 2443, 2, 231321};
	int x11[] = {1};
	int x12[] = {1, 25385935};
	int x13[] = {400, 441, 484};
	int x14[] = {387420489, 389017000, 390617891, 392223168};

	printf("%s\n", classify(x1, nelem(x1), t));
	printf("%s\n", classify(x2, nelem(x2), t));
	printf("%s\n", classify(x3, nelem(x3), t));
	printf("%s\n", classify(x4, nelem(x4), t));
	printf("%s\n", classify(x5, nelem(x5), t));
	printf("%s\n", classify(x6, nelem(x6), t));
	printf("%s\n", classify(x7, nelem(x7), t));
	printf("%s\n", classify(x8, nelem(x8), t));
	printf("%s\n", classify(x9, nelem(x9), t));
	printf("%s\n", classify(x10, nelem(x10), t));
	printf("%s\n", classify(x11, nelem(x11), t));
	printf("%s\n", classify(x12, nelem(x12), t));
	printf("%s\n", classify(x13, nelem(x13), t));
	printf("%s\n", classify(x14, nelem(x14), t));

	return 0;
}
