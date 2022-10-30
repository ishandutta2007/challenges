#include <stdio.h>
#include <stdbool.h>

bool
lez(double n)
{
	return n <= 0;
}

int
main(void)
{
	printf("%d\n", lez(5));
	printf("%d\n", lez(0));
	printf("%d\n", lez(-5));
	printf("%d\n", lez(1));
	printf("%d\n", lez(2));
	printf("%d\n", lez(1000));
	printf("%d\n", lez(0.5));
	return 0;
}
