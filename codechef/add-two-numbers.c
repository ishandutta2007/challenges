// write a function that adds 2 numbers
#include <stdio.h>

int
add(int x, int y)
{
	return x + y;
}

int
main(void)
{
	printf("%d\n", add(1, 2));
	printf("%d\n", add(100, 200));
	printf("%d\n", add(10, 40));
	return 0;
}
