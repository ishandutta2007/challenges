// Given an integer, write a function to determine if it is a power of two.

#include <stdio.h>

int
ispow2(int x)
{
	return x > 0 && (x & (x - 1)) == 0;
}

int
main(void)
{
	int i;

	printf("%d\n", ispow2(1));
	printf("%d\n", ispow2(16));
	printf("%d\n", ispow2(218));
	printf("\n");
	for (i = 0; i <= 1 << 27; i++) {
		if (ispow2(i))
			printf("%x\n", i);
	}
	return 0;
}
