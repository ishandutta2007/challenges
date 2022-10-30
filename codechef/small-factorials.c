// write a program to calculate small factorials
#include <stdio.h>

int
fact(int n)
{
	int i, s;

	if (n <= 1)
		return 1;

	s = 1;
	for (i = 2; i <= n; i++)
		s *= i;
	return s;
}

int
main(void)
{
	printf("%d\n", fact(1));
	printf("%d\n", fact(2));
	printf("%d\n", fact(5));
	printf("%d\n", fact(3));
	return 0;
}
