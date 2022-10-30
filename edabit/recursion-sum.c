// Write a function that recursively finds the sum of the first n natural numbers.
#include <stdio.h>

int
sum(int n)
{
	if (n <= 0)
		return 0;
	return n + sum(n - 1);
}

int
main(void)
{
	static const int tab[] = {
	    5,
	    1,
	    12,
	    7,
	    10,
	    15,
	    20,
	    100,
	    0,
	    -1,
	};
	size_t i;

	for (i = 0; tab[i] >= 0; i++)
		printf("%d\n", sum(tab[i]));
	return 0;
}
