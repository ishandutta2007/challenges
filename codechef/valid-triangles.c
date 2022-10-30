#include <stdio.h>

const char *
valid(int a, int b, int c)
{
	return (a + b + c == 180) ? "YES" : "NO";
}

int
main(void)
{
	printf("%s\n", valid(40, 40, 100));
	printf("%s\n", valid(45, 45, 90));
	printf("%s\n", valid(180, 1, 1));
	return 0;
}
